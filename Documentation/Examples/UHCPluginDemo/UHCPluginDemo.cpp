// UHCPluginDemo.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

using namespace syscalls;

// syscalls that returns a 'vector' uses the first parameter to return its value
void vectorSyscallExample(vector ret) {
	kbGetMapCenter(ret);
}

void test(int player) {
	aiChat(player, "Hello World!");
}

void msgBox(string caption, string message) {
	MessageBoxA(NULL, message, caption, MB_ICONASTERISK);
}

// Turns a random enemy's settlers into sheep
void __stdcall cheatExample(void* playerData) {
	xsSetContextPlayer(1);
	for (int i = 1; i < GetNumberPlayers(); i++) {
		if (kbIsPlayerEnemy(i) && !kbIsPlayerResigned(i)) {
			xsSetContextPlayer(i);
			trUnitSelectClear();

			int unitQueryID = kbUnitQueryCreate("CheatUnitQuery");
			kbUnitQuerySetIgnoreKnockedOutUnits(unitQueryID, true);
			kbUnitQuerySetPlayerID(unitQueryID, i, true);
			kbUnitQuerySetUnitType(unitQueryID, kbGetProtoUnitID("Settler"));
			kbUnitQuerySetState(unitQueryID, cUnitStateAlive);
			kbUnitQueryResetResults(unitQueryID);
			int numberFound = kbUnitQueryExecute(unitQueryID);

			for (int n = 0; n < numberFound; n++)
				trUnitSelectByID(kbUnitQueryGetResult(unitQueryID, n));

			trUnitChangeProtoUnit("Sheep");
			//trSoundPlayFN("SheepSelect.wav", "", -1, "", "");	
			break;
		}
	}
}

int aiDefaultParamValue = 1;

extern "C" _declspec(dllexport)
int __stdcall UHCPluginMain(UHCPluginInfo* pluginInfo) {
	// Register your syscalls and cheats here...

	// After registering a syscall, it can be used in the 'scope' you defined.
	pluginInfo->RegisterSyscall(pluginInfo->info, GroupXS, Vector,
		"xsTest", test, 0, "xsTest: vector syscall example.");

	UHCSyscall& aiTest = pluginInfo->RegisterSyscall(pluginInfo->info, GroupAI, Void,
		"aiTest", (void*)test, 1, "aiTest: Sends 'Hello World!' to specified player.");

	pluginInfo->SyscallSetParam(aiTest, 0, Integer, &aiDefaultParamValue);

	UHCSyscall& aiMsgBox = pluginInfo->RegisterSyscall(pluginInfo->info, GroupAI, Void, "aiMsgBox", (void*)msgBox, 2, "aiMsgBox: Displays a message box");
	pluginInfo->SyscallSetParam(aiMsgBox, 0, String, "Caption");
	pluginInfo->SyscallSetParam(aiMsgBox, 1, String, "Message");

	pluginInfo->RegisterCheat(pluginInfo->info, L"force of nature", true, cheatExample);

	return 0;
}


