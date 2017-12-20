// UHCPluginDemo.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <cmath>

using namespace syscalls;

UHCPluginInfo* g_PluginInfo = nullptr;

// Turns all enemy villagers into sheep
void CHEATCALL ForceOfNature(void* playerData) {
	int villagerType = -1;

	array<wchar_t*>* unitTypes = GetUnitTypes();

	for (int i = 0; i < unitTypes->Count; i++) {
		if (wcscmp(unitTypes->Array[i], L"AbstractVillager") == 0) {
			villagerType = i;
			break;
		}
	}

	for (int i = 1; i < GetNumberPlayers(); i++) {
		xsSetContextPlayer(1);

		if (kbIsPlayerEnemy(i) && !kbIsPlayerResigned(i)) {
			xsSetContextPlayer(i);
			trUnitSelectClear();

			int unitQueryID = kbUnitQueryCreate("CheatUnitQuery");
			kbUnitQuerySetIgnoreKnockedOutUnits(unitQueryID, true);
			kbUnitQuerySetPlayerID(unitQueryID, i, true);
			kbUnitQuerySetUnitType(unitQueryID, villagerType);
			kbUnitQuerySetState(unitQueryID, cUnitStateAlive);
			kbUnitQueryResetResults(unitQueryID);
			int numberFound = kbUnitQueryExecute(unitQueryID);

			for (int n = 0; n < numberFound; n++)
				trUnitSelectByID(kbUnitQueryGetResult(unitQueryID, n));

			trUnitChangeProtoUnit("Sheep");

			kbUnitQueryDestroy(unitQueryID);
		}
	}
}

// Add 10000 shipments
void CHEATCALL ThisIsAComplication(void * playerData) {
	// last parameter is always false
	g_PluginInfo->CheatAddResource(playerData, SHIPMENTS, 10000.00, false);
}

// Spawn 50 cannons
void CHEATCALL KillemAll(void * playerData) {
	for (int i = 0; i < 50; i++)
		g_PluginInfo->CheatSpawnUnit(playerData, "Cannon");
}

// Gets a random location on the circle
// vector return syscall use first parameter to hold vector data
vector rmGetLocationByDistance(vector result, vector center, float distance) {
	float radians = rmRandFloat(0, 2 * 3.1415926);

	result->x = center->x + distance * cosf(radians);
	result->y = center->y;
	result->z = center->z + distance * sinf(radians);

	// always return the first parameter (result vector)
	return result;
}

float g_DefaultParamFloat = 0.0;
int g_InvalidUnitID = -1;

extern "C" _declspec(dllexport)
int UHCPluginMain(UHCPluginInfo* pluginInfo) {
	g_PluginInfo = pluginInfo;

	// Register your syscalls and cheats here...

	// First parameter used to hold the return vector doesn't count as syscall parameter
	UHCSyscall& sRmGetLocationByDistance = pluginInfo->RegisterSyscall(GroupRM, SyscallVector, "rmGetLocationByDistance", rmGetLocationByDistance, 2, "rmGetLocationByDistance: no help.");
	
	pluginInfo->SyscallSetParam(sRmGetLocationByDistance, 0, SyscallVector, cInvalidVector);

	// Default param value must be stored globally, not on the function stack
	pluginInfo->SyscallSetParam(sRmGetLocationByDistance, 1, SyscallFloat, &g_DefaultParamFloat);

	// Some syscalls might work if re-registered in a different scope
	UHCSyscall& sKbUnitGetTactic = pluginInfo->RegisterSyscall(GroupKB, SyscallInteger, "kbUnitGetTactic", aiUnitGetTactic, 1, "kbUnitGetTactic: no help.");

	pluginInfo->SyscallSetParam(sKbUnitGetTactic, 0, SyscallInteger, &g_InvalidUnitID);

	// Second parameter is always true
	pluginInfo->RegisterCheat("force of nature", TRUE, ForceOfNature);

	pluginInfo->RegisterCheat("this is a complication", TRUE, ThisIsAComplication);

	pluginInfo->RegisterCheat("kill 'em all", TRUE, KillemAll);

	return 0;
}


