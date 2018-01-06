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

	if (!hFile) {
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

void Config::ProcessData(DWORD* dwSettings) {
	LPSTR conversionTable[9][2] = { {"AsianCivs:", "asianCivs"}, {"BasePop:", "basePop"}, {"BigButtonCivs:", "bigButtonCivs"}, {"ExtraPop:", "extraPop"}, {"FarmAnim:", "enableFarmAnim"}, {"MarketUnits:", "marketUnits"}, {"NativeCivs:", "nativeCivs"}, {"NotBigButtonBlds:", "noBigButtonBlds"}, {"RectFarmAnim:", "enableRectFarmAnim"}};

	for (size_t i = 0; i < m_Keys.GetNumElements(); i++) {
		for (int j = 0, detected = 0; j < 9 && !detected; j++) {
			if (!lstrcmpiA(m_Keys[i].Name, conversionTable[j][0])) {
				delete[] m_Keys[i].Name;
				m_Keys[i].Name = new char[lstrlenA(conversionTable[j][1]) + 1];
				lstrcpyA(m_Keys[i].Name, conversionTable[j][1]);
				detected = 1;
			}
		}

	}
}

BOOL Config::WriteToFile(LPCWSTR lpConfigFileName, DWORD dwSettings) {
	HANDLE cfgFile = CreateFile(lpConfigFileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD bytesWritten;

	if (cfgFile != INVALID_HANDLE_VALUE) {
		LPSTR settingTable[6] = { "noAILimit", "customRevolutionBanners", "ignoreRegistryPath", "enableAllTeams", "removeFameRestriction", "removeConversionRestriction" };
		LPSTR otherSettings[2] = { "customCheats", "customSyscalls" };
		LPSTR valueTable[3] = { "basePop", "extraPop", "deckCardCount" };

		for (int i = 0; i < 6; i++) {
			if (dwSettings & (1 << i)) {
				WriteFile(cfgFile, settingTable[i], lstrlenA(settingTable[i]), &bytesWritten, NULL);
				WriteFile(cfgFile, "\r\n", 2, &bytesWritten, NULL);
			}
		}

		for (size_t i = 0; i < m_Keys.GetNumElements(); i++) {
			BOOL isSettingString = FALSE;
			BOOL isHiddenSettingString = FALSE;
			BOOL isValueString = FALSE;

			for (int j = 0, detected = 0; j < 6 && !detected; j++) {
				if (!lstrcmpiA(settingTable[j], m_Keys[i].Name)) {
					isSettingString = TRUE;
					detected = 1;
				}
			}

			if (!isSettingString) {
				if (m_Keys[i].Values.GetNumElements() > 0) {
					for (int j = 0, detected = 0; j < 3; j++) {
						if (!lstrcmpiA(valueTable[j], m_Keys[i].Name)) {
							isValueString = TRUE;
							detected = 1;
						}
					}

					WriteFile(cfgFile, m_Keys[i].Name, lstrlenA(m_Keys[i].Name), &bytesWritten, NULL);

					if (isValueString) {
						WriteFile(cfgFile, "=", 1, &bytesWritten, NULL);
						WriteFile(cfgFile, m_Keys[i].Values[0], lstrlenA(m_Keys[i].Values[0]), &bytesWritten, NULL);
						WriteFile(cfgFile, "\r\n", 2, &bytesWritten, NULL);
					}
					else {
						for (size_t j = 0; j < m_Keys[i].Values.GetNumElements(); j++) {
							WriteFile(cfgFile, " ", 1, &bytesWritten, NULL);
							WriteFile(cfgFile, m_Keys[i].Values[j], lstrlenA(m_Keys[i].Values[j]), &bytesWritten, NULL);
						}
						WriteFile(cfgFile, "\r\n", 2, &bytesWritten, NULL);
					}
				}
				else {
					for (int j = 0, detected = 0; j < 2 && !detected; j++) {
						if (!lstrcmpiA(otherSettings[j], m_Keys[i].Name)) {
							isHiddenSettingString = TRUE;
							detected = 1;
						}
					}

					if (isHiddenSettingString) {
						WriteFile(cfgFile, m_Keys[i].Name, lstrlenA(m_Keys[i].Name), &bytesWritten, NULL);
						WriteFile(cfgFile, "\r\n", 2, &bytesWritten, NULL);
					}
				}
			}
		}

		CloseHandle(cfgFile);
		return TRUE;
	}

	return FALSE;
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