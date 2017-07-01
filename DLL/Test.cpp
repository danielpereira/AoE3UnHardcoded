#include "Test.h"
#include "syscalls.h"
#include "UHC.h"
#include <unordered_map>

using namespace syscalls;

void __stdcall CheatForceOfNature(void* playerData) {
	xsSetContextPlayer(1);

	std::unordered_map<std::wstring, int> unitTypeMap;
	
	for (int i = 0; i < GetUnitTypes()->Count; i++)
		unitTypeMap.insert(std::pair<std::wstring, int>(std::wstring(GetUnitTypes()->Array[i]), i));

	for (int i = 1; i < GetNumberPlayers(); i++) {
		if (kbIsPlayerEnemy(i) && !kbIsPlayerResigned(i)) {
			int unitQueryID, unitQuery2ID;
			int numberFound;

			xsSetContextPlayer(i);
			trUnitSelectClear();
			
			unitQueryID = kbUnitQueryCreate("CheatUnitQuery");
			kbUnitQuerySetIgnoreKnockedOutUnits(unitQueryID, true);
			kbUnitQuerySetPlayerID(unitQueryID, i, true);
			kbUnitQuerySetUnitType(unitQueryID, unitTypeMap[L"Unit"]);
			kbUnitQuerySetState(unitQueryID, cUnitStateAlive);
			kbUnitQueryResetResults(unitQueryID);

			xsSetContextPlayer(1);

			unitQuery2ID = kbUnitQueryCreate("CheatUnitQuery2");
			kbUnitQuerySetIgnoreKnockedOutUnits(unitQuery2ID, true);
			kbUnitQuerySetPlayerID(unitQuery2ID, 1, true);
			kbUnitQuerySetUnitType(unitQuery2ID, unitTypeMap[L"Unit"]);
			kbUnitQuerySetState(unitQuery2ID, cUnitStateAlive);
			kbUnitQueryResetResults(unitQuery2ID);

			numberFound = kbUnitQueryExecute(unitQuery2ID);

			for (int n = 0; n < numberFound; n++) {
				int unitID = kbUnitQueryGetResult(unitQuery2ID, n);
				trUnitSelectByID(unitID);
			}

			xsSetContextPlayer(i);
			trUnitConvert(i);

			numberFound = kbUnitQueryExecute(unitQueryID);

			for (int n = 0; n < numberFound; n++) {
				int unitID = kbUnitQueryGetResult(unitQueryID, n);
				trUnitSelectByID(unitID);
			}
			
			xsSetContextPlayer(1);
			trUnitConvert(1);

			// building
			xsSetContextPlayer(i);
			trUnitSelectClear();

			kbUnitQuerySetPlayerID(unitQueryID, i, true);
			kbUnitQuerySetUnitType(unitQueryID, unitTypeMap[L"Building"]);
			kbUnitQuerySetState(unitQueryID, cUnitStateAlive);
			kbUnitQueryResetResults(unitQueryID);

			xsSetContextPlayer(1);

			kbUnitQuerySetPlayerID(unitQuery2ID, 1, true);
			kbUnitQuerySetUnitType(unitQuery2ID, unitTypeMap[L"Building"]);
			kbUnitQuerySetState(unitQuery2ID, cUnitStateAlive);
			kbUnitQueryResetResults(unitQuery2ID);

			numberFound = kbUnitQueryExecute(unitQuery2ID);

			for (int n = 0; n < numberFound; n++) {
				int unitID = kbUnitQueryGetResult(unitQuery2ID, n);
				trUnitSelectByID(unitID);
			}

			xsSetContextPlayer(i);
			trUnitConvert(i);

			numberFound = kbUnitQueryExecute(unitQueryID);

			for (int n = 0; n < numberFound; n++) {
				int unitID = kbUnitQueryGetResult(unitQueryID, n);
				trUnitSelectByID(unitID);
			}

			kbUnitQueryDestroy(unitQueryID);
			kbUnitQueryDestroy(unitQuery2ID);

			break;
		}
	}
}

void TestInit() {
	UHCRegisterCheat(UHCInfo::Instance, L"who am i", TRUE, CheatForceOfNature);
}