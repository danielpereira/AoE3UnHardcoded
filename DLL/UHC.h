#pragma once

#include "TArray.h"
#include "Config.h"
#include <Zydis/Zydis.h>

struct UHCRefTable {
	DWORD RefCount;
	LPSTR *Refs;
	DWORD *RefIDs;
};

#define TABLE_COUNT 11

enum UHCTableName {
	Farm,
	RectFarm,
	Market,
	Asian,
	Native,
	TacticSwitching,
	BigButtonCivs,
	NoBigButtonBlds,
	AttackTypeIcons,
	TwoScoutCivs,
	ExplorerUnits,
	Upls
};

enum UHCSyscallType {
	SyscallVoid = 1,
	SyscallInteger = 2,
	SyscallFloat = 4,
	SyscallBool = 8,
	SyscallString = 16,
	SyscallVector = 32
};

struct UHCSyscallParam {
	DWORD Type;
	LPCVOID Default;
};

struct UHCSyscall {
	DWORD RetType;
	LPCSTR Name;
	LPCVOID Ptr;
	LPCSTR Comment;
	DWORD ParamCount;
	UHCSyscallParam* Params;
};

#define GROUP_COUNT 8

enum UHCSyscallGroupName {
	GroupAI,
	GroupHC,
	GroupKB,
	GroupRM,
	GroupTR,
	GroupUI,
	GroupUI2,
	GroupXS
};

struct UHCCheat {
	LPCWSTR String;
	BOOL Enable;
	void(__stdcall * FunctionPtr)(void*);
};

struct UHCFarmRadius {
	DWORD RefIndex;
	float X, Z;
};

struct UHCTypeIcons {
	LPWSTR IconPath;
	DWORD StringID, IconData;
};

struct UHCExplorer {
	DWORD Type, DeathStringID;
};

#define ENABLE_AI_LIMIT 0x1
#define ENABLE_CHEAT 0x2
#define ENABLE_DECK_LIMIT 0x4
#define ENABLE_FARM_ANIM 0x8
#define ENABLE_POP_LIMIT 0x10
#define ENABLE_REGISTRY_PATH 0x20
#define ENABLE_REV_BANNER 0x40
#define ENABLE_SYSCALL 0x80
#define ENABLE_TEAM_LIMIT 0x100
#define ENABLE_PATCH_MARKET 0x200
#define ENABLE_NATIVE_CIVS 0x400
#define ENABLE_ASIAN_CIVS 0x800
#define ENABLE_BIGBUTTON 0x1000
#define ENABLE_FARM_RADIUS 0x2000
#define ENABLE_TACTIC_SWITCHING 0x4000
#define REMOVE_FAME_RESTRICTION 0x8000
#define ENABLE_TYPE_ICONS 0x10000
#define ENABLE_TWO_SCOUT_CIVS 0x20000
#define ENABLE_NEW_EXPLORERS 0x40000
#define REMOVE_CONVERSION_RESTRICTION 0x80000

class UHCInfo {
public:
	DWORD Enable;
	UHCRefTable Tables[TABLE_COUNT];
	int BasePop, ExtraPop, DeckCardCount;
	TArray<UHCSyscall> SyscallGroups[GROUP_COUNT];
	TArray<UHCCheat> Cheats;
	TArray<LPWSTR> UplFilepaths;
	TArray<LPWSTR> Personalities;
	TArray<LPWSTR> AsianCivNames;
	TArray<LPWSTR> NativeCivNames;
	TArray<UHCFarmRadius> FarmRadiusInfo;
	TArray<UHCTypeIcons> TypeIconsInfo;
	TArray<UHCExplorer> ExplorerInfo;
	DWORD HCXpIconData;
	DWORD HCFameIconData;

	ZydisDecoder Decoder;

	UHCInfo();
	~UHCInfo();

	void LoadPlugins();

private:
	Config* m_Config;
};

extern "C" {
	extern UHCInfo* pUHCInfo;
	extern HANDLE hProcess;

	extern LPWSTR hcXpIconPath;
	extern LPWSTR hcFameIconPath;

	void UHCRegisterCheat(LPCSTR string, BOOL enable, void (__stdcall * fPtr)(void*));

	UHCSyscall& UHCRegisterSyscall(DWORD groupName, DWORD retType, LPCSTR name, LPCVOID fPtr, DWORD paramCount, LPCSTR comment);

	void UHCSyscallSetParam(UHCSyscall& syscall, DWORD paramId, DWORD type, LPCVOID defaultVal);

	bool CheatAddResource(void* playerData, int resourceID, float resourceAmount, bool unk);

	// ASM stuffs
	void __stdcall UHCAsmInit(UHCInfo* info, HANDLE hProcess);

	void __stdcall PatchAILimit();
	void __stdcall PatchCheat();
	void __stdcall PatchDeckLimit();
	void __stdcall PatchFarmAnim();
	void __stdcall PatchPopLimit();
	void __stdcall PatchRegistryPath();
	void __stdcall PatchRevBanner();
	void __stdcall PatchSyscall();
	void __stdcall PatchTeamLimit();
	void __stdcall PatchUnitCheck();
	void __stdcall PatchMarketUnits();
	void __stdcall PatchCivCheck();
	void __stdcall PatchAsianCivs();
	void __stdcall PatchNativeCivs();
	void __stdcall PatchBigButton();
	void __stdcall PatchFarmRadius();
	void __stdcall PatchTacticSwitching();
	void __stdcall PatchFameRestriction();
	void __stdcall PatchFameTrickle();
	void __stdcall PatchAttackTypeIcons();
	void __stdcall PatchTwoScoutCivs();
	void __stdcall PatchExplorerUnits();
	void __stdcall PatchConversionRestriction();

	BOOL __stdcall TableIDExists(DWORD dwTable, int id);

	//void __stdcall PatchDumpSyscall();
}

struct UHCPluginInfo {
	void(*const RegisterCheat)(LPCSTR string, BOOL enable, void(__stdcall * fPtr)(void*));

	UHCSyscall&(*const RegisterSyscall)(DWORD groupName, DWORD retType, LPCSTR name, LPCVOID fPtr, DWORD paramCount, LPCSTR comment);

	void(*const SyscallSetParam)(UHCSyscall& syscall, DWORD paramId, DWORD type, LPCVOID defaultVal);

	bool(*const CheatAddResource)(void* playerData, int resourceID, float resourceAmount, bool unk);

	void(*const CheatSpawnUnit)(void* playerData, const char* protoUnitName);
};