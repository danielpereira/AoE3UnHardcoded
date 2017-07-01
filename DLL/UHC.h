#pragma once

#include "TArray.h"
#include "Config.h"

struct UHCRefTable {
	DWORD RefCount;
	LPSTR *Refs;
	DWORD *RefIDs;
};

#define TABLE_COUNT 7

enum UHCTableName {
	Farm,
	RectFarm,
	Market,
	Asian,
	Native,
	BigButtonCivs,
	NoBigButtonBlds
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
	LPVOID Ptr;
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
	LPVOID FunctionPtr;
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
#define ENABLE_WOL_BIGBUTTON 0x1000

class UHCInfo {
public:
	static UHCInfo* Instance;

	HANDLE hHeap;
	DWORD Enable;
	UHCRefTable Tables[TABLE_COUNT];
	int BasePop, ExtraPop, DeckCardCount;
	TArray<UHCSyscall> SyscallGroups[GROUP_COUNT];
	TArray<UHCCheat> Cheats;
	TArray<LPWSTR> Personalities;
	TArray<LPWSTR> AsianCivNames;
	TArray<LPWSTR> NativeCivNames;

	UHCInfo();
	~UHCInfo();

private:
	Config* m_Config;
};

extern "C" {
	void __stdcall UHCRegisterCheat(UHCInfo* info, LPCWSTR string, BOOL enable, void (__stdcall * fPtr)(void*));

	UHCSyscall& __stdcall UHCRegisterSyscall(UHCInfo* info, UHCSyscallGroupName groupName,
		DWORD retType, LPCSTR name, LPVOID fPtr, DWORD paramCount, LPCSTR comment);

	void __stdcall UHCSyscallSetParam(UHCSyscall& syscall, DWORD paramId, DWORD type, LPCVOID defaultVal);
	LPWSTR __stdcall UHCAnsiStrToWideStr(CHAR* lpStr);

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
	void __stdcall PatchUnitChecking();
	void __stdcall PatchMarketUnits();
	void __stdcall PatchCivChecking();
	void __stdcall PatchAsianCivs();
	void __stdcall PatchNativeCivs();
	void __stdcall PatchWoLBigButton();

	void __stdcall PatchDumpSyscall();
}

struct UHCPluginInfo {
	UHCInfo* info;

	void (__stdcall *RegisterCheat)(UHCInfo* info, LPCWSTR string, BOOL enable, void(__stdcall * fPtr)(void*));

	UHCSyscall& (__stdcall *RegisterSyscall)(UHCInfo* info, UHCSyscallGroupName groupName,
		DWORD retType, LPCSTR name, LPVOID fPtr, DWORD paramCount, LPCSTR comment);

	void(__stdcall *SyscallSetParam)(UHCSyscall& syscall, DWORD paramId, DWORD type, LPCVOID defaultVal);
};