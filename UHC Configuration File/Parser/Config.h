#include <Windows.h>

struct Config {
	DWORD KeyCount;
	struct Key {
		LPSTR Name;
		DWORD ValueCount;
		LPSTR *Values;
	} *Keys;
};

BOOL UHCParseConfig(Config *pConfig, LPWSTR lpConfigName, HANDLE hHeap);