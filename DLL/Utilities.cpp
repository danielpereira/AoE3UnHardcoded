#include "stdafx.h"
#include "Disasm.h"

// Patches a 32 bit address
extern "C" void __stdcall PatchAddress(HANDLE hProcess, DWORD lpBaseAddress, DWORD lpDestAddress, BOOL bRelAddr) {
	DWORD flProtect, flOldProtect = PAGE_EXECUTE_READWRITE, dwBytesWritten;
	DWORD* lpAddress;
	const DWORD dwAddressSize = 4;

	lpAddress = (DWORD*)lpBaseAddress;

	VirtualProtectEx(hProcess, lpAddress, dwAddressSize, PAGE_EXECUTE_READWRITE, &flOldProtect);

	*lpAddress = lpDestAddress;
	if (bRelAddr)
		*lpAddress -= lpBaseAddress + dwAddressSize;

	WriteProcessMemory(hProcess, lpAddress, lpAddress, dwAddressSize, &dwBytesWritten);
	VirtualProtectEx(hProcess, lpAddress, dwAddressSize, flOldProtect, &flProtect);
}

#define SRC_SIZE 16
#define JMP_REL32_SIZE 5

extern "C" void __stdcall PatchCodeCave(HANDLE hProcess, DWORD dwAddress, DWORD dwAddressEnd, 
	DWORD dwCCAddress, DWORD dwCCAddressEnd)
{
	DWORD dwSize = 0, flProtect, flOldProtect = PAGE_EXECUTE_READWRITE, dwBytes;
	BYTE lpBuffer[SRC_SIZE];

	if (dwAddress == dwAddressEnd) {
		BYTE lpInsBuffer[16], lpRestoreBuffer[32];
		PBYTE lpRestoration, lpIns, lpRestore;
		DWORD dwAddressDest, dwInsSize, dwAddressCount = 0, dwRestoreSize;
		PDWORD lpAddresses[4];

		// Allocate space for restored code and a jump from the address to base address
		VirtualProtectEx(hProcess, (LPVOID)dwAddress, SRC_SIZE, PAGE_EXECUTE_READWRITE, &flOldProtect);
		ReadProcessMemory(hProcess, (LPVOID)dwAddress, lpBuffer, SRC_SIZE, &dwBytes);

		lpRestore = lpRestoreBuffer;

		// determine instruction backup size
		do
		{
			lpIns = lpInsBuffer;
			switch (lpBuffer[dwSize]) {
				// jcc rel8
				// no near jump for jcxz(0xe3)
			case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77:
			case 0x78: case 0x79: case 0x7a: case 0x7b: case 0x7c: case 0x7d: case 0x7e: case 0x7f:
				dwAddressDest = (dwAddress + dwSize) + 2 + (CHAR)lpBuffer[dwSize + 1];
				*lpIns++ = 0x0f;
				*lpIns++ = lpBuffer[dwSize] + 0x10;
				dwInsSize = 6;
				dwSize += 2;
				break;
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
					*lpIns++ = 0x0f;
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
				dwInsSize = InstructionLength(lpBuffer + dwSize);
				CopyMemory(lpRestore, lpBuffer + dwSize, dwInsSize);
				dwSize += dwInsSize;
			}

			if (lpIns != lpInsBuffer) {
				*(PDWORD)lpIns = dwAddressDest - ((lpRestore - lpRestoreBuffer) + dwInsSize);
				CopyMemory(lpRestore, lpInsBuffer, dwInsSize);
				lpAddresses[dwAddressCount++] = (PDWORD)(lpRestore + (lpIns - lpInsBuffer));
			}

			lpRestore += dwInsSize;
		} while (dwSize < JMP_REL32_SIZE);

		dwRestoreSize = lpRestore - lpRestoreBuffer + JMP_REL32_SIZE;
		lpRestoration = (PBYTE)VirtualAllocEx(hProcess, NULL, dwRestoreSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		
		// update relative addresses
		for (DWORD i = 0; i < dwAddressCount; i++)
			*lpAddresses[i] -= (DWORD)lpRestoration;

		// Patch jump from restored code address to base address
		lpRestore[0] = 0xe9; // JMP rel32
		*(PDWORD)(lpRestore + 1) = (dwAddress + dwSize) - ((DWORD)lpRestoration + (lpRestore - lpRestoreBuffer) + JMP_REL32_SIZE);
		WriteProcessMemory(hProcess, lpRestoration, lpRestoreBuffer, dwRestoreSize, &dwBytes);
		VirtualProtectEx(hProcess, lpRestoration, dwRestoreSize, PAGE_EXECUTE_READ, &flProtect);

		// Patch jump from end of code cave to restored code address
		VirtualProtectEx(hProcess, (LPVOID)dwCCAddressEnd, JMP_REL32_SIZE, PAGE_EXECUTE_READWRITE, &flOldProtect);
		lpBuffer[0] = 0xe9;
		*(PDWORD)(lpBuffer + 1) = (DWORD)lpRestoration - (dwCCAddressEnd + JMP_REL32_SIZE);
		WriteProcessMemory(hProcess, (LPVOID)dwCCAddressEnd, lpBuffer, JMP_REL32_SIZE, &dwBytes);
		VirtualProtectEx(hProcess, (LPVOID)dwCCAddressEnd, JMP_REL32_SIZE, flOldProtect, &flProtect);
	}
	else {
		// Patch jump from end of code cave to end to base address
		VirtualProtectEx(hProcess, (LPVOID)dwCCAddressEnd, JMP_REL32_SIZE, flOldProtect, &flProtect);
		lpBuffer[0] = 0xe9;
		*(PDWORD)(lpBuffer + 1) = dwAddressEnd - (dwCCAddressEnd + JMP_REL32_SIZE);
		WriteProcessMemory(hProcess, (LPVOID)dwCCAddressEnd, lpBuffer, JMP_REL32_SIZE, &dwBytes);
		VirtualProtectEx(hProcess, (LPVOID)dwCCAddressEnd, JMP_REL32_SIZE, flOldProtect, &flProtect);
	}

	// Patch jump from base address to code cave
	*(PDWORD)(lpBuffer + 1) = dwCCAddress - (dwAddress + JMP_REL32_SIZE);
	WriteProcessMemory(hProcess, (LPVOID)dwAddress, lpBuffer, JMP_REL32_SIZE, &dwBytes);
	VirtualProtectEx(hProcess, (LPVOID)dwAddress, SRC_SIZE, flOldProtect, &flProtect);
}

extern "C" void __stdcall PatchData(HANDLE hProcess, DWORD dwAddress, LPVOID lpBuffer, DWORD dwSize)
{
	DWORD flProtect, flOldProtect, dwBytesWritten;
	VirtualProtectEx(hProcess, (LPVOID)dwAddress, dwSize, PAGE_EXECUTE_READWRITE, &flOldProtect);
	WriteProcessMemory(hProcess, (LPVOID)dwAddress, lpBuffer, dwSize, &dwBytesWritten);
	VirtualProtectEx(hProcess, (LPVOID)dwAddress, dwSize, flOldProtect, &flProtect);
}