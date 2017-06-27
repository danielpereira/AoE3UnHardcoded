code_cave_begin 004581F3h
	mov esi, _UHCInfoPtr
	mov esi, [esi].UHCInfo.ExtraPop
	cmp ecx, esi
	jle check_base_pop
	mov ecx, esi
check_base_pop:
	mov esi, _UHCInfoPtr
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