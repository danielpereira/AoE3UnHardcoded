.model flat, stdcall
option casemap :none

include UHC.inc

extern pUHCInfo:UHCInfoPtr
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

; Fame Restriction Removal
; Allows using the 'Fame' resource for ProtoActions, like AutoGather or ModifyGather

public stdcall PatchFameRestriction
PatchFameRestriction proc
	invoke PatchAddress, hProcess, 0051B026h, 00BD62F8h, 0
	ret
PatchFameRestriction endp

end