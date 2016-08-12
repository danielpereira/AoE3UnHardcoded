#include "Config.h"
#include "Utilities.h"

#define TABLE_COUNT 3

struct UHCInfo {
	DWORD TableCount;
	struct UHCRefTable {
		DWORD RefCount;
		LPVOID *Refs;
        DWORD *RefIDs;
	} *Tables;
	int BasePop;
    int ExtraPop;
};

extern "C" _declspec(dllexport)
UHCInfo* UHCInitInfo(LPWSTR lpConfigName, HANDLE hHeap) {
	Config uConfig;
	UHCInfo *info = NULL;
	static LPCSTR uTableNames[TABLE_COUNT] = {
		"FarmAnim:",
		"RectFarmAnim:",
        "MarketUnits:"
	};

	if (UHCParseConfig(&uConfig, lpConfigName, hHeap)) {
		info = (UHCInfo*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, sizeof(UHCInfo));

		if (info) {
			info->TableCount = TABLE_COUNT;
			info->Tables = (UHCInfo::UHCRefTable*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, sizeof(UHCInfo::UHCRefTable) * TABLE_COUNT);
			if (info->Tables) {
				info->BasePop = 200;

				for (DWORD i = 0; i < uConfig.KeyCount; ++i) {
					BOOL found = FALSE;

					for (DWORD t = 0; t < TABLE_COUNT; ++t) {
						if (lstrcmpA(uConfig.Keys[i].Name, uTableNames[t]) == 0) {
							if (info->Tables[t].Refs) {
								for (DWORD r = 0; r < info->Tables[t].RefCount; ++r)
									HeapFree(hHeap, 0, info->Tables[t].Refs[r]);
								HeapFree(hHeap, 0, info->Tables[t].Refs);
							}
                            
                            if (info->Tables[t].RefIDs)
                                HeapFree(hHeap, 0, info->Tables[t].RefIDs);

							info->Tables[t].RefCount = uConfig.Keys[i].ValueCount;
							info->Tables[t].Refs = (LPVOID*)uConfig.Keys[i].Values;
                            info->Tables[t].RefIDs = (DWORD*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, sizeof(DWORD)*(info->Tables[t].RefCount));

							found = TRUE;
							break;
						}
					}

					if (!found) {
						if (lstrcmpA(uConfig.Keys[i].Name, "BasePop:") == 0) {
							if (uConfig.Keys[i].ValueCount == 1) {
								info->BasePop = UHCStr2Int(uConfig.Keys[i].Values[0]);
								if (info->BasePop < 0)
									info->BasePop = 200;
							}
						}
                        else if (lstrcmpA(uConfig.Keys[i].Name, "ExtraPop:") == 0) {
                            if (uConfig.Keys[i].ValueCount == 1) {
                                info->ExtraPop = UHCStr2Int(uConfig.Keys[i].Values[0]);
                                if (info->ExtraPop < 0)
                                    info->ExtraPop = 50;
                            }
                        }

						for (DWORD v = 0; v < uConfig.Keys[i].ValueCount; ++v)
							HeapFree(hHeap, 0, uConfig.Keys[i].Values[v]);
						HeapFree(hHeap, 0, uConfig.Keys[i].Values);
					}

					HeapFree(hHeap, 0, uConfig.Keys[i].Name);
				}
			}
			else {
				HeapFree(hHeap, 0, info);
				info = NULL;
			}
		}
	}

	return info;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved){
	return TRUE;
}