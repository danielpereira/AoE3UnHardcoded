#pragma once

#include <Windows.h>
#include "TArray.h"

struct ConfigKey {
	LPSTR Name;
	TArray<LPSTR> Values;
};

class Config {
private:
	TArray<ConfigKey> m_Keys;
public:
	Config();
	~Config();

	BOOL Parse(LPCWSTR lpConfigName);

	inline TArray<ConfigKey>& GetKeys() { return m_Keys; }

	void Cleanup();
};