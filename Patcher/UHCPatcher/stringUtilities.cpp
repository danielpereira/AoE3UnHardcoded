#include "stdafx.h"
#include "stringUtilities.h"

int lstrrchrW(LPWSTR str, WCHAR character) {

	for (int i = lstrlenW(str) - 1; i >= 0; i--) {
		if (str[i] == character)
			return i;
	}

	return -1;
}

BOOL StringCchLength(LPWSTR psz, size_t cchMax, size_t *pcch) {
	size_t i;

	for (i = 0, (*pcch) = 0; i < cchMax && psz[i] != '\0'; i++, (*pcch)++);

	return (psz[i] == '\0');
}
