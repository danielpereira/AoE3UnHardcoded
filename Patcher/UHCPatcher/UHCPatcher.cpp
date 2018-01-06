// UHCPatcher.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "UHCPatcher.h"
#include <ImageHlp.h>

#pragma comment(lib, "imagehlp.lib")

#define MAX_LOADSTRING 100

#define UHC_NAME L"UHC Patcher"
#define UHC_RESNAME L"BIN"
#define UHC_LIB_NAME L"UHC.DLL"
#define UHC_HEADER 0x31434855
#define UHC2_HEADER 0x32434855

#define CFG_PATH_MAX 21

// Global Variables:
WCHAR exePath[MAX_PATH];
WCHAR exeBackupPath[MAX_PATH] = L"";
BOOL backupExists = FALSE;
WCHAR cfgFileRelPath[CFG_PATH_MAX] = L"Startup\\uhc.cfg";
DWORD patchSettings = 0;

typedef enum UHC_PATCH_RESULT {
	UHC_PATCH_NONE,
	UHC_PATCH_FAILED,
	UHC_PATCH_SUCCESS
} UHC_PATCH_RESULT;

BOOL UHCPatch(HANDLE hFile, HANDLE hPatchFile) {
	static HANDLE hHeap = GetProcessHeap();
	DWORD dwBytes;

	DWORD dwHeader;
	ReadFile(hPatchFile, &dwHeader, 4, &dwBytes, NULL);

	if (dwHeader != UHC_HEADER) {
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

UHC_PATCH_RESULT PatchExecutable(HWND hwndDlg) {
	if (!backupExists && !(CopyFileW(exePath, exeBackupPath, FALSE))) {
		if (MessageBoxW(hwndDlg, L"The patcher has failed to backup the current executable.\nContinue patching anyway?", L"Error", MB_ICONWARNING | MB_YESNO) != IDYES) {
			return UHC_PATCH_NONE;
		}
	}
	else
		backupExists = TRUE;

	WCHAR dirBuffer[MAX_PATH];
	WCHAR tmpFile[MAX_PATH];

	GetTempPath(MAX_PATH, dirBuffer);
	GetTempFileNameW(dirBuffer, L"UHC", 0, tmpFile);
	HANDLE hTmpPatchFile = CreateFileW(tmpFile, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	HRSRC resHandle = FindResource(NULL, MAKEINTRESOURCE(IDR_PATCH), UHC_RESNAME);
	HGLOBAL resData = LoadResource(NULL, resHandle);
	DWORD resSize = SizeofResource(NULL, resHandle);

	DWORD bytesWritten = 0;
	WriteFile(hTmpPatchFile, resData, resSize, &bytesWritten, NULL);

	HANDLE hExeFile = CreateFileW(exePath, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hExeFile == INVALID_HANDLE_VALUE) {
		MessageBoxW(hwndDlg, L"Failed to open the supplied executable file.", L"Error", MB_ICONERROR | MB_OK);
		CloseHandle(hTmpPatchFile);
		DeleteFileW(tmpFile);
		return UHC_PATCH_NONE;
	}

	ImageRemoveCertificate(hExeFile, 0);

	SetFilePointer(hTmpPatchFile, 0, NULL, FILE_BEGIN);

	if (!UHCPatch(hExeFile, hTmpPatchFile)) {
		CloseHandle(hExeFile);
		CloseHandle(hTmpPatchFile);
		DeleteFileW(tmpFile);
		return UHC_PATCH_FAILED;
	}

	if (SetFilePointer(hExeFile, 0x00865083, NULL, FILE_BEGIN) != INVALID_SET_FILE_POINTER)
		WriteFile(hExeFile, cfgFileRelPath, (lstrlen(cfgFileRelPath) + 1) * 2, &bytesWritten, NULL);

	CloseHandle(hExeFile);
	CloseHandle(hTmpPatchFile);
	DeleteFileW(tmpFile);

	Config* cfgFile = new Config;

	lstrcpyW(dirBuffer, exePath);

	int lastSlashIndex = lstrrchrW(dirBuffer, '\\');
	dirBuffer[lastSlashIndex + 1] = '\0';
	lstrcatW(dirBuffer, cfgFileRelPath);

	int parentDirSlashIndex = lstrrchrW(dirBuffer, '\\');
	dirBuffer[parentDirSlashIndex] = '\0';

	CreateDirectoryW(dirBuffer, NULL);

	dirBuffer[parentDirSlashIndex] = '\\';

	cfgFile->Parse(dirBuffer);
	cfgFile->ProcessData(&patchSettings);

	if (!cfgFile->WriteToFile(dirBuffer, patchSettings))
		MessageBoxW(hwndDlg, L"The patcher has failed to write to the supplied configuration file\n\nIn order to apply the intended patch settings,\n you will have to edit it manually.\n\nRefer to the official UHC Configuration File documentation for more information.", UHC_NAME, MB_ICONINFORMATION | MB_OK);

	delete cfgFile;

	dirBuffer[lastSlashIndex + 1] = '\0';
	lstrcatW(dirBuffer, UHC_LIB_NAME);

	HANDLE hLib = CreateFileW(dirBuffer, (GENERIC_READ | GENERIC_WRITE), FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	resHandle = FindResource(NULL, MAKEINTRESOURCE(IDR_UHC), UHC_RESNAME);
	resData = LoadResource(NULL, resHandle);
	resSize = SizeofResource(NULL, resHandle);

	if (!(WriteFile(hLib, resData, resSize, &bytesWritten, NULL) && (bytesWritten == resSize))) {
		MessageBoxW(hwndDlg, L"The patcher has failed to place the main DLL at the path of the supplied executable.\nYou'll have to manually download it and place it.", UHC_NAME, MB_ICONERROR | MB_OK);
	}
	else
		CloseHandle(hLib);

	return UHC_PATCH_SUCCESS;
}

BOOL ReadCFGPathFromExe(WCHAR* cfgFilePath) {
	WCHAR tmpCfgPath[CFG_PATH_MAX];
	DWORD bytesRead;

	HANDLE exeHandle = CreateFile(exePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (exeHandle != INVALID_HANDLE_VALUE) {
		size_t pcch;

		if (SetFilePointer(exeHandle, 0x00865083, NULL, FILE_BEGIN) != INVALID_SET_FILE_POINTER) {
			ReadFile(exeHandle, tmpCfgPath, CFG_PATH_MAX * 2, &bytesRead, NULL);

			if (StringCchLength(tmpCfgPath, CFG_PATH_MAX, &pcch) && pcch) {
				lstrcpy(cfgFilePath, tmpCfgPath);
				CloseHandle(exeHandle);
				return TRUE;
			}
			else {
				if (SetFilePointer(exeHandle, 0x008AA0B0, NULL, FILE_BEGIN) != INVALID_SET_FILE_POINTER) {
					ReadFile(exeHandle, tmpCfgPath, CFG_PATH_MAX * 2, &bytesRead, NULL);

					if (StringCchLength(tmpCfgPath, CFG_PATH_MAX, &pcch) && pcch) {
						lstrcpy(cfgFilePath, tmpCfgPath);
						CloseHandle(exeHandle);
						return TRUE;
					}
				}
			}
		}

		CloseHandle(exeHandle);
	}

	return FALSE;
}

BOOL IsAValidExecutable(WCHAR* lpExePath, BOOL* backupExists) {
	DWORD dwAttr = GetFileAttributesW(lpExePath);

	if (dwAttr != INVALID_FILE_ATTRIBUTES && !(dwAttr & FILE_ATTRIBUTE_DIRECTORY)) {
		for (int i = lstrlenW(lpExePath) - 1; i >= 0; --i) {
			if (lpExePath[i] == '.') {
				if (!lstrcmpiW(&lpExePath[i], L".exe")) {
					HANDLE exeHandle = CreateFileW(lpExePath, 0, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
					DWORD executableSize = GetFileSize(exeHandle, NULL);
					CloseHandle(exeHandle);

					if (executableSize != 11598648 && executableSize != 11591680) {
						if (!(MessageBox(NULL, L"The supplied executable doesn't seem to be a valid AoE3 TAD executable\nDo you want to proceed with patching this file, anyway?", UHC_NAME, MB_ICONQUESTION | MB_YESNO) == IDYES))
							return FALSE;
					}
					
					lstrcpy(exeBackupPath, lpExePath);
					exeBackupPath[i] = '\0';
					lstrcatW(exeBackupPath, L".backupuhc");

					DWORD dwAttrBackup = GetFileAttributesW(exeBackupPath);

					(*backupExists) = (dwAttrBackup != INVALID_FILE_ATTRIBUTES && !(dwAttrBackup & FILE_ATTRIBUTE_DIRECTORY)) ? TRUE : FALSE;

					return TRUE;

				}
				else {
					MessageBox(NULL, L"The supplied file is not a valid executable file.", L"Error", MB_ICONERROR | MB_OK);
					return FALSE;
				}
			}
		}
	}

	MessageBox(NULL, L"The supplied file is not a valid executable file.", L"Error", MB_ICONERROR | MB_OK);
	return FALSE;
}

BOOL SelectExecutableFile(HWND parentWnd, LPWSTR fileName, BOOL* backupExists) {
	bool fileChosen = FALSE;
	OPENFILENAME ofn;

	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = parentWnd;
	ofn.lpstrFile = fileName;
	fileName[0] = '\0';
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = L"Executable files\0*.EXE\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;

	while (!fileChosen) {
		if (GetOpenFileName(&ofn)) {
			if (IsAValidExecutable(ofn.lpstrFile, backupExists)) {
				fileChosen = TRUE;
				return TRUE;
			}
			else {
				fileName[0] = '\0';
			}
		}
		else {
			fileChosen = TRUE;
		}
	}

	return FALSE;
}

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_INITDIALOG: {
			SendDlgItemMessage(hwndDlg, IDC_CFGNAME, EM_SETLIMITTEXT, 20, NULL);

			if ((BOOL)lParam && IsAValidExecutable(exePath, &backupExists)) {
				SetDlgItemText(hwndDlg, IDC_EXEPATH, exePath);
				EnableWindow(GetDlgItem(hwndDlg, IDC_APPLY), TRUE);
				ReadCFGPathFromExe(cfgFileRelPath);

				if (backupExists)
					EnableWindow(GetDlgItem(hwndDlg, IDC_RESTORE), TRUE);
			}

			SetDlgItemText(hwndDlg, IDC_CFGNAME, cfgFileRelPath);


			return TRUE;
		}
		case WM_CLOSE:
			EndDialog(hwndDlg, 0);
			break;
		case WM_COMMAND:
			switch (LOWORD(wParam)) {
				case IDC_OPEN: {
					WCHAR tmpFileName[MAX_PATH];

					if (SelectExecutableFile(hwndDlg, tmpFileName, &backupExists)) {
						lstrcpy(exePath, tmpFileName);
						SetDlgItemText(hwndDlg, IDC_EXEPATH, exePath);
						EnableWindow(GetDlgItem(hwndDlg, IDC_APPLY), TRUE);

						if (ReadCFGPathFromExe(cfgFileRelPath))
							SetDlgItemText(hwndDlg, IDC_CFGNAME, cfgFileRelPath);

						if (backupExists)
							EnableWindow(GetDlgItem(hwndDlg, IDC_RESTORE), TRUE);
						else
							EnableWindow(GetDlgItem(hwndDlg, IDC_RESTORE), FALSE);
					}
					break;
				}
				case IDC_APPLY: {
					GetDlgItemTextW(hwndDlg, IDC_CFGNAME, cfgFileRelPath, 21);

					DWORD patchResult = PatchExecutable(hwndDlg);

					switch (patchResult) {
						case UHC_PATCH_NONE:
							MessageBoxW(hwndDlg, L"No patches have been applied to the EXE.", UHC_NAME, MB_ICONINFORMATION | MB_OK);
							break;
						case UHC_PATCH_FAILED:
							if (CopyFileW(exeBackupPath, exePath, FALSE) && DeleteFileW(exeBackupPath))
								MessageBoxW(hwndDlg, L"An error occurred while attempting to patch the EXE file\nThe original EXE file has been restored.", UHC_NAME, MB_ICONERROR | MB_OK);
							else
								MessageBoxW(hwndDlg, L"An error occurred while attempting to patch the EXE file\nThe patcher also could not restore the original EXE file.", UHC_NAME, MB_ICONERROR | MB_OK);
							break;
						case UHC_PATCH_SUCCESS:
							MessageBoxW(GetActiveWindow(), L"The EXE has been sucessfully patched!", UHC_NAME, MB_ICONINFORMATION | MB_OK);
					}

					if (backupExists)
						EnableWindow(GetDlgItem(hwndDlg, IDC_RESTORE), TRUE);

					break;

				}
				case IDC_RESTORE: {
					if (CopyFileW(exeBackupPath, exePath, FALSE) && DeleteFileW(exeBackupPath)) {
						MessageBoxW(hwndDlg, L"Backup sucessfully restored.", UHC_NAME, MB_ICONINFORMATION | MB_OK);
						backupExists = false;
						EnableWindow(GetDlgItem(hwndDlg, IDC_RESTORE), FALSE);
					}
					else
						MessageBoxW(hwndDlg, L"An error occurred while attempting to restore the backup of the selected executable.", UHC_NAME, MB_ICONERROR | MB_OK);
					break;
				}
				case IDC_AILIMIT:
				case IDC_REVBANNERS:
				case IDC_IGNOREREG:
				case IDC_TEAMLIMIT: 
				case IDC_FAME_RESTRICTION: 
				case IDC_CONV_RESTRICTION: {
					int chkBoxID = LOWORD(wParam);

					if (IsDlgButtonChecked(hwndDlg, chkBoxID))
						patchSettings |= ((DWORD) 1 << (DWORD) (chkBoxID - 1100));
					else
						patchSettings &= ~((DWORD) 1 << (DWORD) (chkBoxID - 1100));

					int aux = 1;

					break;
				}

			}
			break;
		default:
			return FALSE;
	}

	return TRUE;
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	LPWSTR *lpArgs;
	int argCount;
	BOOL exePathInitialized = FALSE;

	lpArgs = CommandLineToArgvW(GetCommandLineW(), &argCount);

	for (int i = 1; i < argCount; i++) {
		switch (i) {
		case 1:
			lstrcpy(exePath, lpArgs[i]);
			exePathInitialized = TRUE;
			break;
		case 2:
			if (lstrlenW(lpArgs[i]) <= 20)
				lstrcpyW(cfgFileRelPath, lpArgs[i]);
			break;
		}
	}

	if (!exePathInitialized) {
		WCHAR relativeExePath[MAX_PATH];

		GetModuleFileNameW(NULL, relativeExePath, MAX_PATH);

		for (int i = lstrlenW(relativeExePath) - 1, stop = 0; i >= 0 && !stop; i--) {
			if (relativeExePath[i] == '\\') {
				relativeExePath[i] = '\0';
				stop = 1;
			}
 		}

		lstrcatW(relativeExePath, L"\\age3y.exe");

		DWORD dwAttr = GetFileAttributesW(relativeExePath);

		if ((dwAttr != INVALID_FILE_ATTRIBUTES) && !(dwAttr & FILE_ATTRIBUTE_DIRECTORY)) {
			lstrcpy(exePath, relativeExePath);
			exePathInitialized = true;
		}
	}

	DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_MAIN), NULL, DialogProc, exePathInitialized);

	return 0;
}