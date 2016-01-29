// Patch.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Patch.h"

PATCH_API void GetPersonalityNames(int* pCount, LPWSTR** pNames)
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
	PathCombineW(szSearchPath, szModuleFileName, L"AI3\\*.personality");

	// calculate how many personality files we have
	hFind = FindFirstFileW(szSearchPath, &fd);
	if (hFind == INVALID_HANDLE_VALUE)
		return;
	do
	{
		if (FILE_ATTRIBUTE_DIRECTORY & fd.dwFileAttributes)
			continue;

		(*pCount)++;
	} while (FindNextFile(hFind, &fd) != FALSE);
	FindClose(hFind);

	*pNames = (LPWSTR*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, *pCount * sizeof(LPWSTR));
	*pCount = 0;

	hFind = FindFirstFileW(szSearchPath, &fd);
	do
	{
		if (FILE_ATTRIBUTE_DIRECTORY & fd.dwFileAttributes)
			continue;

		PathRemoveExtensionW(fd.cFileName);
		length = lstrlenW(fd.cFileName) + 1;
		(*pNames)[*pCount] = (LPWSTR)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, length * sizeof(WCHAR));
		lstrcpyW((*pNames)[*pCount], fd.cFileName);

		(*pCount)++;
	} while (FindNextFile(hFind, &fd) != FALSE);

	FindClose(hFind);
}