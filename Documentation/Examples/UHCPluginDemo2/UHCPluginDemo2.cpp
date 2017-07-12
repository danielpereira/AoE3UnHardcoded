// UHCPluginDemo2.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "syscalls.h"
#include "UHCPlugin.h"
#include "CheatFunctions.h"

void __stdcall testCheat(void* playerData) {
	CheatAddResource(playerData, SHIPMENTS, 10000.00, 0);
}

extern "C" _declspec(dllexport)
int __stdcall UHCPluginMain(UHCPluginInfo* pluginInfo) {

	pluginInfo->RegisterCheat(pluginInfo->info, L"this is a complication", TRUE, testCheat);

	return 0;
}
