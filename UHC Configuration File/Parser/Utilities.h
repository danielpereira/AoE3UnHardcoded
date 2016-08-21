#include <Windows.h>

int UHCStr2Int(LPCSTR lpStr);

extern "C" _declspec(dllexport)
WCHAR* UHCAnsiStrToWideStr(HANDLE hHeap, CHAR* lpStr);