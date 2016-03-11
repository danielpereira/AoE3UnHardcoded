#include <Windows.h>
// Patch files must be named as the patch name
// They will be read from the same directory of this EXE
// File Specs (.uhc)
// header (4 bytes) UHC_HEADER
// data count (4 bytes)
// data 0 offset (4 bytes)
// data 0 length (4 bytes)
// data 0 [bytes]
// data 1...
// ...

#define UHC_HEADER 0x31434855 

BOOL UHCPatch(HANDLE hFile, HANDLE hPatchFile) {
	static HANDLE hHeap = GetProcessHeap();
	DWORD dwBytes;

	DWORD dwHeader;
	ReadFile(hPatchFile, &dwHeader, 4, &dwBytes, NULL);

	if (dwHeader != UHC_HEADER)
		return FALSE;

	DWORD dwDataCount;
	ReadFile(hPatchFile, &dwDataCount, 4, &dwBytes, NULL);

	for (DWORD i = 0; i < dwDataCount; ++i) {
		DWORD dwOffset, dwLength;
		LPSTR lpData;

		ReadFile(hPatchFile, &dwOffset, 4, &dwBytes, NULL);
		ReadFile(hPatchFile, &dwLength, 4, &dwBytes, NULL);

		lpData = (LPSTR)HeapAlloc(hHeap, 0, dwLength);
		ReadFile(hPatchFile, lpData, dwLength, &dwBytes, NULL);

		if (SetFilePointer(hFile, dwOffset, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
			return FALSE;
		WriteFile(hFile, lpData, dwLength, &dwBytes, NULL);

		HeapFree(hHeap, 0, lpData);
	}

	return TRUE;
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {
	int argCount;
	LPWSTR *lpArgs;
	WCHAR lpDirectory[MAX_PATH];
	WCHAR lpFind[MAX_PATH];
	WIN32_FIND_DATAW fd;
	HANDLE hFind;
	HANDLE hFile;

	lpArgs = CommandLineToArgvW(GetCommandLineW(), &argCount);

	if (argCount < 2) {
		MessageBoxW(GetActiveWindow(), L"No target EXE was found.", L"UHC Patcher", MB_ICONERROR | MB_OK);
		return FALSE;
	}

	hFile = CreateFileW(lpArgs[1], GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	GetModuleFileNameW(NULL, lpDirectory, MAX_PATH);
	for (int i = lstrlenW(lpDirectory) - 1; i >= 0; --i) {
		if (lpDirectory[i] == '\\') {
			lpDirectory[i + 1] = 0;
			break;
		}
	}

	lstrcpyW(lpFind, lpDirectory);
	lstrcatW(lpFind, L"*.uhc");
	hFind = FindFirstFileW(lpFind, &fd);

	if (hFind == INVALID_HANDLE_VALUE) {
		MessageBoxW(GetActiveWindow(), L"No patch files have been found found.", L"UHC Patcher", MB_ICONERROR | MB_OK);
		return FALSE;
	}

	do {
		WCHAR lpPatchFilePath[MAX_PATH];
		WCHAR lpMsg[MAX_PATH];
		HANDLE hPatchFile;

		lstrcpyW(lpMsg, L"Apply patch \"");
		lstrcatW(lpMsg, fd.cFileName);

		for (DWORD i = lstrlenW(lpMsg) - 1; i >= 0; --i) {
			if (lpMsg[i] == '.') {
				lpMsg[i] = 0;
				break;
			}
		}

		lstrcatW(lpMsg, L"\"?");
		
		if (MessageBoxW(GetActiveWindow(), lpMsg, L"UHC Patcher", MB_ICONQUESTION | MB_YESNO) != IDYES)
			continue;

		lstrcpyW(lpPatchFilePath, lpDirectory);
		lstrcatW(lpPatchFilePath, fd.cFileName);

		hPatchFile = CreateFileW(lpPatchFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (!UHCPatch(hFile, hPatchFile))
			MessageBoxW(GetActiveWindow(), L"An error occurred while patching the EXE file!", L"UHC Patcher", MB_ICONERROR | MB_OK);	

	} while (FindNextFileW(hFind, &fd));

	FindClose(hFind);

	return EXIT_SUCCESS;
}