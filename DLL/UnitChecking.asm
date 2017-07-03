; Get farm and market IDs
code_cave_begin 005EE78Bh
	mov edi,  [esi+140h]
	mov ecx, edi
	invoke getIDs, FARM
	mov ecx, edi
	invoke getIDs, RECTFARM
	mov ecx, edi
	invoke getIDs, MARKET
	mov ecx, edi
	invoke getIDs, 6
code_cave_end 005EE78Bh

public stdcall PatchUnitChecking
PatchUnitChecking proc
	patch_code_cave 005EE78Bh,  005EE78Bh
	retn
PatchUnitChecking endp