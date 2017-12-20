#ifndef _UHCPLUGIN_H
#define _UHCPLUGIN_H

#include "syscalls.h"

enum UHCSyscallType {
	SyscallVoid = 1,
	SyscallInteger = 2,
	SyscallFloat = 4,
	SyscallBool = 8,
	SyscallString = 16,
	SyscallVector = 32
};

enum UHCSyscallGroupName {
	GroupAI,
	GroupHC,
	GroupKB,   // AI and triggers
	GroupRM,
	GroupTR,
	GroupUI,   // Triggers and UI xmls
	GroupUI2,  // UI xmls only
	GroupXS
};

struct UHCSyscall;

typedef enum RESOURCE_ID {
	GOLD,
	WOOD,
	FOOD,
	FAME,
	ID_4,
	XP,
	SHIPMENTS,
	EXPORT
} RESOURCE_ID;

#if defined(__MINGW32__) || defined(_MSC_VER)
#define CHEATCALL __stdcall
#elif defined(__GNUC__) || defined(__GNUG__)
#define CHEATCALL __attribute__((stdcall))
#endif

struct UHCPluginInfo {
	void(*RegisterCheat)(const char* string, bool enable, void(CHEATCALL * fPtr)(void*));

	UHCSyscall&(*RegisterSyscall)(UHCSyscallGroupName groupName, unsigned int retType, const char* name, const void* fPtr, unsigned int paramCount, const char* comment);

	void(*SyscallSetParam)(UHCSyscall& syscall, unsigned int paramId, unsigned int type, const void* defaultVal);

	bool(*CheatAddResource)(void* playerData, int resourceID, float resourceAmount, bool unk);

	void(*CheatSpawnUnit)(void* playerData, const char* protoUnitName);
};

#endif
