#include "CheatFunctions.h"

char(__thiscall const* CheatAddResource)(void* playerData, __int32 resourceID, float resourceAmount, __int8 unk) = reinterpret_cast<char(__thiscall*)(void*, __int32, float, __int8)>(0x0049A98A);
void(__cdecl const* CheatSpawnUnit)(void* playerData, char* protoUnitName) = reinterpret_cast<void(__cdecl*)(void*, char*)>(0x007B51C3);

