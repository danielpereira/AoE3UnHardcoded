#include "Config.h"

BOOL UHCParseConfig(Config *pConfig, LPWSTR lpConfigName, HANDLE hHeap)  {
	HANDLE hFile = NULL;
	DWORD dwFileSize = INVALID_FILE_SIZE, dwBytes,
		dwStringIndex = 0, dwStringBegin = 0, dwLength = 0;
	LPSTR lpBuffer = NULL;
	Config::Key key = { NULL, 0, NULL };
	BOOL result = TRUE;

	pConfig->KeyCount = 0;
	pConfig->Keys = NULL;

	hFile = CreateFileW(lpConfigName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (!hFile) {
        OutputDebugStringA("Failed to open file");
		goto BAD_RET;
    }

	dwFileSize = GetFileSize(hFile, NULL);

	if (dwFileSize == INVALID_FILE_SIZE) {
        OutputDebugStringA("Failed to open file");
		goto BAD_RET;
    }

	lpBuffer = (LPSTR)HeapAlloc(hHeap, 0, dwFileSize);

	if (!lpBuffer)
		goto BAD_RET;

	if (!ReadFile(hFile, lpBuffer, dwFileSize, &dwBytes, NULL) ||
		dwBytes != dwFileSize) {
        OutputDebugStringA("Failed to read file");
		goto BAD_RET;
    }

	for (DWORD i = 0; i < dwFileSize; ++i) {

		if (lpBuffer[i] == '/') {
			if (i + 1 < dwFileSize &&
				lpBuffer[i + 1] == '/') {
				while (i < dwFileSize) {
					if (lpBuffer[i] == '\r' || lpBuffer[i] == '\n')
						break;
					++i;
				}
			}
			else
				goto BAD_RET;
		}

		if (lpBuffer[i] == ' ' ||
			lpBuffer[i] == '\t' ||
			lpBuffer[i] == '\r' ||
			lpBuffer[i] == '\n' ||
			lpBuffer[i] == '/' ||
			i + 1 == dwFileSize)
		{
			if (i + 1 == dwFileSize &&
				!(lpBuffer[i] == ' ' ||
				lpBuffer[i] == '\t' ||
				lpBuffer[i] == '\r' ||
				lpBuffer[i] == '\n'))
				++dwLength;

			if (dwLength > 0) {
				LPSTR lpString = (LPSTR)HeapAlloc(hHeap, 0, dwLength + 1);

				if (lpString == NULL)
					goto BAD_RET;

				for (DWORD s = 0; s < dwLength; ++s)
					lpString[s] = lpBuffer[dwStringBegin + s];
				lpString[dwLength] = 0;

				if (dwStringIndex == 0)
					key.Name = lpString;
				else {
					key.ValueCount = dwStringIndex;

					if (key.Values == NULL)
						key.Values = (LPSTR*)HeapAlloc(hHeap, 0, sizeof(LPSTR));
					else
						key.Values = (LPSTR*)HeapReAlloc(hHeap, 0, key.Values, dwStringIndex * sizeof(LPSTR));

					if (!key.Values)
						goto BAD_RET;

					key.Values[dwStringIndex - 1] = lpString;
				}

				dwLength = 0;

				++dwStringIndex;
			}

			if ((lpBuffer[i] == '\r' ||
				lpBuffer[i] == '\n' ||
				i + 1 == dwFileSize) &&
				dwStringIndex > 0) {

				++pConfig->KeyCount;

				if (pConfig->Keys == NULL)
					pConfig->Keys = (Config::Key*)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, sizeof(Config::Key));
				else
					pConfig->Keys = (Config::Key*)HeapReAlloc(hHeap, HEAP_ZERO_MEMORY, pConfig->Keys,
					pConfig->KeyCount  * sizeof(Config::Key));

				if (!pConfig->Keys)
					goto BAD_RET;

				pConfig->Keys[pConfig->KeyCount - 1] = key;
				dwStringIndex = 0;
				key.ValueCount = 0;
				key.Values = NULL;
			}

			dwStringBegin = i + 1;
		}
		else
			++dwLength;
	}

	goto RET;

BAD_RET:
	result = FALSE;
	if (pConfig->Keys) {
		for (DWORD i = 0; i < pConfig->KeyCount; ++i) {
			if (pConfig->Keys[i].Name)
				HeapFree(hHeap, 0, pConfig->Keys[i].Name);
			if (pConfig->Keys[i].Values) {
				for (DWORD v = 0; v < pConfig->Keys[i].ValueCount; ++v) {
					if (pConfig->Keys[i].Values[v])
						HeapFree(hHeap, 0, pConfig->Keys[i].Values[v]);
				}
				HeapFree(hHeap, 0, pConfig->Keys[i].Values);
			}
		}
		HeapFree(hHeap, 0, pConfig->Keys);
	}
RET:
	HeapFree(hHeap, 0, lpBuffer);
	if (hFile)
		CloseHandle(hFile);

	return result;
}