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

#define UHC_NAME L"UHC Patcher"
#define UHC_RESNAME "BIN"
#define UHC_LIB_COUNT 2
#define UHC_HEADER 0x31434855
#define UHC2_HEADER 0x32434855

typedef enum UHC_PATCH_RESULT {
	UHC_PATCH_NONE,
	UHC_PATCH_FAILED,
	UHC_PATCH_SUCCESS
} UHC_PATCH_RESULT;

BOOL UHCSaveLibs() {
	static DWORD UHC_LIB_IDS[UHC_LIB_COUNT] = { 202, 203 };
	static LPWSTR UHC_LIB_NAMES[UHC_LIB_COUNT] = { L"uhc_wrapper.dll", L"uhc.dll" };

	for (DWORD i = 0; i < UHC_LIB_COUNT; i++) {
		HANDLE hLib = CreateFileW(UHC_LIB_NAMES[i], (GENERIC_READ | GENERIC_WRITE), FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		
		if (!hLib)
			return FALSE;

		HRSRC resHandle = FindResource(NULL, MAKEINTRESOURCE(UHC_LIB_IDS[i]), UHC_RESNAME);
		HGLOBAL resData = LoadResource(NULL, resHandle);
		DWORD resSize = SizeofResource(NULL, resHandle);

		DWORD bytesWritten = 0;

		if (!(WriteFile(hLib, resData, resSize, &bytesWritten, NULL) && (bytesWritten == resSize)))
			return FALSE;

		CloseHandle(hLib);

	}

	return TRUE;
}

BOOL UHCPatch(HANDLE hFile, HANDLE hPatchFile) {
	static HANDLE hHeap = GetProcessHeap();
	DWORD dwBytes;

	DWORD dwHeader;
	ReadFile(hPatchFile, &dwHeader, 4, &dwBytes, NULL);

	if (dwHeader == UHC2_HEADER) {
		if (!UHCSaveLibs())
			return FALSE;
	}
	else if (dwHeader != UHC_HEADER) {
		return FALSE;
	}

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
	WCHAR lpBackup[MAX_PATH];
	WCHAR lpDirectory[MAX_PATH];
	WCHAR lpFind[MAX_PATH];
	WIN32_FIND_DATAW fd;
	HANDLE hFind;
	HANDLE hFile;
	UHC_PATCH_RESULT patchStatus = UHC_PATCH_NONE;

	lpArgs = CommandLineToArgvW(GetCommandLineW(), &argCount);

	if (argCount < 2) {
		MessageBoxW(GetActiveWindow(), L"Failed to open file\nTarget EXE not found!", UHC_NAME, MB_ICONERROR | MB_OK);
		return FALSE;
	}

	for (DWORD i = lstrlenW(lpArgs[1]) - 1; i >= 0; --i) {
		if (lpArgs[1][i] == '.') {
			if (lstrcmpiW(&lpArgs[1][i], L".exe") != 0) {
				MessageBoxW(GetActiveWindow(), L"Failed to open file\nTarget file is not an EXE", UHC_NAME, MB_ICONERROR | MB_OK);
				return FALSE;
			}

			lstrcpynW(lpBackup, lpArgs[1], &lpArgs[1][i] - lpArgs[1] + 1);
			lstrcatW(lpBackup, L".backupuhc");

			DWORD dwAttr = GetFileAttributesW(lpBackup);

			if (dwAttr != INVALID_FILE_ATTRIBUTES &&
				!(dwAttr & FILE_ATTRIBUTE_DIRECTORY)) {
				if (MessageBoxW(GetActiveWindow(), L"A Patcher backup file for the target EXE has been located\nDo you want to restore it?", UHC_NAME, MB_ICONQUESTION | MB_YESNO) == IDYES) {
					if (CopyFileW(lpBackup, lpArgs[1], FALSE) &&
						DeleteFileW(lpBackup)) {
						MessageBoxW(GetActiveWindow(), L"Backup successfully restored.", UHC_NAME, MB_ICONINFORMATION | MB_OK);
						return TRUE;
					}
					else {
						MessageBoxW(GetActiveWindow(), L"Failed to restore backup!", UHC_NAME, MB_ICONERROR | MB_OK);
						return FALSE;
					}
				}
			}
			else {
				if (!CopyFileW(lpArgs[1], lpBackup, FALSE))
					if (MessageBoxW(GetActiveWindow(), L"Failed to make a backup!\nContinue patching anyway?", UHC_NAME, MB_ICONWARNING | MB_YESNO) != IDYES)
				        return FALSE;
			}

			break;
		}
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
		MessageBoxW(GetActiveWindow(), L"No patch files have been found!", UHC_NAME, MB_ICONERROR | MB_OK);
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

		if (MessageBoxW(GetActiveWindow(), lpMsg, UHC_NAME, MB_ICONQUESTION | MB_YESNO) != IDYES)
			continue;

		lstrcpyW(lpPatchFilePath, lpDirectory);
		lstrcatW(lpPatchFilePath, fd.cFileName);

		hPatchFile = CreateFileW(lpPatchFilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (!UHCPatch(hFile, hPatchFile)) {
			patchStatus = UHC_PATCH_FAILED;
			break;
		}

		CloseHandle(hPatchFile);

		patchStatus = UHC_PATCH_SUCCESS;

	} while (FindNextFileW(hFind, &fd));

	FindClose(hFind);

	CloseHandle(hFile);

	switch (patchStatus) {
	    case UHC_PATCH_NONE:
		    DeleteFileW(lpBackup);
		    MessageBoxW(GetActiveWindow(), L"No patches have been applied to the EXE.", UHC_NAME, MB_ICONINFORMATION | MB_OK);
		    break;
	    case UHC_PATCH_FAILED:
		    if (CopyFileW(lpBackup, lpArgs[1], FALSE) &&
			    DeleteFileW(lpBackup))
			    MessageBoxW(GetActiveWindow(), L"An error occurred while attempting to patch the EXE file\nThe original EXE file has been restored.", UHC_NAME, MB_ICONERROR | MB_OK);
		    else
			    MessageBoxW(GetActiveWindow(), L"An error occurred while attempting to patch the EXE file\n" UHC_NAME L" also could not restore the original EXE file", UHC_NAME, MB_ICONERROR | MB_OK);
		    break;
	    case UHC_PATCH_SUCCESS:
		    MessageBoxW(GetActiveWindow(), L"The EXE has been sucessfully patched!", UHC_NAME, MB_ICONINFORMATION | MB_OK);
	}

	return EXIT_SUCCESS;
}