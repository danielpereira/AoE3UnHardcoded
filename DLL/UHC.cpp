#include "stdafx.h"
#include "UHC.h"

UHCInfo* pUHCInfo = nullptr;
HANDLE hProcess = NULL;

LPWSTR hcXpIconPath = L"ui\\home_city\\xp_hc_icon";
LPWSTR hcFameIconPath = L"ui\\home_city\\fame_hc_icon";

UHCPluginInfo pluginInfo = {
	UHCRegisterCheat,
	UHCRegisterSyscall,
	UHCSyscallSetParam,
	CheatAddResource,
	reinterpret_cast<void(*)(void*, const char*)>(0x007B4F03)
};

// request high-performance NVIDIA GPU
extern "C" {
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

// request high-performance AMD GPU
extern "C" {
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

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

void EncryptCheatString(LPWSTR dest, LPCWSTR src) {
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

void UHCRegisterCheat(LPCSTR string, BOOL enable, void(__stdcall * fPtr)(void*)) {
	DWORD length = lstrlenA(string);
	LPWSTR lpString = new WCHAR[length + 1];
	LPWSTR lpEncrypted = new WCHAR[length * 2 + 1];

	mbstowcs(lpString, string, length + 1);

	EncryptCheatString(lpEncrypted, lpString);

	delete[] lpString;

	UHCCheat& cheat = pUHCInfo->Cheats.InsertEmptyBack();
	cheat.String = lpEncrypted;
	cheat.Enable = enable;
	cheat.FunctionPtr = fPtr;
}

UHCSyscall& UHCRegisterSyscall(DWORD groupName, DWORD retType, LPCSTR name, LPCVOID fPtr, DWORD paramCount, LPCSTR comment) {
	TArray<UHCSyscall>& group = pUHCInfo->SyscallGroups[groupName];

	UHCSyscall& syscall = group.InsertEmptyBack();
	syscall.Params = new UHCSyscallParam[paramCount];

	syscall.RetType = retType;
	syscall.Name = name;
	syscall.Ptr = fPtr;
	syscall.ParamCount = paramCount;
	syscall.Comment = comment;

	return syscall;
}

void UHCSyscallSetParam(UHCSyscall& syscall, DWORD paramId, DWORD type, LPCVOID defaultVal) {
	if (paramId >= syscall.ParamCount)
		return;

	syscall.Params[paramId].Type = type;
	syscall.Params[paramId].Default = defaultVal;
}

bool CheatAddResource(void* playerData, int resourceID, float resourceAmount, bool unk)
{
	return reinterpret_cast<bool(__thiscall*)(void*, int, float, bool)>(0x0049A98A)(playerData, resourceID, resourceAmount, unk);
}

inline void SetRefTable(UHCRefTable& table, ConfigKey& key) {
	table.RefCount = key.Values.GetNumElements();
	table.RefIDs = new DWORD[table.RefCount];
	table.Refs = key.Values.GetData();
}

UHCInfo::UHCInfo() {
	// UHC Patcher default string offset
	LPCWSTR szConfig = (LPCWSTR)0x00C65083;

	//WCHAR szConfig[MAX_PATH];
	//LPCWSTR lpStartup = (LPCWSTR)0xbeaf98;
	//lstrcpyW(szConfig, lpStartup);
	//lstrcatW(szConfig, L"uhc.cfg");

	Enable = 0;

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
				LPCSTR lpSrc = Tables[Asian].Refs[i];
				size_t length = lstrlenA(lpSrc) + 1;
				WCHAR* lpStr = new WCHAR[length];
				mbstowcs(lpStr, lpSrc, length);
				AsianCivNames.PushBack(lpStr);
			}
		}

		else if (lstrcmpiA(key.Name, "nativeCivs") == 0) {
			Enable |= ENABLE_NATIVE_CIVS;
			SetRefTable(Tables[Native], key);

			for (DWORD i = 0; i < Tables[Native].RefCount; i++) {
				LPCSTR lpSrc = Tables[Native].Refs[i];
				size_t length = lstrlenA(lpSrc) + 1;
				WCHAR* lpStr = new WCHAR[length];
				mbstowcs(lpStr, lpSrc, length);
				NativeCivNames.PushBack(lpStr);
			}
		}

		else if (!lstrcmpiA(key.Name, "farmingRadius")) {
			Enable |= ENABLE_FARM_RADIUS;

			size_t i = 0;

			while (i + 2 < key.Values.GetNumElements()) {
				UHCFarmRadius aux;
				aux.RefIndex = atoi(key.Values[i++]);
				aux.X = (float) atof(key.Values[i++]);
				aux.Z = (float) atof(key.Values[i++]);
				FarmRadiusInfo.PushBack(aux);
			}

		}

		else if (!lstrcmpiA(key.Name, "attackTypeIcons")) {
			if (!(key.Values.GetNumElements() % 3)) {
				Enable |= ENABLE_TYPE_ICONS;

				Tables[AttackTypeIcons].RefCount = key.Values.GetNumElements() / 3;
				Tables[AttackTypeIcons].Refs = new LPSTR[Tables[AttackTypeIcons].RefCount];
				Tables[AttackTypeIcons].RefIDs = new DWORD[Tables[AttackTypeIcons].RefCount];

				size_t i = 0, j = 0;

				while (i + 2 < key.Values.GetNumElements()) {
					UHCTypeIcons aux;

					Tables[AttackTypeIcons].Refs[j++] = key.Values[i++];
					aux.StringID = atoi(key.Values[i++]);
					size_t length = lstrlenA(key.Values[i]) + 1;
					aux.IconPath = new WCHAR[length];
					mbstowcs(aux.IconPath, key.Values[i++], length);
					TypeIconsInfo.PushBack(aux);
				}
			}
		}

		else if (!lstrcmpiA(key.Name, "explorerUnits")) {
			if (!(key.Values.GetNumElements() % 3)) {
				Enable |= ENABLE_NEW_EXPLORERS;

				Tables[ExplorerUnits].RefCount = key.Values.GetNumElements() / 3;
				Tables[ExplorerUnits].Refs = new LPSTR[Tables[ExplorerUnits].RefCount];
				Tables[ExplorerUnits].RefIDs = new DWORD[Tables[ExplorerUnits].RefCount];

				size_t i = 0, j = 0;

				while (i + 2 < key.Values.GetNumElements()) {
					UHCExplorer aux;

					Tables[ExplorerUnits].Refs[j++] = key.Values[i++];
					aux.Type = atoi(key.Values[i++]);
					aux.DeathStringID = atoi(key.Values[i++]);
					ExplorerInfo.PushBack(aux);
				}
			}
		}

		else if (lstrcmpiA(key.Name, "twoScoutCivs") == 0) {
			Enable |= ENABLE_TWO_SCOUT_CIVS;
			SetRefTable(Tables[TwoScoutCivs], key);
		}

		else if (!lstrcmpiA(key.Name, "tacticSwitching")) {
			Enable |= ENABLE_TACTIC_SWITCHING;
			SetRefTable(Tables[TacticSwitching], key);
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

		else if (lstrcmpiA(key.Name, "customSyscalls") == 0) {
			Enable |= ENABLE_SYSCALL;
			SetRefTable(Tables[Upls], key);

			for (DWORD i = 0; i < Tables[Upls].RefCount; i++) {
				LPCSTR lpSrc = Tables[Upls].Refs[i];
				size_t length = lstrlenA(lpSrc) + 1;
				WCHAR* lpStr = new WCHAR[length];
				mbstowcs(lpStr, lpSrc, length);
				UplFilepaths.PushBack(lpStr);
			}
		}

		else if (lstrcmpiA(key.Name, "enableAllTeams") == 0)
			Enable |= ENABLE_TEAM_LIMIT;

		else if (lstrcmpiA(key.Name, "removeFameRestriction") == 0)
			Enable |= REMOVE_FAME_RESTRICTION;

		else if (lstrcmpiA(key.Name, "removeConversionRestriction") == 0)
			Enable |= REMOVE_CONVERSION_RESTRICTION;
	}

	ZydisDecoderInit(&Decoder, ZYDIS_MACHINE_MODE_LONG_COMPAT_32, ZYDIS_ADDRESS_WIDTH_32);
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

	for (size_t i = 0; i < UplFilepaths.GetNumElements(); i++)
		delete[] UplFilepaths[i];

	for (size_t i = 0; i < Personalities.GetNumElements(); i++)
		delete[] Personalities[i];

	for (size_t i = 0; i < AsianCivNames.GetNumElements(); i++)
		delete[] AsianCivNames[i];

	for (size_t i = 0; i < NativeCivNames.GetNumElements(); i++)
		delete[] NativeCivNames[i];
}

void UHCInfo::LoadPlugins() {
	// defaults to load all upls in folder if none specified
	if (UplFilepaths.GetNumElements() == 0) {
		UplFilepaths.PushBack(L"*.upl");
	}

	for (size_t i = 0; i < UplFilepaths.GetNumElements(); i++) {

		WIN32_FIND_DATAW fd;
		HANDLE hFind = FindFirstFileW(UplFilepaths[i], &fd);

		if (hFind != INVALID_HANDLE_VALUE) {

			do {
				if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
					continue;
				HMODULE hLib = LoadLibraryW(fd.cFileName);

				if (!hLib)
					continue;

				FARPROC pluginProc = GetProcAddress(hLib, "UHCPluginMain");

				if (pluginProc) {
					int exitCode;

					exitCode = reinterpret_cast<int(*)(UHCPluginInfo*)>(pluginProc)(&pluginInfo);

#ifdef _DEBUG
					WCHAR debugMsg[256];
					wsprintfW(debugMsg, L"UHC Plugin \"%s\" returned with exit code %d.\n", fd.cFileName, exitCode);
					OutputDebugStringW(debugMsg);
#endif
				}

			} while (FindNextFileW(hFind, &fd));
		}

		FindClose(hFind);
	}
}

extern "C" _declspec(dllexport)
void APIENTRY UHCMain() {
	hProcess = GetCurrentProcess();

	try
	{
#ifdef _DEBUG
		MessageBoxA(0, "'UHC.dll' Loaded.", "UHC", MB_ICONINFORMATION);
#endif

		pUHCInfo = new UHCInfo;

		DWORD enable = pUHCInfo->Enable;

		// Patch stuffs we enabled
		if (enable & ENABLE_AI_LIMIT)
			PatchAILimit();

		if (enable & ENABLE_CHEAT)
			PatchCheat();

		if (enable & ENABLE_DECK_LIMIT)
			PatchDeckLimit();

		if (enable & (ENABLE_FARM_ANIM | ENABLE_PATCH_MARKET | ENABLE_BIGBUTTON | ENABLE_NEW_EXPLORERS))
			PatchUnitCheck();

		if (enable & ENABLE_FARM_ANIM)
			PatchFarmAnim();

		if (enable & ENABLE_FARM_RADIUS)
			PatchFarmRadius();

		if (enable & ENABLE_TACTIC_SWITCHING)
			PatchTacticSwitching();

		if (enable & ENABLE_TYPE_ICONS)
			PatchAttackTypeIcons();

		if (enable & ENABLE_PATCH_MARKET)
			PatchMarketUnits();

		if (enable & ENABLE_NEW_EXPLORERS)
			PatchExplorerUnits();

		if (enable & (ENABLE_ASIAN_CIVS | ENABLE_NATIVE_CIVS | ENABLE_BIGBUTTON | ENABLE_TWO_SCOUT_CIVS))
			PatchCivCheck();

		if (enable & ENABLE_ASIAN_CIVS)
			PatchAsianCivs();

		if (enable & ENABLE_NATIVE_CIVS)
			PatchNativeCivs();
		
		if (enable & ENABLE_TWO_SCOUT_CIVS)
			PatchTwoScoutCivs();

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

		if (enable & REMOVE_FAME_RESTRICTION) {
			PatchFameRestriction();
            PatchFameTrickle();
        }

		if (enable & REMOVE_CONVERSION_RESTRICTION)
			PatchConversionRestriction();

		// Load .upl plugins
		if (enable & (ENABLE_CHEAT | ENABLE_SYSCALL))
			pUHCInfo->LoadPlugins();
	}
	catch (...)
	{
		MessageBoxA(0, "Failed to load UHC config!", "Initialization error", MB_ICONERROR | MB_OK);
		ExitProcess(0);
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_DETACH:
		if (pUHCInfo)
			delete pUHCInfo;
	}

	return TRUE;
}

