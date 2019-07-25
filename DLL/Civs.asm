.model flat, stdcall
option casemap :none

include UHC.inc

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
    mov esi, [edi].UHCInfo.NativeCivNames
	lea edi, [edi].UHCInfo.Tables
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

patch_begin AsianCivs

; Asian Civs Patch #1
code_cave_begin 00454F1Dh
	cmp eax,  dword ptr ds:[00C6FB88h]
	je_rel32 00454F2Ah
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
	je_rel32 008D6ACCh
	invoke TableIDExists, ASIAN, eax
	test eax, eax
	je_rel32 008D6B0Ch
code_cave_end 008D6AF7h

; Asian Civs Patch #3
code_cave_begin 00818284h
	call_rel32 0049A2D8h
	test eax, eax
	jne_rel32 0081828Dh
	mov ecx, ebp
	invoke checkWonders, esi, edi
	test eax, eax
	je_rel32 008182EBh
code_cave_end 008182A9h

patch_end AsianCivs

; Big button civs

patch_begin BigButton

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
	invoke TableIDExists,BIGBUTTON_CIVS,eax
	test eax,eax
	je bb_back
	
	bb_exclude_buildings:
	mov eax,[esi+5Ch]
	test eax,eax
	je_rel32 00695955h
	mov eax,[eax+08h]
	invoke TableIDExists,NO_BIGBUTTON_BLDS,eax
	test eax,eax
	je_rel32 00695955h
	
	bb_back:
code_cave_end 00461BDEh

patch_end BigButton

; Native civs
; Allows user-created civilizations to use TWC civ features

patch_begin NativeCivs

; Native Civs Patch #1
code_cave_begin 005126C1h
	mov ecx,[ecx+140h]
	invoke getCivIDs, NATIVE
	mov ecx,dword ptr ds:[00C66234h]
	mov ecx,[ecx+140h]
code_cave_end 005126C7h
 
; Native Civs Patch #2 
code_cave_begin 0051271Fh
	cmp eax,dword ptr ds:[00C6FB58h]
	je_rel32 0051272Ah
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
code_cave_end 0052B588h

; Native Civs Patch #4 
code_cave_begin 00453D5Eh
	cmp dword ptr ds:[esp+4], 0
	je npatch4_check
	cmp eax, dword ptr ds:[00C6FB5Ch]
	je npatch4_end

	npatch4_check:
	invoke TableIDExists, NATIVE, eax
	test eax, eax
	jne npatch4_end
	xor al,al
	retn 4
	
	npatch4_end:
	mov al, 1
	retn 4
code_cave_end 00453D62h

; Native Civs Patch #5
code_cave_begin 004904B5h
	je_rel32 00679E66h
	invoke TableIDExists, NATIVE, eax
	test eax, eax
	jne_rel32 00679E66h
code_cave_end 004904BBh

; Native Civs Patch #6   
code_cave_begin 004ECD6Bh
	cmp eax,dword ptr ds:[00C6FB5Ch]
	je_rel32 004ECD7Dh
	invoke TableIDExists, NATIVE, eax
	test eax, eax
	jne_rel32 004ECD7Dh
code_cave_end 004ECD73h

; Native Civs Patch #7   
code_cave_begin 0067B0A5h
	cmp eax, dword ptr ds:[00C6FB58h]
	je_rel32 0067B0BBh
	invoke TableIDExists, NATIVE, eax
	test eax, eax
	jne_rel32 0067B0BBh
code_cave_end 0067B0ADh

; Native Civs Patch #8	
code_cave_begin 008D47C9h
	je npatch8_end
	invoke TableIDExists, NATIVE, eax
	test eax, eax
	je_rel32 008D4894h
npatch8_end:
code_cave_end 008D47CFh

; Native Civs Patch #9	
code_cave_begin 008D52AFh
	je_rel32 008D53B4h
	invoke TableIDExists, NATIVE, eax
	test eax, eax
	jne_rel32 008D53B4h
code_cave_end 008D52B5h

; Native Civs Patch #10	 
code_cave_begin 0081ADEBh
	mov [esp+20h], eax
	mov eax,[esp+10h]
	invoke checkCouncil, eax, esi, edi
	test eax, eax
	jne_rel32 0081AE59h
	cmp [esp+10h], ebx
code_cave_end 0081ADF3h

patch_end NativeCivs

; Two Scouts/Explorers Civs

patch_begin TwoScoutCivs

code_cave_begin 0077EBB2h
	mov eax, [esi+1DCh]
	invoke TableIDExists, TWO_SCOUT_CIVS, eax
	test eax, eax
	je two_scout_patch1_end
	mov bl, al
	mov byte ptr ds:[esp+0Fh], bl
	mov byte ptr ds:[esp+0Eh], 0
	jmp_rel32 0077EBF6h

	two_scout_patch1_end:
code_cave_end 0077EBB2h	

code_cave_begin 0077EF29h
	invoke TableIDExists, TWO_SCOUT_CIVS, eax
	test eax, eax
	jne_rel32 0077EF68h
	mov eax, dword ptr ds:[esp+14h]
	push eax
	call_rel32 008D0318h
code_cave_end 0077EF2Fh

code_cave_begin 0077DDD2h
	mov eax, [esi+1DCh]
	invoke TableIDExists, TWO_SCOUT_CIVS, eax
	test eax, eax
	jne_rel32 0077DE16h
code_cave_end 0077DDD2h

code_cave_begin 0077DFF4h
	mov eax, [esi+1DCh]
	invoke TableIDExists, TWO_SCOUT_CIVS, eax
	test eax, eax
	jne_rel32 0077E039h
code_cave_end 0077DFF4h

patch_end TwoScoutCivs

; Civ check

patch_begin CivCheck

code_cave_begin 008D0318h
	mov ecx, dword ptr ds:[00C66234h]
	mov ecx, [ecx+140h]
	invoke getCivIDs, ASIAN
	mov ecx, dword ptr ds:[00C66234h]
	mov ecx, [ecx+140h]
	invoke getCivIDs, NATIVE
	mov ecx, dword ptr ds:[00C66234h]
	mov ecx, [ecx+140h]
	invoke getCivIDs, TWO_SCOUT_CIVS
	mov eax, dword ptr ds:[00C66234h]
	jmp_rel32 008D031Dh
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
	invoke getCivIDs, BIGBUTTON_CIVS
	mov edx, dword ptr ds:[00C66234h]
	jmp_rel32 008DABA9h
code_cave_end 008DABA8h

patch_end CivCheck

end