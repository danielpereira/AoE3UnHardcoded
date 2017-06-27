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
	jz team3_mp
	dec eax
	jz team4_mp
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