#include "Utilities.h"

int UHCStr2Int(LPCSTR lpStr) {
	int result = 0;
	int stop = 0;
	if (lpStr) {
		for (int i = 0; i < lstrlenA(lpStr) && !stop; ++i) {
			if (lpStr[i] >= 48 &&
				lpStr[i] <= 57) {
				int t = lpStr[i] - 48;
				for (int j = i; j < lstrlenA(lpStr) - 1; ++j)
					t *= 10;
				result += t;
			}
			else {
				result = -1;
				stop = 1;
			}
		}
	}
	else
		result = -1;

	return result;
}

extern "C" _declspec(dllexport)
WCHAR* UHCAnsiStrToWideStr(HANDLE hHeap, CHAR* lpStr) {

	int lenght = lstrlenA(lpStr);

	if (lenght) {
		WCHAR* wideStr = (WCHAR*) HeapAlloc(hHeap, HEAP_ZERO_MEMORY, (++lenght) * 2);

		for (int i = 0; i < lenght; i++)
			wideStr[i] = (WCHAR)lpStr[i];

		return wideStr;
	}

	return NULL;
}