.model flat, stdcall
option casemap :none

include UHC.inc

extern pUHCInfo:UHCInfoPtr
extern hcXpIconPath:DWORD
extern hcFameIconPath:DWORD
extern hProcess:DWORD

.code

; AI limit
; Makes the game read all .personality files from the AI directory

LoadPersonalities proto stdcall

code_cave_begin 00603B0Bh
	invoke LoadPersonalities
	mov edi, pUHCInfo
	mov esi, [edi].UHCInfo.PersonalityCount
	mov dword ptr ss:[esp + 040h], esi
	mov esi, [edi].UHCInfo.Personalities
	mov dword ptr ss:[esp + 050h], esi
code_cave_end 00603C4Fh

public stdcall PatchAILimit
PatchAILimit proc
	patch_code_cave 00603B0Bh, 00603C4Fh
	ret
PatchAILimit endp

; Deck limit
; Increases maximum deck card count to 40

code_cave_begin 007EF026h
	mov ecx, pUHCInfo
	mov ecx, [ecx].UHCInfo.DeckCardCount
	cmp eax, ecx
	jle deck_end
	mov eax, ecx
deck_end:
code_cave_end 007EF030h

public stdcall PatchDeckLimit
PatchDeckLimit proc
	patch_code_cave 007EF026h, 007EF030h
	ret
PatchDeckLimit endp

; Pop limit
; Removes maximum base population and extra population limit (refer to PopulationCapExtra in Techtree)

code_cave_begin 004581F3h
	mov esi, pUHCInfo
	mov esi, [esi].UHCInfo.ExtraPop
	cmp ecx, esi
	jle check_base_pop
	mov ecx, esi
check_base_pop:
	mov esi, pUHCInfo
	mov esi, [esi].UHCInfo.BasePop
	add ecx, esi
	cmp eax, ecx
	jle check_pop_extra
	mov eax, ecx
check_pop_extra:
	mov edx, [edx + 04F4h]
	test edx, edx
	jle pop_end
	add eax, edx
pop_end:
code_cave_end 0045823Fh

public stdcall PatchPopLimit
PatchPopLimit proc
	patch_code_cave 004581F3h, 0045823Fh
	ret
PatchPopLimit endp

; Team limit
; Unlocks team 3 and 4 for both singleplayer and multiplayer

; singleplayer
code_cave_begin 07A0709h
	push 08D2Fh ; Team 3 String ID
	lea ecx, [esp + 014h]
	mov eax, 058EA52h
	call eax
	mov esi, eax
	mov eax, [esp + 018h]
	mov edi, eax
	push ebx
	add eax, 01h
	push eax
	lea ecx, [esp + 01ch]
	mov eax, 04676E7h
	call eax
	test al, al
	jz team3_zero_return
	mov ecx, [esp + 014h]
	push esi
	lea ecx, [edi * 04h + ecx]
	mov eax, 040196Fh
	call eax
team3_zero_return:
	lea ecx, [esp + 010h]
	mov eax, 04010CAh
	mov eax, [esp + 024h]
	mov esi, eax
	push ebx
	add eax, 01h
	push eax
	lea ecx, [esp + 028h]
	mov eax, 0401113h
	call eax
	test al, al
	jz team4
	mov edx, [esp + 020h]
	mov dword ptr ds:[esi * 4 + edx], 02h
team4:
	push 08D30h ; Team 4 String ID
	lea ecx, [esp + 014h]
	mov eax, 058EA52h
	call eax
	mov esi, eax
	mov eax, [esp + 018h]
	mov edi, eax
	push ebx
	add eax, 01h
	push eax
	lea ecx, [esp + 01ch]
	mov eax, 04676E7h
	call eax
	test al, al
	jz team4_zero_return
	mov ecx, [esp + 014h]
	push esi
	lea ecx, [edi * 04h + ecx]
	mov eax, 040196Fh
	call eax
team4_zero_return:
	lea ecx, [esp + 010h]
	mov eax, 04010CAh
	mov eax, [esp + 024h]
	mov esi, eax
	push ebx
	add eax, 01h
	push eax
	lea ecx, [esp + 028h]
	mov eax, 0401113h
	call eax
	test al, al
	jz team4_end
	mov edx, [esp + 020h]
	mov dword ptr ds:[esi * 4 + edx], 03h
team4_end:
code_cave_end 07A0709h

; multiplayer
code_cave_begin 077674Ah
	jz team_random_mp
	dec eax
	jz team3_mp
	dec eax
	jz team4_mp
team_random_mp:
code_cave_end 077674Ah

team3_mp:
	mov ecx, 02h
	push ecx
	mov ecx, dword ptr ds:[esi + 0Ch]
	push edx
	mov eax, 0A26321h
	call eax
	pop edi
	pop esi
	mov al, 01h
	pop ebx
	add esp, 028h
	retn 0Ch
team4_mp:
	mov ecx, 03h
	push ecx
	mov ecx, dword ptr ds:[esi + 0Ch]
	push edx
	mov eax, 0A26321h
	call eax
	pop edi
	pop esi
	mov al, 01h
	pop ebx
	add esp, 028h
	retn 0Ch

public stdcall PatchTeamLimit
PatchTeamLimit proc
	patch_code_cave 07A0709h, 07A0709h
	patch_code_cave 077674Ah, 077674Ah
	ret
PatchTeamLimit endp

; Politician Screen Resource Restriction Patch #1

code_cave_begin 0080E490h
	lea ecx, [esp+28h]
    call_rel32 0058F070
    push 3
    lea ecx, [esp+34h]
    call_rel32 0044EFFF
    push ecx
    fstp dword ptr ds:[esp]
    push 3
    lea  ecx, [esp+30h]
    call_rel32 0058EF83
    mov edx, dword ptr ds:[00C66234h]
    mov ebx, [edx]
    mov ecx, esi
    call_rel32 004539D3
    push eax
    push 1
    push 1
    push 1
    lea eax, [esp+28h]
    push eax
    lea ecx, [esp+3Ch]
    push ecx
    mov ecx, dword ptr ds: [00C66234h]
    call dword ptr ds:[ebx+134h]
    push -1
    push -1
    lea edx, [esp+20h]
    push edx
    lea ecx, [esp+20h]
    call_rel32 004439E3
    push -1
    push -1
    push 00B9FFDCh
    lea ecx, [esp+20h]
    call_rel32 00443960
	lea ecx, [esp+28h]
    call_rel32 0058F070_1
    push 5
    lea ecx, [esp+34h]
    call_rel32 0044EFFF_1
    push ecx
    fstp dword ptr ds:[esp]
    push 5
    lea  ecx, [esp+30h]
    call_rel32 0058EF83_1
    mov edx, dword ptr ds:[00C66234h]
    mov ebx, [edx]
    mov ecx, esi
    call_rel32 004539D3_1
    push eax
    push 1
    push 1
    push 1
    lea eax, [esp+28h]
    push eax
    lea ecx, [esp+3Ch]
    push ecx
    mov ecx, dword ptr ds: [00C66234h]
    call dword ptr ds:[ebx+134h]
    push -1
    push -1
    lea edx, [esp+20h]
    push edx
    lea ecx, [esp+20h]
    call_rel32 004439E3_1
    push -1
    push -1
    push 00B9FFDCh
    lea ecx, [esp+20h]
    call_rel32 00443960_1
	lea ecx, [esp+28h]
    call_rel32 0058F070_2
    push 6
    lea ecx, [esp+34h]
    call_rel32 0044EFFF_2
    push ecx
    fstp dword ptr ds:[esp]
    push 6
    lea  ecx, [esp+30h]
    call_rel32 0058EF83_2
    mov edx, dword ptr ds:[00C66234h]
    mov ebx, [edx]
    mov ecx, esi
    call_rel32 004539D3_2
    push eax
    push 1
    push 1
    push 1
    lea eax, [esp+28h]
    push eax
    lea ecx, [esp+3Ch]
    push ecx
    mov ecx, dword ptr ds: [00C66234h]
    call dword ptr ds:[ebx+134h]
    push -1
    push -1
    lea edx, [esp+20h]
    push edx
    lea ecx, [esp+20h]
    call_rel32 004439E3_2
    push -1
    push -1
    push 00B9FFDCh
    lea ecx, [esp+20h]
    call_rel32 00443960_2
code_cave_end 0080E490h

; Politician Screen Resource Restriction Patch #2

code_cave_begin 0081943Dh
	lea ecx, [esp+28h]
    call_rel32 0058F070_3
    push 3
    lea ecx, [esp+34h]
    call_rel32 0044EFFF_3
    push ecx
    fstp dword ptr ds:[esp]
    push 3
    lea  ecx, [esp+30h]
    call_rel32 0058EF83_3
    mov edx, dword ptr ds:[00C66234h]
    mov ebx, [edx]
    mov ecx, esi
    call_rel32 004539D3_3
    push eax
    push 1
    push 1
    push 1
    lea eax, [esp+28h]
    push eax
    lea ecx, [esp+3Ch]
    push ecx
    mov ecx, dword ptr ds: [00C66234h]
    call dword ptr ds:[ebx+134h]
    push -1
    push -1
    lea edx, [esp+20h]
    push edx
    lea ecx, [esp+20h]
    call_rel32 004439E3_3
    push -1
    push -1
    push 00B9FFDCh
    lea ecx, [esp+20h]
    call_rel32 00443960_3
	lea ecx, [esp+28h]
    call_rel32 0058F070_4
    push 5
    lea ecx, [esp+34h]
    call_rel32 0044EFFF_4
    push ecx
    fstp dword ptr ds:[esp]
    push 5
    lea  ecx, [esp+30h]
    call_rel32 0058EF83_4
    mov edx, dword ptr ds:[00C66234h]
    mov ebx, [edx]
    mov ecx, esi
    call_rel32 004539D3_4
    push eax
    push 1
    push 1
    push 1
    lea eax, [esp+28h]
    push eax
    lea ecx, [esp+3Ch]
    push ecx
    mov ecx, dword ptr ds: [00C66234h]
    call dword ptr ds:[ebx+134h]
    push -1
    push -1
    lea edx, [esp+20h]
    push edx
    lea ecx, [esp+20h]
    call_rel32 004439E3_4
    push -1
    push -1
    push 00B9FFDCh
    lea ecx, [esp+20h]
    call_rel32 00443960_4
	lea ecx, [esp+28h]
    call_rel32 0058F070_5
    push 6
    lea ecx, [esp+34h]
    call_rel32 0044EFFF_5
    push ecx
    fstp dword ptr ds:[esp]
    push 6
    lea  ecx, [esp+30h]
    call_rel32 0058EF83_5
    mov edx, dword ptr ds:[00C66234h]
    mov ebx, [edx]
    mov ecx, esi
    call_rel32 004539D3_5
    push eax
    push 1
    push 1
    push 1
    lea eax, [esp+28h]
    push eax
    lea ecx, [esp+3Ch]
    push ecx
    mov ecx, dword ptr ds: [00C66234h]
    call dword ptr ds:[ebx+134h]
    push -1
    push -1
    lea edx, [esp+20h]
    push edx
    lea ecx, [esp+20h]
    call_rel32 004439E3_5
    push -1
    push -1
    push 00B9FFDCh
    lea ecx, [esp+20h]
    call_rel32 00443960_5
	lea ecx, [esp+28h]
    call_rel32 0058F070_6
    push 7
    lea ecx, [esp+34h]
    call_rel32 0044EFFF_6
    push ecx
    fstp dword ptr ds:[esp]
    push 7
    lea  ecx, [esp+30h]
    call_rel32 0058EF83_6
    mov edx, dword ptr ds:[00C66234h]
    mov ebx, [edx]
    mov ecx, esi
    call_rel32 004539D3_6
    push eax
    push 1
    push 1
    push 1
    lea eax, [esp+28h]
    push eax
    lea ecx, [esp+3Ch]
    push ecx
    mov ecx, dword ptr ds: [00C66234h]
    call dword ptr ds:[ebx+134h]
    push -1
    push -1
    lea edx, [esp+20h]
    push edx
    lea ecx, [esp+20h]
    call_rel32 004439E3_6
    push -1
    push -1
    push 00B9FFDCh
    lea ecx, [esp+20h]
    call_rel32 00443960_6
code_cave_end 0081943Dh

code_cave_begin 005C1E1Fh
	call_rel32 0058E3EB
	mov dword ptr ds:[esi+168h],eax
	push -1
	push 0
	push 0
	push hcXpIconPath
	mov ecx,edi
	call_rel32 0058E3EB_1
	mov ecx, pUHCInfo
	lea ecx,[ecx].UHCInfo.HCXpIconData
	mov [ecx],eax
	push -1
	push 0
	push 0
	push hcFameIconPath
	mov ecx,edi
	call_rel32 0058E3EB_2
	mov ecx, pUHCInfo
	lea ecx,[ecx].UHCInfo.HCFameIconData
	mov [ecx],eax
	push -1
	push 0
	push 0
	push 00BA96C4h
	mov ecx,edi
code_cave_end 005C1E37h

DisplayFameIcon:
	mov eax, pUHCInfo
	mov eax, [eax].UHCInfo.HCFameIconData
	jmp_rel32 009A2098

DisplayXPIcon:
	mov eax, pUHCInfo
	mov eax, [eax].UHCInfo.HCXpIconData
	jmp_rel32 009A2098_1


; Resource Restriction Removal
; Allows using the 'Fame' resource for ProtoActions, like AutoGather or ModifyGather
; Also removes resource restrictions in politician screens and HC cards

public stdcall PatchFameRestriction
PatchFameRestriction proc
	invoke PatchAddress, hProcess, 0051B026h, 00BD62F8h, 0

	patch_code_cave 0080E490h,  0080E490h
	invoke PatchAddress, hProcess, sub_0058F070, 0058F070h, 1
	invoke PatchAddress, hProcess, sub_0044EFFF, 0044EFFFh, 1
	invoke PatchAddress, hProcess, sub_0058EF83, 0058EF83h, 1
	invoke PatchAddress, hProcess, sub_004539D3, 004539D3h, 1
	invoke PatchAddress, hProcess, sub_004439E3, 004439E3h, 1
	invoke PatchAddress, hProcess, sub_00443960, 00443960h, 1
	invoke PatchAddress, hProcess, sub_0058F070_1, 0058F070h, 1
	invoke PatchAddress, hProcess, sub_0044EFFF_1, 0044EFFFh, 1
	invoke PatchAddress, hProcess, sub_0058EF83_1, 0058EF83h, 1
	invoke PatchAddress, hProcess, sub_004539D3_1, 004539D3h, 1
	invoke PatchAddress, hProcess, sub_004439E3_1, 004439E3h, 1
	invoke PatchAddress, hProcess, sub_00443960_1, 00443960h, 1
	invoke PatchAddress, hProcess, sub_0058F070_2, 0058F070h, 1
	invoke PatchAddress, hProcess, sub_0044EFFF_2, 0044EFFFh, 1
	invoke PatchAddress, hProcess, sub_0058EF83_2, 0058EF83h, 1
	invoke PatchAddress, hProcess, sub_004539D3_2, 004539D3h, 1
	invoke PatchAddress, hProcess, sub_004439E3_2, 004439E3h, 1
	invoke PatchAddress, hProcess, sub_00443960_2, 00443960h, 1

	patch_code_cave 0081943Dh,  0081943Dh
	invoke PatchAddress, hProcess, sub_0058F070_3, 0058F070h, 1
	invoke PatchAddress, hProcess, sub_0044EFFF_3, 0044EFFFh, 1
	invoke PatchAddress, hProcess, sub_0058EF83_3, 0058EF83h, 1
	invoke PatchAddress, hProcess, sub_004539D3_3, 004539D3h, 1
	invoke PatchAddress, hProcess, sub_004439E3_3, 004439E3h, 1
	invoke PatchAddress, hProcess, sub_00443960_3, 00443960h, 1
	invoke PatchAddress, hProcess, sub_0058F070_4, 0058F070h, 1
	invoke PatchAddress, hProcess, sub_0044EFFF_4, 0044EFFFh, 1
	invoke PatchAddress, hProcess, sub_0058EF83_4, 0058EF83h, 1
	invoke PatchAddress, hProcess, sub_004539D3_4, 004539D3h, 1
	invoke PatchAddress, hProcess, sub_004439E3_4, 004439E3h, 1
	invoke PatchAddress, hProcess, sub_00443960_4, 00443960h, 1
	invoke PatchAddress, hProcess, sub_0058F070_5, 0058F070h, 1
	invoke PatchAddress, hProcess, sub_0044EFFF_5, 0044EFFFh, 1
	invoke PatchAddress, hProcess, sub_0058EF83_5, 0058EF83h, 1
	invoke PatchAddress, hProcess, sub_004539D3_5, 004539D3h, 1
	invoke PatchAddress, hProcess, sub_004439E3_5, 004439E3h, 1
	invoke PatchAddress, hProcess, sub_00443960_5, 00443960h, 1
	invoke PatchAddress, hProcess, sub_0058F070_6, 0058F070h, 1
	invoke PatchAddress, hProcess, sub_0044EFFF_6, 0044EFFFh, 1
	invoke PatchAddress, hProcess, sub_0058EF83_6, 0058EF83h, 1
	invoke PatchAddress, hProcess, sub_004539D3_6, 004539D3h, 1
	invoke PatchAddress, hProcess, sub_004439E3_6, 004439E3h, 1
	invoke PatchAddress, hProcess, sub_00443960_6, 00443960h, 1

	patch_code_cave 005C1E1Fh,  005C1E37h
	invoke PatchAddress, hProcess, sub_0058E3EB, 0058E3EBh, 1
	invoke PatchAddress, hProcess, sub_0058E3EB_1, 0058E3EBh, 1
	invoke PatchAddress, hProcess, sub_0058E3EB_2, 0058E3EBh, 1

	invoke PatchAddress, hProcess, 009A218Ch, DisplayFameIcon, 0
	invoke PatchAddress, hProcess, loc_009A2098, 009A2098h, 1

	invoke PatchAddress, hProcess, 009A2194h, DisplayXPIcon, 0
	invoke PatchAddress, hProcess, loc_009A2098_1, 009A2098h, 1

	ret
PatchFameRestriction endp

; Conversion Restriction
; Allows the ConvertGuardian power/ability to be used on units that do not belong to a treasure

public stdcall PatchConversionRestriction
PatchConversionRestriction proc
	sub esp, 4
	mov word ptr ds:[esp], 9090h
	lea eax, [esp]

	invoke PatchData, hProcess, 009D5B6Ch, eax, 2

	add esp, 4
	ret
PatchConversionRestriction endp

end