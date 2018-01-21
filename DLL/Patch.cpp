#include "stdafx.h"
#include "UHC.h"

extern "C" BOOL __stdcall TableIDExists(DWORD dwTable, int id) {
	__asm push ecx
	BOOL result = FALSE;

	if (dwTable >= TABLE_COUNT) {
		goto DONE;
	}

	UHCRefTable& table = pUHCInfo->Tables[dwTable];
	for (DWORD i = 0; i < table.RefCount; i++) {
		if (table.RefIDs[i] == id) {
			result = TRUE;
			goto DONE;
		}
	}

DONE:
	__asm pop ecx
	return result;
}

extern "C" void __stdcall RegisterSyscallGroup(UHCSyscallGroupName name, LPVOID _this) {
	auto SyscallRegister = reinterpret_cast<BOOL(__thiscall *)(LPVOID _this, LPCSTR name, LPCVOID fPtr, DWORD retType)>(0x624f52);
	auto SyscallPrintf = reinterpret_cast<int(*)(LPVOID _this, LPCSTR format, ...)>(0xa44b95);
	auto SyscallFree = reinterpret_cast<int(__thiscall *)(LPVOID _this)>(0xa44c0b);
	auto SyscallGetName = reinterpret_cast<LPCSTR(__thiscall *)(LPVOID _this)> (0xa44bee);
	auto SyscallSetParamInteger = reinterpret_cast<BOOL(__thiscall *)(LPVOID _this, int defaultVal)>(0x62505b);
	auto SyscallSetParamFloat = reinterpret_cast<BOOL(__thiscall *)(LPVOID _this, float defaultVal)>(0x625079);
	auto SyscallSetParamBool = reinterpret_cast<BOOL(__thiscall *)(LPVOID _this, BOOL defaultVal)>(0x62506a);
	auto SyscallSetParamString = reinterpret_cast<BOOL(__thiscall *)(LPVOID _this, LPCSTR defaultVal)>(0x624e3f);
	auto SyscallSetParamVector = reinterpret_cast<BOOL(__thiscall *)(LPVOID _this, const float* defaultVal)>(0x62734a);
	auto SyscallComment = reinterpret_cast<BOOL(__thiscall *)(LPVOID _this, LPCSTR comment)>(0x624e56);
	auto SyscallRegisterEnd = reinterpret_cast<BOOL(__thiscall *)(LPVOID _this)>(0x6250b0);

	TArray<UHCSyscall>& group = pUHCInfo->SyscallGroups[name];
	for (size_t i = 0; i < group.GetNumElements(); i++) {
		UHCSyscall& syscall = group[i];
		if (!SyscallRegister(_this, syscall.Name, syscall.Ptr, syscall.RetType)) {
			SyscallPrintf(_this, (LPCSTR)0xbf1e98, syscall.Name);
			SyscallFree(_this);
			return;
		}

		// to-do: rule related functions

		for (DWORD i = 0; i < syscall.ParamCount; i++) {
			switch (syscall.Params[i].Type)
			{
			case SyscallInteger:
				if (!SyscallSetParamInteger(_this, *(const int*)syscall.Params[i].Default)) {
					SyscallPrintf(_this, (LPCSTR)0xbf1e50, syscall.Params[i].Default, SyscallGetName(_this));
					SyscallFree(_this);
					return;
				}
				break;
			case SyscallFloat:
				if (!SyscallSetParamFloat(_this, *(const float*)syscall.Params[i].Default)) {
					SyscallPrintf(_this, (LPCSTR)0xbf1e08, syscall.Params[i].Default, SyscallGetName(_this));
					SyscallFree(_this);
					return;
				}
				break;
			case SyscallBool:
				if (!SyscallSetParamBool(_this, *(const BOOL*)syscall.Params[i].Default)) {
					SyscallPrintf(_this, (LPCSTR)0xbf1dc0, syscall.Params[i].Default, SyscallGetName(_this));
					SyscallFree(_this);
					return;
				}
				break;
			case SyscallString:
				if (!SyscallSetParamString(_this, (LPCSTR)syscall.Params[i].Default)) {
					SyscallPrintf(_this, (LPCSTR)0xbf1d78, syscall.Params[i].Default, SyscallGetName(_this));
					SyscallFree(_this);
					return;
				}
				break;
			case SyscallVector:
				const float* vec = (const float*)syscall.Params[i].Default;
				if (!SyscallSetParamVector(_this, vec)) {
					SyscallPrintf(_this, (LPCSTR)0xbffa48, vec[0], vec[1], vec[2], SyscallGetName(_this));
					SyscallFree(_this);
					return;
				}
			}
		}

		if (!SyscallComment(_this, syscall.Comment)) {
			SyscallFree(_this);
			return;
		}

		SyscallRegisterEnd(_this);

#ifdef _DEBUG
		char debugMsg[256];
		wsprintfA(debugMsg, "Loaded UHC syscall '%s'.\n", syscall.Name);
		OutputDebugStringA(debugMsg);
#endif

	}
}

extern "C" void __stdcall LoadPersonalities() {
	WCHAR szFindPath[MAX_PATH];
	LPCWSTR lpAI = (LPCWSTR)0x0be3a98;
	LPCWSTR lpPersonalityExt = (LPCWSTR)0x0c0b39c;
	WIN32_FIND_DATAW fd;
	HANDLE hFind;

	lstrcpyW(szFindPath, lpAI);
	lstrcatW(szFindPath, L"*");
	lstrcatW(szFindPath, lpPersonalityExt);

	hFind = FindFirstFileW(szFindPath, &fd);

	if (hFind != INVALID_HANDLE_VALUE) {
		TArray<LPWSTR>& personalities = pUHCInfo->Personalities;

		do
		{
			size_t length = wcschr(fd.cFileName, L'.') - fd.cFileName + 1;

			personalities.PushBack(new WCHAR[length]);
			lstrcpynW(personalities.Back(), fd.cFileName, length);

		} while (FindNextFileW(hFind, &fd));

		FindClose(hFind);
	}
}

extern "C" BOOL __stdcall CheckRevBanner(LPCSTR lpRevTech, LPVOID lpThis, LPVOID lpPathObject) {
	if (strncmp(lpRevTech, "XPRevolution", 12) != 0)
		return FALSE;

	const WCHAR szBannerPrefix[] = L"ui\\ingame\\politicians\\REV_banner_";
	WCHAR szPath[MAX_PATH];
	LPCSTR lpLeaderName = lpRevTech + 12;

	lstrcpyW(szPath, szBannerPrefix);
	mbstowcs(szPath + ((sizeof(szBannerPrefix) - 1)/sizeof(WCHAR)), lpLeaderName, lstrlenA(lpLeaderName) + 1);

	reinterpret_cast<void(__thiscall *)(LPVOID, LPCWSTR)>(0x401a12)(lpPathObject, szPath);
	reinterpret_cast<void(__thiscall *)(LPVOID, LPVOID)>(0x638823)(lpThis, lpPathObject);

	return TRUE;
}