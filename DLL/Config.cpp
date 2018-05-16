#include "stdafx.h"
#include "Config.h"

Config::Config() {}

Config::~Config() {
	Cleanup();
}

BOOL Config::Parse(LPCWSTR lpConfigName) {
	HANDLE hFile = NULL;
	DWORD dwFileSize = INVALID_FILE_SIZE, dwBytes,
		dwStringIndex = 0, dwStringBegin = 0, dwLength = 0;
	LPSTR lpBuffer = NULL;
	ConfigKey* key = NULL;
	BOOL result = TRUE;
	BOOL hasEquals = FALSE;

	hFile = CreateFileW(lpConfigName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		WCHAR lpStr[256];
		wsprintfW(lpStr, L"Failed to open '%s'!", lpConfigName);
		OutputDebugStringW(lpStr);
		goto BAD_RET;
	}

	dwFileSize = GetFileSize(hFile, NULL);

	if (dwFileSize == INVALID_FILE_SIZE) {
		WCHAR lpStr[256];
		wsprintfW(lpStr, L"Failed to open '%s'!", lpConfigName);
		OutputDebugStringW(lpStr);
		goto BAD_RET;
	}

	lpBuffer = new CHAR[dwFileSize + 1];

	if (!lpBuffer)
		goto BAD_RET;

	if (!ReadFile(hFile, lpBuffer, dwFileSize, &dwBytes, NULL) ||
		dwBytes != dwFileSize) {
		WCHAR lpStr[256];
		wsprintfW(lpStr, L"Failed to read '%s'!", lpConfigName);
		OutputDebugStringW(lpStr);
		goto BAD_RET;
	}

	lpBuffer[dwFileSize++] = '\0';

	for (DWORD i = 0; i < dwFileSize; ++i) {
		switch (lpBuffer[i])
		{
		case '/':
		case ' ':
		case '\t':
		case '\r':
		case '\n':
		case '\0':
			if (lpBuffer[i] == '/') {
				if (i + 1 < dwFileSize && lpBuffer[i + 1] == '/') {
					while (i < dwFileSize) {
						if (lpBuffer[i] == '\r' || lpBuffer[i] == '\n')
							break;
						i++;
					}
				}
				else
					goto BAD_RET;
			}

			// read the rest line as value if '=' found
			if (hasEquals && lpBuffer[i] == ' ' || lpBuffer[i] == '\t') {
				dwLength++;
				continue;
			}

			if (dwLength > 0) {
				LPSTR lpString = new CHAR[dwLength + 1];
				DWORD s;

				if (dwStringIndex == 0) {
					for (s = 0; s < dwLength; ++s) {
						if (lpBuffer[dwStringBegin + s] == '=') {
							hasEquals = TRUE;
							break;
						}
						lpString[s] = lpBuffer[dwStringBegin + s];
					}
					lpString[s] = 0;

					key = &m_Keys.InsertEmptyBack();
					key->Name = lpString;
				}
				else {
					for (s = 0; s < dwLength; ++s)
						lpString[s] = lpBuffer[dwStringBegin + s];
					lpString[s] = 0;

					key->Values.PushBack(lpString);
				}

				dwLength = 0;

				if (hasEquals && dwStringIndex == 0)
					i = dwStringBegin + s;

				dwStringIndex++;
			}

			switch (lpBuffer[i])
			{
			case '\r':
			case '\n':
				dwStringIndex = 0;
				hasEquals = FALSE;
			}

			dwStringBegin = i + 1;
			break;
		default:
			dwLength++;
		}
	}

	goto RET;

BAD_RET:
	result = FALSE;
	Cleanup();
RET:
	delete[] lpBuffer;
	if (hFile)
		CloseHandle(hFile);

	return result;
}

void Config::Cleanup() {
	for (size_t i = 0; i < m_Keys.GetNumElements(); ++i) {
		if (m_Keys[i].Name)
			delete[] m_Keys[i].Name;

		for (size_t v = 0; v < m_Keys[i].Values.GetNumElements(); ++v) {
			if (m_Keys[i].Values[v])
				delete[] m_Keys[i].Values[v];
		}
	}
}
