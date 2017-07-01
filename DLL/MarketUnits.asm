code_cave_begin 007DEF70h
    invoke marketCheck
    test eax,eax
    jne_rel32 007DEFC3
    mov edx, dword ptr ds:[00C66234h]
    mov ecx, [esi+80h]
    jmp_rel32 007DEF76
code_cave_end 007DEF75h

public stdcall PatchMarketUnits
PatchMarketUnits proc
	patch_code_cave 007DEF70h,  007DEF75h
	invoke PatchAddress, _hProcess, loc_007DEFC3, 007DEFC3h, 1
	invoke PatchAddress, _hProcess, loc_007DEF76, 007DEF76h, 1
	ret
PatchMarketUnits endp
