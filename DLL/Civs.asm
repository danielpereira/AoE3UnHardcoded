.model flat, stdcall
option casemap :none

include UHC.inc

extern pUHCInfo:UHCInfoPtr
extern hProcess:DWORD

TableIDExists proto stdcall dwTable:DWORD, id:DWORD

.code

getCivIDs PROC stdcall dwType:DWORD

    push edi
	push esi
	push ebx
    mov ebx,  UHCRefTable
    mov esi, ecx
    mov edi,  dwType
    imul ebx, edi
    mov edi, pUHCInfo
	lea edi, [edi].UHCInfo.Tables
    lea edi, [edi+ebx]
    mov ebx, [edi].UHCRefTable.RefCount
    test ebx, ebx
    je getCivIDs_end
    dec ebx
    
getCivIDs_loop:
    mov eax, [edi].UHCRefTable.Refs
    mov eax, [eax+ebx*4]
    push eax
    mov ecx, esi
    mov eax,  0058E71Fh
	call eax
    mov ecx, [edi].UHCRefTable.RefIDs
    mov [ecx+ebx*4], eax
    dec ebx
    jns getCivIDs_loop
    
getCivIDs_end:
    pop ebx
	pop esi
	pop edi
    ret

getCivIDs ENDP

checkWonders PROC stdcall esiPtr:DWORD, ediPtr:DWORD

    push edi
	push esi
	push ebx
    mov ebx, UHCRefTable
    mov esi, ecx
    mov edi, ASIAN
    imul ebx, edi
    mov edi, pUHCInfo
	lea edi, [edi].UHCInfo.Tables
    lea edi, [edi+ebx]
    mov ebx, [edi].UHCRefTable.RefCount
    test ebx, ebx
    je checkWonders_end
    dec ebx
    mov ecx, [edi].UHCRefTable.RefIDs
    cmp dword ptr ds:[esi+24h], 0
    jg checkWonders_not_null
    or eax, -1
    jmp checkWonders_loop
    
checkWonders_not_null:
    mov eax, [esi+20h]
    mov eax, [eax]
    
checkWonders_loop:
    cmp eax, [ecx+ebx*4]
    je checkWonders_load_wonders
    dec ebx
    jns checkWonders_loop
    jmp checkWonders_end
    
checkWonders_load_wonders:
    mov esi, esiPtr
    mov edi, ediPtr
    push -1
    push 0
	mov eax, pUHCInfo
    mov eax, [eax].UHCInfo.AsianCivNames
    mov eax, [eax+ebx*4]
    push eax
    mov eax, [esi+18Ch]
    lea ecx, [eax+edi+8]
    mov eax,  00443C10h
	call eax
    test eax, eax
    jne checkWonders_end
    mov eax, 1
    pop ebx
	pop esi
	pop edi
    ret
    
checkWonders_end:
    xor eax, eax
    pop ebx
	pop esi
	pop edi
    ret

checkWonders ENDP

checkCouncil PROC stdcall civID:DWORD, esiPtr:DWORD, ediPtr:DWORD

    push edi
	push esi
	push ebx
    mov ebx,  UHCRefTable
    mov edi,  NATIVE
    imul ebx, edi
    mov edi, pUHCInfo
	lea edi, [edi].UHCInfo.Tables
	mov esi, [edi].UHCInfo.NativeCivNames
    lea edi, [edi+ebx]
    mov ebx, [edi].UHCRefTable.RefCount
    test ebx, ebx
    je checkcouncil_end
    mov edi, [edi].UHCRefTable.RefIDs
    dec ebx
    
checkcouncil_loop:
    mov eax, civID
    mov ecx, [edi+ebx*4]
    cmp eax, ecx
    je checkcouncil_check
    dec ebx
    cmp ebx, 0
    jge checkcouncil_loop
    jmp checkcouncil_end
    
checkcouncil_check:
    mov eax, esiPtr
    mov eax, [eax+18Ch]
    mov ecx, ediPtr
    lea ecx, [eax+ecx+8]
    push -1
    push 0
    mov eax, [esi+ebx*4]
    push eax
    mov eax,  00443C10h
	call eax
    test eax, eax
    jne checkcouncil_end
    mov eax, 1
    pop ebx
	pop esi
	pop edi
    ret
    
checkcouncil_end:
    xor eax, eax
    pop ebx
	pop esi
	pop edi
    ret
    
checkCouncil ENDP

NatCivCheck1 PROC STDCALL ebxVal:DWORD

    push edi
	push esi
	push ebx
    mov ebx,  UHCRefTable
    mov esi, ecx
    mov edi,  NATIVE
    imul ebx, edi
    mov edi, pUHCInfo
	lea edi, [edi].UHCInfo.Tables
    lea edi, [edi+ebx]
    mov ebx, [edi].UHCRefTable.RefCount
    test ebx, ebx
    je natcivcheck1_end
    dec ebx
    
natcivcheck1_loop:
    mov eax, [edi].UHCRefTable.Refs
    mov eax, [eax+ebx*4]
    push eax
    mov ecx, esi
    mov eax,  0052D6FFh
	call eax
    xor ecx, ecx
    cmp eax, ecx
    je natcivcheck1_next
    mov ecx, ebxVal
    mov [eax+10h], ecx

natcivcheck1_next:
    dec ebx
    cmp ebx, 0
    jge natcivcheck1_loop
    
natcivcheck1_end:
    pop ebx
	pop esi
	pop edi
    ret
    
NatCivCheck1 ENDP

; Asian civs
; Allows user-created civilizations to use TAD civ features

; Asian Civs Patch #1
code_cave_begin 00454F1Dh
    cmp eax,  dword ptr ds:[00C6FB88h]
    je_rel32 00454F2A
    invoke TableIDExists, ASIAN, eax
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
    invoke TableIDExists, ASIAN, eax
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
	invoke PatchAddress,  hProcess,  loc_008D6ACC,  008D6ACCh,  1
    invoke PatchAddress,  hProcess,  loc_008D6B0C,  008D6B0Ch,  1
    invoke PatchAddress,  hProcess,  loc_008D6AF7,  008D6AF7h,  1

	patch_code_cave 00818284h,  00818288h
	invoke PatchAddress,  hProcess,  sub_0049A2D8,  0049A2D8h,  1
    invoke PatchAddress,  hProcess,  loc_0081828D,  0081828Dh,  1
    invoke PatchAddress,  hProcess,  loc_008182EB,  008182EBh,  1
    invoke PatchAddress,  hProcess,  loc_008182A9,  008182A9h,  1
	ret
PatchAsianCivs endp

; Big button civs

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
    invoke TableIDExists,5,eax
    test eax,eax
    je bb_back
    
    bb_exclude_buildings:
    mov eax,[esi+5Ch]
    test eax,eax
    je_rel32 00695955_1
    mov eax,[eax+08h]
    invoke TableIDExists,6,eax
    test eax,eax
    je_rel32 00695955_2
    
    bb_back:
    jmp_rel32 00461BDE
code_cave_end 00461BDDh

public stdcall PatchBigButton

PatchBigButton proc

	patch_code_cave 00461BD8h, 00461BDDh
	invoke PatchAddress,hProcess,loc_00695955_1,00695955h,1
	invoke PatchAddress,hProcess,loc_00461BDE,00461BDEh,1
	invoke PatchAddress,hProcess,loc_00695955_2,00695955h,1
	ret
PatchBigButton endp

; Native civs
; Allows user-created civilizations to use TWC civ features

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
    invoke TableIDExists, NATIVE, eax
    test eax, eax
    je npatch2_invalid_id
    mov al, 1
    retn
    
    npatch2_invalid_id:
    xor al, al
    retn
code_cave_end 00512724h

; Native Civs Patch #3 
code_cave_begin 0052B581h
    mov ecx, edi
    invoke NatCivCheck1, ebx
    lea ecx, [esp+100h]
    jmp_rel32 0052B588
code_cave_end 0052B587h

; Native Civs Patch #4 
code_cave_begin 00453D5Eh
    mov edx,eax
    invoke TableIDExists, NATIVE, eax
    test eax, eax
    jne npatch4_end
    cmp dword ptr ds:[esp+4], 0
    jmp_rel32 00453D63
    
    npatch4_end:
    mov al, 1
    retn 4
code_cave_end 00453D62h

; Native Civs Patch #5
code_cave_begin 004904B5h
    je_rel32 00679E66
    invoke TableIDExists, NATIVE, eax
    test eax, eax
    jne_rel32 00679E66_1
    jmp_rel32 004904BB
code_cave_end 004904BAh

; Native Civs Patch #6   
code_cave_begin 004ECD6Bh
    cmp eax,dword ptr ds:[00C6FB5Ch]
    je_rel32 004ECD7D
    invoke TableIDExists, NATIVE, eax
    test eax, eax
    jne_rel32 004ECD7D_1
    jmp_rel32 004ECD73
code_cave_end 004ECD71h

; Native Civs Patch #7   
code_cave_begin 0067B0A5h
    cmp eax, dword ptr ds:[00C6FB58h]
    je_rel32 0067B0BB
    invoke TableIDExists, NATIVE, eax
    test eax, eax
    jne_rel32 0067B0BB_1
    jmp_rel32 0067B0AD
code_cave_end 0067B0AAh

; Native Civs Patch #8    
code_cave_begin 008D47C9h
    je_rel32 008D47CF
    invoke TableIDExists, NATIVE, eax
    test eax, eax
    je_rel32 008D4894
    jmp_rel32 008D47CF_1
code_cave_end 008D47CEh

; Native Civs Patch #9    
code_cave_begin 008D52AFh
    je_rel32 008D53B4
    invoke TableIDExists, NATIVE, eax
    test eax, eax
    jne_rel32 008D53B4_1
    jmp_rel32 008D52B5
code_cave_end 008D52B5h

; Native Civs Patch #10     
code_cave_begin 0081ADEBh
    mov [esp+20h], eax
    mov eax,[esp+10h]
    invoke checkCouncil, eax, hProcess, edi
    test eax, eax
    jne_rel32 0081AE59
    cmp [esp+10h], ebx
    jmp_rel32 0081ADF3
code_cave_end 0081ADF2h

public stdcall PatchNativeCivs

PatchNativeCivs proc

	patch_code_cave 005126C1h, 005126C6h
	invoke PatchAddress, hProcess, loc_005126C7, 005126C7h, 1

	patch_code_cave 0051271Fh, 00512724h
	invoke PatchAddress, hProcess, loc_0051272A, 0051272Ah, 1

	patch_code_cave 0052B581h, 0052B587h
	invoke PatchAddress, hProcess, loc_0052B588, 0052B588h, 1

	patch_code_cave 00453D5Eh, 00453D62h
	invoke PatchAddress, hProcess, loc_00453D63, 00453D63h, 1

	patch_code_cave 004904B5h, 004904BAh
	invoke PatchAddress, hProcess, loc_00679E66, 00679E66h, 1
    invoke PatchAddress, hProcess, loc_00679E66_1, 00679E66h, 1
    invoke PatchAddress, hProcess, loc_004904BB, 004904BBh, 1

	patch_code_cave 004ECD6Bh, 004ECD71h
	invoke PatchAddress, hProcess, loc_004ECD7D, 004ECD7Dh, 1
    invoke PatchAddress, hProcess, loc_004ECD7D_1, 004ECD7Dh, 1
    invoke PatchAddress, hProcess, loc_004ECD73, 004ECD73h, 1

	patch_code_cave 0067B0A5h, 0067B0AAh
	invoke PatchAddress, hProcess, loc_0067B0BB, 0067B0BBh, 1
	invoke PatchAddress, hProcess, loc_0067B0BB_1, 0067B0BBh, 1
    invoke PatchAddress, hProcess, loc_0067B0AD, 0067B0ADh, 1

	patch_code_cave 008D47C9h, 008D47CEh
	invoke PatchAddress, hProcess,loc_008D47CF,008D47CFh,1
	invoke PatchAddress, hProcess,loc_008D4894,008D4894h,1
	invoke PatchAddress, hProcess,loc_008D47CF_1,008D47CFh,1

	patch_code_cave 008D52AFh, 008D52B5h
	invoke PatchAddress, hProcess, loc_008D53B4, 008D53B4h, 1
	invoke PatchAddress, hProcess, loc_008D53B4_1, 008D53B4h, 1
	invoke PatchAddress, hProcess, loc_008D52B5, 008D52B5h, 1

	patch_code_cave 0081ADEBh, 0081ADF2h
	invoke PatchAddress, hProcess, loc_0081AE59, 0081AE59h, 1
	invoke PatchAddress, hProcess, loc_0081ADF3, 0081ADF3h, 1

	ret
PatchNativeCivs endp

; Civ check

code_cave_begin 008D0318h
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx, [ecx+140h]
    invoke getCivIDs, ASIAN
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx, [ecx+140h]
    invoke getCivIDs, NATIVE
    mov eax, dword ptr ds:[00C66234h]
    jmp_rel32 008D031D
code_cave_end 008D031Ch

code_cave_begin 008DABA3h
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx, [ecx+140h]
    invoke getCivIDs, ASIAN
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx, [ecx+140h]
    invoke getCivIDs, NATIVE
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx, [ecx+140h]
    invoke getCivIDs, 5
    mov edx, dword ptr ds:[00C66234h]
    jmp_rel32 008DABA9
code_cave_end 008DABA8h

public stdcall PatchCivCheck
PatchCivCheck proc
	patch_code_cave 008D0318h, 008DABA8h
	invoke PatchAddress, hProcess, loc_008D031D, 008D031Dh, 1
	
	patch_code_cave 008DABA3h, 008DABA8h
	invoke PatchAddress, hProcess, loc_008DABA9, 008DABA9h, 1
	ret
PatchCivCheck endp

end