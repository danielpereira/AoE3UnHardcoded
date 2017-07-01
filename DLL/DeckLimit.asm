code_cave_begin 007EF026h
	mov ecx, _UHCInfoPtr
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