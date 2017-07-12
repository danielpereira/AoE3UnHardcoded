#ifndef _UHC_H
#define _UHC_H

#include "syscalls.h"

enum UHCSyscallType {
	Void = 1,
	Integer = 2,
	Float = 4,
	Bool = 8,
	String = 16,
	Vector = 32
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

struct UHCInfo;
struct UHCSyscall;

struct UHCPluginInfo {
	UHCInfo* info;

	void(__stdcall *RegisterCheat)(UHCInfo* info, const wchar_t* string, bool enable, void(__stdcall * fPtr)(void*));

	UHCSyscall& (__stdcall *RegisterSyscall)(UHCInfo* info, UHCSyscallGroupName groupName,
		__int32 retType, const char* name, void* fPtr, __int32 paramCount, const char* comment);

	void(__stdcall *SyscallSetParam)(UHCSyscall& syscall, __int32 paramId, __int32 type, const void* defaultVal);
};

#endif
