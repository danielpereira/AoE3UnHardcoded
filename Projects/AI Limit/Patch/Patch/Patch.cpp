// Patch.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Patch.h"

PATCH_API void GetPersonalityNames(int* pCount, LPWSTR** pNames, LPCWSTR pszDir)
{
	WCHAR szModuleFileName[MAX_PATH], szSearchPath[MAX_PATH];
	HANDLE hHeap, hFind;
	WIN32_FIND_DATAW fd;
	size_t length;

	*pCount = 0;
	*pNames = NULL;

	hHeap = HeapCreate(0, 0, 0);

	GetModuleFileNameW(NULL, szModuleFileName, MAX_PATH);
	PathRemoveFileSpecW(szModuleFileName);

	PathCombineW(szSearchPath, szModuleFileName, pszDir);
	lstrcatW(szSearchPath, L"*.personality");

	hFind = FindFirstFileW(szSearchPath, &fd);
	if (hFind == INVALID_HANDLE_VALUE)
		return;

	do
	{
		if (*pNames == NULL)
			*pNames = (LPWSTR*)HeapAlloc(hHeap, 0, sizeof(LPWSTR));
		else
			*pNames = (LPWSTR*)HeapReAlloc(hHeap, 0, *pNames, *pCount * sizeof(LPWSTR) + sizeof(LPWSTR));

		PathRemoveExtensionW(fd.cFileName);
		length = lstrlenW(fd.cFileName) + 1;
		(*pNames)[*pCount] = (LPWSTR)HeapAlloc(hHeap, 0, length * sizeof(WCHAR));
		lstrcpyW((*pNames)[*pCount], fd.cFileName);

		(*pCount)++;
	} while (FindNextFileW(hFind, &fd) != FALSE);

	FindClose(hFind);
}
