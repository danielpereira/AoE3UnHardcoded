; Native Civs Patch #1
code_cave_begin 005126C1h
    mov ecx,[ecx+140h]
    invoke getCivIDs, NATIVE
    mov ecx,dword ptr ds:[00C66234h]
    mov ecx,[ecx+140h]
    jmp_rel32 005126C7
code_cave_end 005126C6h
 
; Native Civs Patch #2 
code_cave_begin 0051271Fh
    cmp eax,dword ptr ds:[00C6FB58h]
    je_rel32 0051272A 
    invoke checkID, NATIVE,eax
    test eax,eax
    je npatch2_invalid_id
    mov al,1
    retn
    
    npatch2_invalid_id:
    xor al,al
    retn
code_cave_end 00512724h

; Native Civs Patch #3 
code_cave_begin 0052B581h
    mov ecx,edi
    invoke NatCivCheck1,ebx
    lea ecx,[esp+100h]
    jmp_rel32 0052B588
code_cave_end 0052B587h

; Native Civs Patch #4 
code_cave_begin 00453D5Eh
    mov edx,eax
    invoke checkID,NATIVE,eax
    test eax,eax
    jne npatch4_end
    cmp dword ptr ds:[esp+4],0
    jmp_rel32 00453D63
    
    npatch4_end:
    mov al,1
    retn 4
code_cave_end 00453D62h

; Native Civs Patch #5
code_cave_begin 004904B5h
    je_rel32 00679E66
    invoke checkID,NATIVE,eax
    test eax,eax
    jne_rel32 00679E66_1
    jmp_rel32 004904BB
code_cave_end 004904BAh

; Native Civs Patch #6   
code_cave_begin 004ECD6Bh
    cmp eax,dword ptr ds:[00C6FB5Ch]
    je_rel32 004ECD7D
    invoke checkID,NATIVE,eax
    test eax,eax
    jne_rel32 004ECD7D_1
    jmp_rel32 004ECD73
code_cave_end 004ECD71h

; Native Civs Patch #7   
code_cave_begin 0067B0A5h
    cmp eax,dword ptr ds:[00C6FB58h]
    je_rel32 0067B0BB
    invoke checkID,NATIVE,eax
    test eax,eax
    jne_rel32 0067B0BB_1
    jmp_rel32 0067B0AD
code_cave_end 0067B0AAh

; Native Civs Patch #8    
code_cave_begin 008D47C9h
    je_rel32 008D47CF
    invoke checkID,NATIVE,eax
    test eax,eax
    je_rel32 008D4894
    jmp_rel32 008D47CF_1
code_cave_end 008D47CEh

; Native Civs Patch #9    
code_cave_begin 008D52AFh
    je_rel32 008D53B4
    invoke checkID,NATIVE,eax
    test eax,eax
    jne_rel32 008D53B4_1
    jmp_rel32 008D52B5
code_cave_end 008D52B5h

; Native Civs Patch #10     
code_cave_begin 0081ADEBh
    mov [esp+20h],eax
    mov eax,[esp+10h]
    invoke checkCouncil,eax,_hProcess,edi
    test eax,eax
    jne_rel32 0081AE59
    cmp [esp+10h],ebx
    jmp_rel32 0081ADF3
code_cave_end 0081ADF2h

public stdcall PatchNativeCivs

PatchNativeCivs proc

	patch_code_cave 005126C1h, 005126C6h
	invoke PatchAddress,_hProcess,loc_005126C7,005126C7h,1

	patch_code_cave 0051271Fh, 00512724h
	invoke PatchAddress,_hProcess,loc_0051272A,0051272Ah,1

	patch_code_cave 0052B581h, 0052B587h
	invoke PatchAddress,_hProcess,loc_0052B588,0052B588h,1

	patch_code_cave 00453D5Eh, 00453D62h
	invoke PatchAddress,_hProcess,loc_00453D63,00453D63h,1

	patch_code_cave 004904B5h, 004904BAh
	invoke PatchAddress,_hProcess,loc_00679E66,00679E66h,1
    invoke PatchAddress,_hProcess,loc_00679E66_1,00679E66h,1
    invoke PatchAddress,_hProcess,loc_004904BB,004904BBh,1

	patch_code_cave 004ECD6Bh, 004ECD71h
	invoke PatchAddress,_hProcess,loc_004ECD7D,004ECD7Dh,1
    invoke PatchAddress,_hProcess,loc_004ECD7D_1,004ECD7Dh,1
    invoke PatchAddress,_hProcess,loc_004ECD73,004ECD73h,1

	patch_code_cave 0067B0A5h, 0067B0AAh
	invoke PatchAddress,_hProcess,loc_0067B0BB,0067B0BBh,1
	invoke PatchAddress,_hProcess,loc_0067B0BB_1,0067B0BBh,1
    invoke PatchAddress,_hProcess,loc_0067B0AD,0067B0ADh,1

	patch_code_cave 008D47C9h, 008D47CEh
	invoke PatchAddress,_hProcess,loc_008D47CF,008D47CFh,1
	invoke PatchAddress,_hProcess,loc_008D4894,008D4894h,1
	invoke PatchAddress,_hProcess,loc_008D47CF_1,008D47CFh,1

	patch_code_cave 008D52AFh, 008D52B5h
	invoke PatchAddress,_hProcess,loc_008D53B4,008D53B4h,1
	invoke PatchAddress,_hProcess,loc_008D53B4_1,008D53B4h,1
	invoke PatchAddress,_hProcess,loc_008D52B5,008D52B5h,1

	patch_code_cave 0081ADEBh, 0081ADF2h
	invoke PatchAddress,_hProcess,loc_0081AE59,0081AE59h,1
	invoke PatchAddress,_hProcess,loc_0081ADF3,0081ADF3h,1

	ret
PatchNativeCivs endp