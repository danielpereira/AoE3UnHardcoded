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

patch_begin AILimit

code_cave_begin 00603B0Bh
	invoke LoadPersonalities
	mov edi, pUHCInfo
	mov esi, [edi].UHCInfo.PersonalityCount
	mov dword ptr ss:[esp + 040h], esi
	mov esi, [edi].UHCInfo.Personalities
	mov dword ptr ss:[esp + 050h], esi
code_cave_end 00603C4Fh

patch_end AILimit

; Deck limit
; Increases maximum deck card count to 40

patch_begin DeckLimit

code_cave_begin 007EF026h
	mov ecx, pUHCInfo
	mov ecx, [ecx].UHCInfo.DeckCardCount
	cmp eax, ecx
	jle deck_end
	mov eax, ecx
deck_end:
code_cave_end 007EF030h

patch_end DeckLimit

; Pop limit
; Removes maximum base population and extra population limit (refer to PopulationCapExtra in Techtree)

patch_begin PopLimit

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

patch_end PopLimit

; Team limit
; Unlocks team 3 and 4 for both singleplayer and multiplayer

; singleplayer

patch_begin TeamLimit

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

patch_end TeamLimit

; Politician Screen Resource Restriction Patch #1

patch_begin FameRestriction

code_cave_begin 0080E490h
	lea ecx, [esp+28h]
	call_rel32 0058F070h
	push 3
	lea ecx, [esp+34h]
	call_rel32 0044EFFFh
	push ecx
	fstp dword ptr ds:[esp]
	push 3
	lea  ecx, [esp+30h]
	call_rel32 0058EF83h
	mov edx, dword ptr ds:[00C66234h]
	mov ebx, [edx]
	mov ecx, esi
	call_rel32 004539D3h
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
	call_rel32 004439E3h
	push -1
	push -1
	push 00B9FFDCh
	lea ecx, [esp+20h]
	call_rel32 00443960h
	lea ecx, [esp+28h]
	call_rel32 0058F070h
	push 5
	lea ecx, [esp+34h]
	call_rel32 0044EFFFh
	push ecx
	fstp dword ptr ds:[esp]
	push 5
	lea  ecx, [esp+30h]
	call_rel32 0058EF83h
	mov edx, dword ptr ds:[00C66234h]
	mov ebx, [edx]
	mov ecx, esi
	call_rel32 004539D3h
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
	call_rel32 004439E3h
	push -1
	push -1
	push 00B9FFDCh
	lea ecx, [esp+20h]
	call_rel32 00443960h
	lea ecx, [esp+28h]
	call_rel32 0058F070h
	push 6
	lea ecx, [esp+34h]
	call_rel32 0044EFFFh
	push ecx
	fstp dword ptr ds:[esp]
	push 6
	lea  ecx, [esp+30h]
	call_rel32 0058EF83h
	mov edx, dword ptr ds:[00C66234h]
	mov ebx, [edx]
	mov ecx, esi
	call_rel32 004539D3h
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
	call_rel32 004439E3h
	push -1
	push -1
	push 00B9FFDCh
	lea ecx, [esp+20h]
	call_rel32 00443960h
code_cave_end 0080E490h

; Politician Screen Resource Restriction Patch #2

code_cave_begin 0081943Dh
	lea ecx, [esp+28h]
	call_rel32 0058F070h
	push 3
	lea ecx, [esp+34h]
	call_rel32 0044EFFFh
	push ecx
	fstp dword ptr ds:[esp]
	push 3
	lea  ecx, [esp+30h]
	call_rel32 0058EF83h
	mov edx, dword ptr ds:[00C66234h]
	mov ebx, [edx]
	mov ecx, esi
	call_rel32 004539D3h
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
	call_rel32 004439E3h
	push -1
	push -1
	push 00B9FFDCh
	lea ecx, [esp+20h]
	call_rel32 00443960h
	lea ecx, [esp+28h]
	call_rel32 0058F070h
	push 5
	lea ecx, [esp+34h]
	call_rel32 0044EFFFh
	push ecx
	fstp dword ptr ds:[esp]
	push 5
	lea  ecx, [esp+30h]
	call_rel32 0058EF83h
	mov edx, dword ptr ds:[00C66234h]
	mov ebx, [edx]
	mov ecx, esi
	call_rel32 004539D3h
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
	call_rel32 004439E3h
	push -1
	push -1
	push 00B9FFDCh
	lea ecx, [esp+20h]
	call_rel32 00443960h
	lea ecx, [esp+28h]
	call_rel32 0058F070h
	push 6
	lea ecx, [esp+34h]
	call_rel32 0044EFFFh
	push ecx
	fstp dword ptr ds:[esp]
	push 6
	lea  ecx, [esp+30h]
	call_rel32 0058EF83h
	mov edx, dword ptr ds:[00C66234h]
	mov ebx, [edx]
	mov ecx, esi
	call_rel32 004539D3h
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
	call_rel32 004439E3h
	push -1
	push -1
	push 00B9FFDCh
	lea ecx, [esp+20h]
	call_rel32 00443960h
	lea ecx, [esp+28h]
	call_rel32 0058F070h
	push 7
	lea ecx, [esp+34h]
	call_rel32 0044EFFFh
	push ecx
	fstp dword ptr ds:[esp]
	push 7
	lea  ecx, [esp+30h]
	call_rel32 0058EF83h
	mov edx, dword ptr ds:[00C66234h]
	mov ebx, [edx]
	mov ecx, esi
	call_rel32 004539D3h
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
	call_rel32 004439E3h
	push -1
	push -1
	push 00B9FFDCh
	lea ecx, [esp+20h]
	call_rel32 00443960h
code_cave_end 0081943Dh

code_cave_begin 005C1E1Fh
	call_rel32 0058E3EBh
	mov dword ptr ds:[esi+168h],eax
	push -1
	push 0
	push 0
	push hcXpIconPath
	mov ecx,edi
	call_rel32 0058E3EBh
	mov ecx, pUHCInfo
	lea ecx,[ecx].UHCInfo.HCXpIconData
	mov [ecx],eax
	push -1
	push 0
	push 0
	push hcFameIconPath
	mov ecx,edi
	call_rel32 0058E3EBh
	mov ecx, pUHCInfo
	lea ecx,[ecx].UHCInfo.HCFameIconData
	mov [ecx],eax
	push -1
	push 0
	push 0
	push 00BA96C4h
	mov ecx,edi
code_cave_end 005C1E37h

case 009A218Ch
	mov eax, pUHCInfo
	mov eax, [eax].UHCInfo.HCFameIconData
	jmp_rel32 009A2098h
case 009A2194h
	mov eax, pUHCInfo
	mov eax, [eax].UHCInfo.HCXpIconData
	jmp_rel32 009A2098h

patch_end FameRestriction

; Fame Trickling Patch

public stdcall PatchFameTrickle
PatchFameTrickle proc

	invoke PatchAddress, hProcess, 0051B026h, 00BD62F8h, 0

	ret
PatchFameTrickle endp


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