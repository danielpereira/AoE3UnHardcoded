#include "Test.h"
#include "syscalls.h"
#include "UHC.h"
#include <unordered_map>
#include <ctime>

using namespace syscalls;

void __stdcall CheatForceOfNature(void* playerData) {
	xsSetContextPlayer(1);

	std::unordered_map<std::wstring, int> unitTypeMap;
	
	for (int i = 0; i < GetUnitTypes()->Count; i++)
		unitTypeMap.insert(std::pair<std::wstring, int>(std::wstring(GetUnitTypes()->Array[i]), i));

	int enemies[8];
	int numEnemies = 0;

	for (int i = 1; i < GetNumberPlayers(); i++) {
		if (kbIsPlayerEnemy(i) && !kbIsPlayerResigned(i))
			enemies[numEnemies++] = i;
	}

	srand(time(NULL));

	int me = 1;
	int enemy = enemies[rand() % numEnemies];

	int unitQueryID, unitQueryEnemyID;
	int numberFound;

	xsSetContextPlayer(me);	
	unitQueryID = kbUnitQueryCreate("CheatUnitQuery");
	kbUnitQuerySetIgnoreKnockedOutUnits(unitQueryID, true);
	kbUnitQuerySetPlayerID(unitQueryID, me, true);
	kbUnitQuerySetUnitType(unitQueryID, unitTypeMap[L"Unit"]);
	kbUnitQuerySetState(unitQueryID, cUnitStateAlive);
	kbUnitQueryResetResults(unitQueryID);

	xsSetContextPlayer(enemy);
	unitQueryEnemyID = kbUnitQueryCreate("CheatUnitQueryEnemy");
	kbUnitQuerySetIgnoreKnockedOutUnits(unitQueryEnemyID, true);
	kbUnitQuerySetPlayerID(unitQueryEnemyID, enemy, true);
	kbUnitQuerySetUnitType(unitQueryEnemyID, unitTypeMap[L"Unit"]);
	kbUnitQuerySetState(unitQueryEnemyID, cUnitStateAlive);
	kbUnitQueryResetResults(unitQueryEnemyID);

	trUnitSelectClear();
	xsSetContextPlayer(enemy);
	numberFound = kbUnitQueryExecute(unitQueryEnemyID);
	for (int n = 0; n < numberFound; n++) {
		int unitID = kbUnitQueryGetResult(unitQueryEnemyID, n);
		trUnitSelectByID(unitID);
	}
	xsSetContextPlayer(me);
	trUnitConvert(me);

	trUnitSelectClear();
	xsSetContextPlayer(me);
	numberFound = kbUnitQueryExecute(unitQueryID);
	for (int n = 0; n < numberFound; n++) {
		int unitID = kbUnitQueryGetResult(unitQueryID, n);
		trUnitSelectByID(unitID);
	}
	xsSetContextPlayer(enemy);
	trUnitConvert(enemy);

	// building
	xsSetContextPlayer(me);
	kbUnitQuerySetPlayerID(unitQueryID, me, true);
	kbUnitQuerySetUnitType(unitQueryID, unitTypeMap[L"Building"]);
	kbUnitQuerySetState(unitQueryID, cUnitStateAlive);
	kbUnitQueryResetResults(unitQueryID);

	xsSetContextPlayer(enemy);
	kbUnitQuerySetPlayerID(unitQueryEnemyID, enemy, true);
	kbUnitQuerySetUnitType(unitQueryEnemyID, unitTypeMap[L"Building"]);
	kbUnitQuerySetState(unitQueryEnemyID, cUnitStateAlive);
	kbUnitQueryResetResults(unitQueryEnemyID);

	trUnitSelectClear();
	xsSetContextPlayer(me);
	numberFound = kbUnitQueryExecute(unitQueryEnemyID);
	for (int n = 0; n < numberFound; n++) {
		int unitID = kbUnitQueryGetResult(unitQueryEnemyID, n);
		trUnitSelectByID(unitID);
	}
	trUnitConvert(me);

	trUnitSelectClear();
	xsSetContextPlayer(enemy);
	numberFound = kbUnitQueryExecute(unitQueryID);
	for (int n = 0; n < numberFound; n++) {
		int unitID = kbUnitQueryGetResult(unitQueryID, n);
		trUnitSelectByID(unitID);
	}
	trUnitConvert(enemy);

	kbUnitQueryDestroy(unitQueryID);
	kbUnitQueryDestroy(unitQueryEnemyID);
}

void TestInit() {
	UHCRegisterCheat(UHCInfo::Instance, L"who am i", TRUE, CheatForceOfNature);
}