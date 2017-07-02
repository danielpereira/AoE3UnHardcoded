#include "stdafx.h"
#include "UHC.h"

#define TEST

#ifdef TEST
#include "Test.h"
#endif

// override operator new and delete
/*void* operator new(size_t size) {
	auto _operator_new = reinterpret_cast<void* (__thiscall *)(int, size_t*)>(0x401234);
	return _operator_new(0xc66010, &size);
}

void operator delete(void* mem) {
	auto _operator_delete = reinterpret_cast<void(__thiscall *)(int, void*)>(0x4014c3);
	return _operator_delete(0xc66010, mem);
}*/

void FixWorkingPath() {
	WCHAR lpWorkingPath[MAX_PATH];

	GetModuleFileNameW(NULL, lpWorkingPath, MAX_PATH);

	for (int i = lstrlenW(lpWorkingPath) - 1; i >= 0; i--) {
		if (lpWorkingPath[i] == '\\') {
			lpWorkingPath[i + 1] = '\0';

			SetCurrentDirectoryW(lpWorkingPath);
			break;
		}
	}

}

void EncryptString(LPWSTR dest, LPCWSTR src) {
	LPCWSTR lpPtr = src;
	LPWSTR lpEncryptedPtr = dest;

	const LPCWSTR lpEncryptTable[] = {
		L"A0", L"0$", L"$#", L"#V", L"V(", L"(M", L"MS", L"S%", L"%k", L"kj", L"j>", L">,",
		L",!", L"!`", L"`2", L"23", L"3;", L";2", L"2x", L"x|", L"|F", L"Fl", L"l\"", L"\".",
		L".4", L"4#"
	};

	while (*lpPtr) {
		WCHAR ch = *lpPtr;
		if (ch >= L'a' && ch <= L'z') {
			LPCWSTR lpEncryptChar = lpEncryptTable[ch - L'a'];
			*lpEncryptedPtr++ = lpEncryptChar[0];
			*lpEncryptedPtr++ = lpEncryptChar[1];
		}
		else
			*lpEncryptedPtr++ = ch;
		lpPtr++;
	}
	*lpEncryptedPtr = 0;
}

void __stdcall UHCRegisterCheat(UHCInfo* info, LPCWSTR string, BOOL enable, void(__stdcall * fPtr)(void*)) {
	DWORD length = lstrlenW(string);
	LPWSTR lpEncrypted = new WCHAR[length * 2 + 1];

	EncryptString(lpEncrypted, string);

	if (!lpEncrypted)
		return;

	UHCCheat& cheat = info->Cheats.InsertEmptyBack();
	cheat.String = lpEncrypted;
	cheat.Enable = enable;
	cheat.FunctionPtr = fPtr;
}

UHCSyscall& __stdcall UHCRegisterSyscall(UHCInfo* info, UHCSyscallGroupName groupName,
	DWORD retType, LPCSTR name, LPVOID fPtr, DWORD paramCount, LPCSTR comment) {
	TArray<UHCSyscall>& group = info->SyscallGroups[groupName];

	UHCSyscall& syscall = group.InsertEmptyBack();
	syscall.Params = new UHCSyscallParam[paramCount];

	syscall.RetType = retType;
	syscall.Name = name;
	syscall.Ptr = fPtr;
	syscall.ParamCount = paramCount;
	syscall.Comment = comment;

	return syscall;
}

void __stdcall UHCSyscallSetParam(UHCSyscall& syscall, DWORD paramId, DWORD type, LPCVOID defaultVal) {
	if (paramId >= syscall.ParamCount)
		return;

	syscall.Params[paramId].Type = type;
	syscall.Params[paramId].Default = defaultVal;
}

inline void SetRefTable(UHCRefTable& table, ConfigKey& key) {
	table.RefCount = key.Values.GetNumElements();
	table.RefIDs = new DWORD[table.RefCount];
	table.Refs = key.Values.GetData();
}

LPWSTR __stdcall UHCAnsiStrToWideStr(CHAR* lpStr) {

	int lenght = lstrlenA(lpStr);

	if (lenght) {
		LPWSTR wideStr = new WCHAR[lenght];

		for (int i = 0; i < lenght; i++)
			wideStr[i] = (WCHAR)lpStr[i];

		return wideStr;
	}

	return NULL;
}

UHCInfo* UHCInfo::Instance = nullptr;

UHCInfo::UHCInfo() {
	LPCWSTR szConfig = (LPCWSTR)0x00C65083;
	//LPCWSTR lpStartup = (LPCWSTR)0xbeaf98;

	hHeap = GetProcessHeap();

	Enable = 0;

	//lstrcpyW(szConfig, lpStartup);
	//lstrcatW(szConfig, L"uhc.cfg");

	for (DWORD i = 0; i < TABLE_COUNT; i++) {
		Tables[i].RefCount = 0;
		Tables[i].Refs = 0;
		Tables[i].RefIDs = 0;
	}
	
	BasePop = 200;
	ExtraPop = 50;
	DeckCardCount = 25;

	m_Config = new Config;

	FixWorkingPath();

	if (!m_Config->Parse(szConfig))
		return;

	for (DWORD i = 0; i < m_Config->GetKeys().GetNumElements(); i++) {
		ConfigKey& key = m_Config->GetKeys()[i];

		if (lstrcmpiA(key.Name, "enableFarmAnim") == 0) {
			Enable |= ENABLE_FARM_ANIM;
			SetRefTable(Tables[Farm], key);
		}

		else if (lstrcmpiA(key.Name, "enableRectFarmAnim") == 0) {
			Enable |= ENABLE_FARM_ANIM;
			SetRefTable(Tables[RectFarm], key);
		}

		else if (lstrcmpiA(key.Name, "marketUnits") == 0) {
			Enable |= ENABLE_PATCH_MARKET;
			SetRefTable(Tables[Market], key);
		}

		else if (lstrcmpiA(key.Name, "bigButtonCivs") == 0) {
			Enable |= ENABLE_BIGBUTTON;
			SetRefTable(Tables[BigButtonCivs], key);
		}

		else if (lstrcmpiA(key.Name, "noBigButtonBlds") == 0) {
			Enable |= ENABLE_BIGBUTTON;
			SetRefTable(Tables[NoBigButtonBlds], key);
		}

		else if (lstrcmpiA(key.Name, "asianCivs") == 0) {
			Enable |= ENABLE_ASIAN_CIVS;
			SetRefTable(Tables[Asian], key);

			for (DWORD i = 0; i < Tables[Asian].RefCount; i++) {
				AsianCivNames.PushBack(UHCAnsiStrToWideStr(Tables[Asian].Refs[i]));
			}
		}

		else if (lstrcmpiA(key.Name, "nativeCivs") == 0) {
			Enable |= ENABLE_NATIVE_CIVS;
			SetRefTable(Tables[Native], key);

			for (DWORD i = 0; i < Tables[Native].RefCount; i++) {
				NativeCivNames.PushBack(UHCAnsiStrToWideStr(Tables[Native].Refs[i]));
			}
		}

		else if (lstrcmpiA(key.Name, "basePop") == 0 && key.Values.GetNumElements() == 1) {
			Enable |= ENABLE_POP_LIMIT;
			BasePop = atoi(key.Values[0]);
		}

		else if (lstrcmpiA(key.Name, "extraPop") == 0 && key.Values.GetNumElements() == 1) {
			Enable |= ENABLE_POP_LIMIT;
			ExtraPop = atoi(key.Values[0]);
		}

		else if (lstrcmpiA(key.Name, "deckCardCount") == 0 && key.Values.GetNumElements() == 1) {
			Enable |= ENABLE_DECK_LIMIT;
			DeckCardCount = atoi(key.Values[0]);
		}

		else if (lstrcmpiA(key.Name, "noAILimit") == 0)
			Enable |= ENABLE_AI_LIMIT;

		else if (lstrcmpiA(key.Name, "customCheats") == 0)
			Enable |= ENABLE_CHEAT;

		else if (lstrcmpiA(key.Name, "ignoreRegistryPath") == 0)
			Enable |= ENABLE_REGISTRY_PATH;

		else if (lstrcmpiA(key.Name, "customRevolutionBanners") == 0)
			Enable |= ENABLE_REV_BANNER;

		else if (lstrcmpiA(key.Name, "customSyscalls") == 0)
			Enable |= ENABLE_SYSCALL;

		else if (lstrcmpiA(key.Name, "enableAllTeams") == 0)
			Enable |= ENABLE_TEAM_LIMIT;
	}
}

UHCInfo::~UHCInfo() {
	for (size_t i = 0; i < TABLE_COUNT; i++)
		delete[] Tables[i].RefIDs;

	for (size_t i = 0; i < Cheats.GetNumElements(); i++)
		delete[] Cheats[i].String;

	for (size_t g = 0; g < GROUP_COUNT; g++) {
		for (size_t i = 0; i < SyscallGroups[g].GetNumElements(); i++)
			delete[] SyscallGroups[g][i].Params;
	}

	for (size_t i = 0; i < Personalities.GetNumElements(); i++)
		delete[] Personalities[i];

	for (size_t i = 0; i < AsianCivNames.GetNumElements(); i++)
		delete[] AsianCivNames[i];

	for (size_t i = 0; i < NativeCivNames.GetNumElements(); i++)
		delete[] NativeCivNames[i];
}

void LoadPlugins() {
	WIN32_FIND_DATAW fd;
	HANDLE hFind = FindFirstFileW(L"*.upl", &fd);

	UHCPluginInfo pluginInfo = {
		UHCInfo::Instance,
		UHCRegisterCheat,
		UHCRegisterSyscall,
		UHCSyscallSetParam
	};

	if (hFind != INVALID_HANDLE_VALUE) {

		do {
			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				continue;
			HMODULE hLib = LoadLibraryW(fd.cFileName);

			if (!hLib)
				continue;

			FARPROC pluginProc = GetProcAddress(hLib, "_UHCPluginMain@4");

			if (pluginProc)
				((int(__stdcall*)(UHCPluginInfo*))pluginProc)(&pluginInfo);
		} while (FindNextFileW(hFind, &fd));
	}

	FindClose(hFind);
}

extern "C" _declspec(dllexport)
void APIENTRY UHCMain() {
	HANDLE hProcess = GetCurrentProcess();

	try
	{
#ifdef _DEBUG
		MessageBoxA(0, "'UHC.dll' Loaded.", "UHC", MB_ICONINFORMATION);
#endif

		UHCInfo::Instance = new UHCInfo;

		UHCAsmInit(UHCInfo::Instance, hProcess);

		DWORD enable = UHCInfo::Instance->Enable;

		// Patch stuffs we enabled
		if (enable & ENABLE_AI_LIMIT)
			PatchAILimit();

		if (enable & ENABLE_CHEAT)
			PatchCheat();

		if (enable & ENABLE_DECK_LIMIT)
			PatchDeckLimit();

		if (enable & (ENABLE_FARM_ANIM | ENABLE_PATCH_MARKET | ENABLE_BIGBUTTON))
			PatchUnitChecking();

		if (enable & ENABLE_FARM_ANIM)
			PatchFarmAnim();

		if (enable & ENABLE_PATCH_MARKET)
			PatchMarketUnits();

		if (enable & (ENABLE_ASIAN_CIVS | ENABLE_NATIVE_CIVS | ENABLE_BIGBUTTON))
			PatchCivChecking();

		if (enable & ENABLE_ASIAN_CIVS)
			PatchAsianCivs();

		if (enable & ENABLE_NATIVE_CIVS)
			PatchNativeCivs();
		
		if (enable & ENABLE_BIGBUTTON)
			PatchBigButton();

		if (enable & ENABLE_POP_LIMIT)
			PatchPopLimit();

		if (enable & ENABLE_REV_BANNER)
			PatchRevBanner();

		if (enable & ENABLE_SYSCALL)
			PatchSyscall();

		if (enable & ENABLE_TEAM_LIMIT)
			PatchTeamLimit();

		if (enable & ENABLE_REGISTRY_PATH)
			PatchRegistryPath();

		// Load .upl plugins
		LoadPlugins();

#ifdef TEST
		TestInit();
#endif
	}
	catch (...)
	{
		MessageBoxA(0, "Failed to load UHC config!", "Initialization error", MB_ICONERROR | MB_OK);
		ExitProcess(0);
	}
}

#include <fstream>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_DETACH:
		if (UHCInfo::Instance)
			delete UHCInfo::Instance;
	}


	return TRUE;
}

