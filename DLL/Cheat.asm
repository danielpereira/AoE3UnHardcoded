.model flat, stdcall
option casemap :none

include UHC.inc

.code

patch_begin Cheat

code_cave_begin 0551FE6h
	mov edi, pUHCInfo
	mov ebx, [edi].UHCInfo.CheatCount
	test ebx, ebx
	je cheat_end
	mov edi, [edi].UHCInfo.Cheats
	dec ebx

cheat_loop:
	mov eax, [edi].UHCCheat.String
	push eax
	lea ecx, [esp+18h]
	mov eax, ebx
	add eax, 24
	mov dword ptr [esp+10h], eax
	mov eax, [edi].UHCCheat.Enable
	mov [esp+14h], eax
	mov eax, 00401A12h
	call eax
	mov esi, dword ptr ds:[00D65604h]
	push 0
	lea edx, [esi+1]
	push edx
	mov ecx, 00D65600h
	mov eax, [edi].UHCCheat.FunctionPtr
	mov dword ptr [esp+20h], eax
	mov eax, 005ACE63h
	call eax
	test al, al
	je cheat_next
	mov eax, [esp+0Ch]
	shl esi, 4
	add esi, dword ptr ds:[00D65600h]
	lea edx, [esp+14h]
	mov [esi], eax
	mov ecx, [esp+10h]
	mov [esi+04h], ecx
	push edx
	lea ecx, [esi+08]
	mov eax, 0040196Fh
	call eax
	mov ecx, [esp+18h]
	mov [esi+0Ch], ecx

cheat_next:
	lea ecx, [esp+14h]
	mov eax, 004010CAh
	call eax
    
	add edi, UHCCheat
	dec ebx
	jns cheat_loop

cheat_end:
code_cave_end 0551FE6h

patch_end Cheat

end