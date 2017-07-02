code_cave_begin 00461BD8h
    jne bb_exclude_buildings
    mov eax,edi
    cmp dword ptr ds:[eax+24h],0
    jg bb_not_null
    or eax,-1
    jmp bb_check
    
    bb_not_null:
    mov eax,[eax+20h]
    mov eax,[eax]
    
    bb_check:
    invoke checkID,5,eax
    test eax,eax
    je bb_back
    
    bb_exclude_buildings:
    mov eax,[esi+5Ch]
    test eax,eax
    je_rel32 00695955_1
    mov eax,[eax+08h]
    invoke checkID,6,eax
    test eax,eax
    je_rel32 00695955_2
    
    bb_back:
    jmp_rel32 00461BDE
code_cave_end 00461BDDh

public stdcall PatchBigButton

PatchBigButton proc

	patch_code_cave 00461BD8h, 00461BDDh
	invoke PatchAddress,_hProcess,loc_00695955_1,00695955h,1
	invoke PatchAddress,_hProcess,loc_00461BDE,00461BDEh,1
	invoke PatchAddress,_hProcess,loc_00695955_2,00695955h,1
	ret
PatchBigButton endp