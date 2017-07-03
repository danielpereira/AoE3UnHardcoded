#pragma once

typedef enum RESOURCE_ID {
	GOLD,
	WOOD,
	FOOD,
	FAME,
	ID_4,
	XP,
	SHIPMENTS,
	EXPORT
} RESOURCE_ID;

extern char(__thiscall *const CheatAddResource)(void* playerData, __int32 resourceID, float resourceAmount, __int8 unk);
extern void(__cdecl *const CheatSpawnUnit)(void* playerData, char* protoUnitName);
