; Asian Civs Patch #1
code_cave_begin 00454F1Dh
    cmp eax,  dword ptr ds:[00C6FB88h]
    je_rel32 00454F2A
    invoke checkID, ASIAN, eax
    test eax, eax
    je apatch1_invalid_id
    mov al, 1
    retn 4
    
    apatch1_invalid_id:
    xor al, al
    retn 4
code_cave_end 00454F22h

; Asian Civs Patch #2    
code_cave_begin 008D6AC4h
    cmp eax,  dword ptr ds:[00C6FB88h]
    je_rel32 008D6ACC
    invoke checkID, ASIAN, eax
    test eax, eax
    je_rel32 008D6B0C
    jmp_rel32 008D6AF7
code_cave_end 008D6AC9h

; Asian Civs Patch #3
code_cave_begin 00818284h
    call_rel32 0049A2D8
    test eax, eax
    jne_rel32 0081828D
    mov ecx, ebp
    invoke checkWonders, esi, edi
    test eax, eax
    je_rel32 008182EB
    jmp_rel32 008182A9
code_cave_end 00818288h

public stdcall PatchAsianCivs
PatchAsianCivs proc
	patch_code_cave 00454F1Dh,  00454F22h
	invoke PatchAddress, esi, loc_00454F2A,  00454F2Ah,  1

	patch_code_cave 008D6AC4h,  008D6AC9h
	invoke PatchAddress,  _hProcess,  loc_008D6ACC,  008D6ACCh,  1
    invoke PatchAddress,  _hProcess,  loc_008D6B0C,  008D6B0Ch,  1
    invoke PatchAddress,  _hProcess,  loc_008D6AF7,  008D6AF7h,  1

	patch_code_cave 00818284h,  00818288h
	invoke PatchAddress,  _hProcess,  sub_0049A2D8,  0049A2D8h,  1
    invoke PatchAddress,  _hProcess,  loc_0081828D,  0081828Dh,  1
    invoke PatchAddress,  _hProcess,  loc_008182EB,  008182EBh,  1
    invoke PatchAddress,  _hProcess,  loc_008182A9,  008182A9h,  1
	ret
PatchAsianCivs endp