#include "stdafx.h"
#include "UHC.h"

extern "C" BOOL __stdcall PatchAddress(HANDLE hProcess, UINT_PTR lpBaseAddress, UINT_PTR lpDestAddress, BOOL bRelAddr) {
	DWORD flProtect, flOldProtect = PAGE_EXECUTE_READWRITE;
	SIZE_T dwBytesWritten;
	UINT_PTR* lpAddress;
	BOOL result;

	lpAddress = (UINT_PTR*)lpBaseAddress;

	result = VirtualProtectEx(hProcess, lpAddress, sizeof(UINT_PTR), PAGE_EXECUTE_READWRITE, &flOldProtect);
	if (!result)
		goto DONE;

	*lpAddress = lpDestAddress;
	if (bRelAddr)
		*lpAddress -= lpBaseAddress + sizeof(UINT_PTR);

	result = WriteProcessMemory(hProcess, lpAddress, lpAddress, sizeof(UINT_PTR), &dwBytesWritten);
	if (!result)
		goto DONE;

	result = VirtualProtectEx(hProcess, lpAddress, sizeof(UINT_PTR), flOldProtect, &flProtect);
DONE:
	return result;
}

extern "C" BOOL __stdcall PatchData(HANDLE hProcess, UINT_PTR dwAddress, LPVOID lpBuffer, SIZE_T dwSize)
{
	DWORD flProtect, flOldProtect;
	SIZE_T dwBytesWritten;
	BOOL result;

	result = VirtualProtectEx(hProcess, (LPVOID)dwAddress, dwSize, PAGE_EXECUTE_READWRITE, &flOldProtect);
	if (!result)
		goto DONE;

	result = WriteProcessMemory(hProcess, (LPVOID)dwAddress, lpBuffer, dwSize, &dwBytesWritten);
	if (!result)
		goto DONE;

	result = VirtualProtectEx(hProcess, (LPVOID)dwAddress, dwSize, flOldProtect, &flProtect);
DONE:
	return result;
}

#define JMP_REL32_SIZE 5

extern "C" BOOL __stdcall PatchCodeCave(HANDLE hProcess, UINT_PTR dwAddress, UINT_PTR dwAddressEnd, UINT_PTR dwCCAddress, UINT_PTR dwCCAddressEnd)
{
	// minimum instructions' size larger than 32 bit relative jump
	UINT_PTR dwSize = dwAddressEnd - dwAddress;

	DWORD flProtect, flOldProtect = PAGE_EXECUTE_READWRITE;
	SIZE_T dwBytes;
	BYTE lpBuffer[32];
	BOOL result;

	if (dwSize < JMP_REL32_SIZE) {
		BYTE lpInsBuffer[16], lpRestoreBuffer[32];
		PBYTE lpRestoration, lpIns, lpRestore;
		SIZE_T dwAddressDest, dwInsSize, dwRestoreSize;

		// Restored relative instructions' jump addresses
		SIZE_T dwAddressCount = 0;
		PUINT_PTR lpAddresses[4];

		// Allocate space for restored code and a jump from the address to base address
		result = VirtualProtectEx(hProcess, (LPVOID)dwAddress, sizeof(lpBuffer), PAGE_EXECUTE_READWRITE, &flOldProtect);
		if (!result)
			goto DONE;

		result = ReadProcessMemory(hProcess, (LPVOID)dwAddress, lpBuffer, sizeof(lpBuffer), &dwBytes);
		if (!result)
			goto DONE;

		lpRestore = lpRestoreBuffer;

		// determine restored instructions' size
		do
		{
			lpIns = lpInsBuffer;
			switch (lpBuffer[dwSize]) {
				// jcc rel8
			case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77:
			case 0x78: case 0x79: case 0x7a: case 0x7b: case 0x7c: case 0x7d: case 0x7e: case 0x7f:
				dwAddressDest = (dwAddress + dwSize) + 2 + (CHAR)lpBuffer[dwSize + 1];
				*lpIns++ = 0x0f; // JCC prefix
				*lpIns++ = lpBuffer[dwSize] + 0x10;
				dwInsSize = 6;
				dwSize += 2;
				break;
				// no near jump for jcxz(0xe3)
			case 0xe3:
				result = FALSE;
				goto DONE;
				// jmp rel8
			case 0xeb:
				dwAddressDest = (dwAddress + dwSize) + 2 + (CHAR)lpBuffer[dwSize + 1];
				*lpIns++ = 0xe9;
				dwInsSize = 5;
				dwSize += 2;
				break;
				// jcc rel32
			case 0x0f:
				switch (lpBuffer[dwSize + 1])
				{
				case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87:
				case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f:
					dwAddressDest = (dwAddress + dwSize) + 6 + *(PDWORD)(lpBuffer + 2);
					*lpIns++ = 0x0f; // JCC prefix
					*lpIns++ = lpBuffer[dwSize + 1];
					dwInsSize = 6;
					dwSize += 6;
					break;
				default:
					goto LABEL_NOT_REL;
				}
				break;
				// call rel32
			case 0xe8:
				// jmp rel32
			case 0xe9:
				dwAddressDest = (dwAddress + dwSize) + 5 + *(PDWORD)(lpBuffer + 1);
				*lpIns++ = lpBuffer[dwSize];
				dwInsSize = 5;
				dwSize += 5;
				break;
			default:
			LABEL_NOT_REL:
				ZydisDecodedInstruction ins;
				result = ZYDIS_SUCCESS(ZydisDecoderDecodeBuffer(&pUHCInfo->Decoder, lpBuffer + dwSize, sizeof(lpBuffer) - dwSize, dwAddress + dwSize, &ins));
				if (!result)
					goto DONE;

				dwInsSize = ins.length;
				CopyMemory(lpRestore, lpBuffer + dwSize, dwInsSize);
				dwSize += dwInsSize;
			}

			if (lpIns != lpInsBuffer) {
				*(PDWORD)lpIns = dwAddressDest - ((lpRestore - lpRestoreBuffer) + dwInsSize);
				CopyMemory(lpRestore, lpInsBuffer, dwInsSize);
				lpAddresses[dwAddressCount++] = (PUINT_PTR)(lpRestore + (lpIns - lpInsBuffer));
			}

			lpRestore += dwInsSize;
		} while (dwSize < JMP_REL32_SIZE);

		dwRestoreSize = lpRestore - lpRestoreBuffer + JMP_REL32_SIZE;
		lpRestoration = (PBYTE)VirtualAllocEx(hProcess, NULL, dwRestoreSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		if (!lpRestoration) {
			result = FALSE;
			goto DONE;
		}
		
		// update relative addresses
		for (SIZE_T i = 0; i < dwAddressCount; i++)
			*lpAddresses[i] -= (UINT_PTR)lpRestoration;

		// Patch jump from restored code address to base address
		lpRestore[0] = 0xe9; // JMP rel32
		*(PUINT_PTR)(lpRestore + 1) = (dwAddress + dwSize) - ((UINT_PTR)lpRestoration + (lpRestore - lpRestoreBuffer) + JMP_REL32_SIZE);
		result = WriteProcessMemory(hProcess, lpRestoration, lpRestoreBuffer, dwRestoreSize, &dwBytes);
		if (!result)
			goto DONE;

		result = VirtualProtectEx(hProcess, lpRestoration, dwRestoreSize, PAGE_EXECUTE_READ, &flProtect);
		if (!result)
			goto DONE;

		// Patch jump from end of code cave to restored code address
		result = VirtualProtectEx(hProcess, (LPVOID)dwCCAddressEnd, JMP_REL32_SIZE, PAGE_EXECUTE_READWRITE, &flOldProtect);
		if (!result)
			goto DONE;

		lpBuffer[0] = 0xe9;
		*(PUINT_PTR)(lpBuffer + 1) = (UINT_PTR)lpRestoration - (dwCCAddressEnd + JMP_REL32_SIZE);

		result = WriteProcessMemory(hProcess, (LPVOID)dwCCAddressEnd, lpBuffer, JMP_REL32_SIZE, &dwBytes);
		if (!result)
			goto DONE;

		result = VirtualProtectEx(hProcess, (LPVOID)dwCCAddressEnd, JMP_REL32_SIZE, flOldProtect, &flProtect);
		if (!result)
			goto DONE;
	}
	else {
		// Patch jump from end of code cave to end to base address
		result = VirtualProtectEx(hProcess, (LPVOID)dwCCAddressEnd, JMP_REL32_SIZE, flOldProtect, &flProtect);
		if (!result)
			goto DONE;

		lpBuffer[0] = 0xe9;
		*(PUINT_PTR)(lpBuffer + 1) = dwAddressEnd - (dwCCAddressEnd + JMP_REL32_SIZE);
		result = WriteProcessMemory(hProcess, (LPVOID)dwCCAddressEnd, lpBuffer, JMP_REL32_SIZE, &dwBytes);
		if (!result)
			goto DONE;

		result = VirtualProtectEx(hProcess, (LPVOID)dwCCAddressEnd, JMP_REL32_SIZE, flOldProtect, &flProtect);
		if (!result)
			goto DONE;
	}

	// Patch jump from base address to code cave
	*(PUINT_PTR)(lpBuffer + 1) = dwCCAddress - (dwAddress + JMP_REL32_SIZE);
	result = WriteProcessMemory(hProcess, (LPVOID)dwAddress, lpBuffer, JMP_REL32_SIZE, &dwBytes);
	if (!result)
		goto DONE;

	result = VirtualProtectEx(hProcess, (LPVOID)dwAddress, sizeof(lpBuffer), flOldProtect, &flProtect);

DONE:
	return result;
}

#define FAKE_INSTRUCTION_IDENTIFIER 0xF1

#pragma pack(push, 1)

struct FakeInstruction
{
	BYTE identifier;
	BYTE opcode;
	UINT_PTR address;

	enum
	{
		CALL32,
        JMP32,
		JE32,
		JNE32,
		CASE,
		CodeCaveBegin,
		CodeCaveEnd,
	};
};

#pragma pack(pop)

// Patch fake instructions in a given range
extern "C" BOOL __stdcall PatchFakeInstructions(HANDLE hProcess, UINT_PTR lpAddress, UINT_PTR lpAddressEnd)
{
	ZydisDecodedInstruction instruction;
	UINT_PTR position = lpAddress;
	BYTE lpBuffer[32];
	SIZE_T bytesRead;
	UINT_PTR uBeginAddress = 0;
	UINT_PTR uCCBeginAddress = 0;
	BOOL result;

	while (position < lpAddressEnd) {
		result = ReadProcessMemory(hProcess, (LPCVOID)position, lpBuffer, sizeof(lpBuffer), &bytesRead);
		if (!result)
			goto DONE;

		auto fakeIns = (FakeInstruction*)lpBuffer;
		if (fakeIns->identifier == FAKE_INSTRUCTION_IDENTIFIER) {
			UINT16 data = 0;
			switch (fakeIns->opcode)
			{
			case FakeInstruction::CALL32:
				data = 0xe890; // nop, call near
				break;
			case FakeInstruction::JMP32:
				data = 0xe990; // nop, jmp near
				break;
			case FakeInstruction::JE32:
				data = 0x840f;
				break;
			case FakeInstruction::JNE32:
				data = 0x850f;
				break;
			case FakeInstruction::CASE:
				// jump table offset
				result = PatchAddress(hProcess, fakeIns->address, position + sizeof(FakeInstruction), FALSE);
				if (!result)
					goto DONE;
				break;
			case FakeInstruction::CodeCaveBegin:
				uBeginAddress = fakeIns->address;
				uCCBeginAddress = position + sizeof(FakeInstruction);
				break;
			case FakeInstruction::CodeCaveEnd:
			{
				PUINT_PTR lpCCEnd = &fakeIns->address;
				if (uBeginAddress == 0 || uCCBeginAddress == 0) {
					result = FALSE;
					goto DONE;
				}
				result = PatchCodeCave(hProcess, uBeginAddress, fakeIns->address, uCCBeginAddress, position - JMP_REL32_SIZE);
				if (!result)
					goto DONE;
				uBeginAddress = 0;
				uCCBeginAddress = 0;
			}
			break;
			default:
				result = FALSE;
				goto DONE;
			}

			if (data) {
				result = PatchData(hProcess, position, &data, sizeof(UINT16));
				if (!result)
					goto DONE;
				result = PatchAddress(hProcess, position + offsetof(FakeInstruction, address), fakeIns->address, TRUE);
				if (!result)
					goto DONE;
			}

			position += sizeof(FakeInstruction);
		}
		else {
			result = ZYDIS_SUCCESS(ZydisDecoderDecodeBuffer(&pUHCInfo->Decoder, lpBuffer, sizeof(lpBuffer), position, &instruction));
			if (!result)
				goto DONE;
			position += instruction.length;
		}
	}

	if (position > lpAddressEnd)
		result = FALSE;

DONE:
	return result;
}