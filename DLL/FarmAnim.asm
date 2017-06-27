; Farm Patch #1
code_cave_begin 004EDA85h
    mov ecx, esi
    mov ecx, [ecx+5Ch]
    test ecx, ecx
    jne fpatch1_null
    or ecx, -1
    jmp fpatch1_check
    
    fpatch1_null:
    mov ecx, [ecx+08h]
    
    fpatch1_check:
    invoke checkID, 0, ecx
    test eax, eax
    jne_rel32 004E3069
    
    fpatch1_rect_farm:
    mov ecx, esi
    mov ecx, [ecx+5Ch]
    test ecx, ecx
    jne fpatch1_not_null_r
    or ecx, -1
    jmp fpatch1_check_r
    
    fpatch1_not_null_r:
    mov ecx, [ecx+08h]
    
    fpatch1_check_r:
    invoke checkID, 1, ecx
    test eax, eax
    je fpatch1_end
    jmp_rel32 006A8A55
    
    fpatch1_end:
    mov ebp, dword ptr ds:[00C66234h]
    mov edx, [ebp+140h]
code_cave_end 004EDA8Bh

;Farm Patch #2
code_cave_begin 0050DE33h
    je_rel32 006A8E67
    mov ecx, edi
    mov ecx, [ecx+5Ch]
    test ecx, ecx
    jne fpatch2_not_null
    or ecx, -1
    jmp fpatch2_check
    
    fpatch2_not_null:
    mov ecx, [ecx+08h]
    
    fpatch2_check:
    invoke checkID, 0, ecx
    test eax, eax
    jne_rel32 006A8E67_1
    
    fpatch2_rect_farm:
    mov ecx, edi
    mov ecx, [ecx+5Ch]
    test ecx, ecx
    jne fpatch2_not_null_r
    or ecx, -1
    jmp fpatch2_check_r
    
    fpatch2_not_null_r:
    mov ecx, [ecx+08h]
    
    fpatch2_check_r:
    invoke checkID, 1, ecx
    test eax, eax
    je_rel32 004EDD6C
    jmp_rel32 0050DF51
code_cave_end 0050DE39h

;Farm Patch #3
code_cave_begin 0073D41Ah
    je fpatch3_sacred_field
    mov edx, eax
    invoke checkID, 0, ebx
    test eax, eax
    jne fpatch3_mill
    invoke checkID, 1, ebx
    test eax, eax
    jne fpatch3_mill
    mov eax, edx
    jmp_rel32 0073D427
    
    fpatch3_mill:
    mov eax, edx
    jmp_rel32 0073D49B
    
    fpatch3_sacred_field:
    mov eax, [eax+5F4Ch]
    jmp_rel32 0073D264
code_cave_end 0073D422h
 
;Farm Patch #4
code_cave_begin 008CEC9Fh
    call_rel32 004E2C50
    invoke checkID, 0, esi
    test eax, eax
    jne_rel32 008CED20
    invoke checkID, 1, esi
    test eax, eax
    jne_rel32 008CED20_1
code_cave_end 008CECA4h

;Farm Patch #5    
code_cave_begin 009DDB79h
    mov ebx, eax
    invoke checkID, 0, ecx
    test eax, eax
    mov eax, ebx
    je fpatch5_back
    xor ebx, ebx
    jmp_rel32 009DDBB4
    
    fpatch5_back:
    xor ebx, ebx
    cmp ecx, [eax+5E58h]
code_cave_end 009DDB7Fh

;Farm Patch #6
code_cave_begin 004EE07Fh
    je_rel32 00586DFF
    invoke checkID, 0, eax
    test eax, eax
    jne_rel32 00586DFF_1
code_cave_end 004EE085h

;Farm Patch #7    
code_cave_begin 004EE2FEh
    je_rel32 00586E11
    mov eax, ebp
    mov eax, [eax+5Ch]
    test eax, eax
    jne fpatch7_not_null
    or eax, -1
    jmp fpatch7_check
    
    fpatch7_not_null:
    mov eax, [eax+08h]
    
    fpatch7_check:
    invoke checkID, 0, eax
    test eax, eax
    jne_rel32 00586E11_1
code_cave_end 004EE304h

;Farm Patch #8     
code_cave_begin 006A8FE1h
    call_rel32 0044CB0A
    cmp eax, ebx
    je_rel32 006A8FEA
    mov edx, eax
    invoke checkID, 0, eax
    test eax, eax
    je_rel32 006A900C
    jmp_rel32 006A8FEA_1
code_cave_end 006A8FE7h

;Rect Farm Patch #1
code_cave_begin 009DDD80h
    mov edx, dword ptr ds:[00C66234h]
    mov ecx, [edi+5Ch]
    mov eax, [edx+140h]
    mov ecx, [ecx+04]
    mov ebp, eax
    invoke checkID, 1, ecx
    test eax, eax
    mov eax, ebp
    jne_rel32 009DDD9E
    jmp_rel32 009DDD92
code_cave_end 009DDD86h

;Rect Farm Patch #2
code_cave_begin 004741F0h
    je_rel32 004743DD
    mov ecx, [ebx+5Ch]
    test ecx, ecx
    jne rpatch2_not_null
    or ecx, -1
    jmp rpatch2_check
    
    rpatch2_not_null:
    mov ecx, [ecx+08]
    
    rpatch2_check:
    invoke checkID, 1, ecx
    test eax, eax
    je_rel32 004741F6
    mov ecx, [ebx+18h]
    mov [esp+14h], ecx
    jmp_rel32 00689BBE
code_cave_end 004741F6h

;Rect Farm Patch #3    
code_cave_begin 004EEDB4h
    mov ecx, [edi+5Ch]
    test ecx, ecx
    jne rpatch3_not_null
    or ecx, -1
    jmp rpatch3_check
    
    rpatch3_not_null:
    mov ecx, [ecx+08]
    
    rpatch3_check:
    invoke checkID, 1, ecx
    test eax, eax
    jne_rel32 004EEE18
    mov ecx, dword ptr ds:[00C66234h]
code_cave_end 004EEDBAh

;Rect Farm Patch #4     
code_cave_begin 004EEE9Eh
    mov ecx, [edi+5Ch]
    test ecx, ecx
    jne rpatch4_not_null
    or ecx, -1
    jmp rpatch4_check
    
    rpatch4_not_null:
    mov ecx, [ecx+08]
    
    rpatch4_check:
    invoke checkID, 1, ecx
    test eax, eax
    jne_rel32 004ED756
    mov ecx, dword ptr ds:[00C66234h]
code_cave_end 004EEEA4h

public stdcall PatchFarmAnim
PatchFarmAnim proc

    patch_code_cave 004EDA85h, 004EDA8Bh
    invoke PatchAddress, _hProcess, loc_004E3069, 004E3069h, 1
    invoke PatchAddress, _hProcess, loc_006A8A55, 006A8A55h, 1
    
    patch_code_cave 0050DE33h, 0050DE39h
    invoke PatchAddress, _hProcess, loc_006A8E67_1, 006A8E67h, 1
    invoke PatchAddress, _hProcess, loc_0050DF51, 0050DF51h, 1
    invoke PatchAddress, _hProcess, loc_006A8E67, 006A8E67h, 1
    invoke PatchAddress, _hProcess, loc_004EDD6C, 004EDD6Ch, 1
    
    patch_code_cave 0073D41Ah, 0073D422h
    invoke PatchAddress, _hProcess, loc_0073D264, 0073D264h, 1
    invoke PatchAddress, _hProcess, loc_0073D427, 0073D427h, 1
    invoke PatchAddress, _hProcess, loc_0073D49B, 0073D49Bh, 1
    
	patch_code_cave 008CEC9Fh, 008CECA4h
    invoke PatchAddress, _hProcess, sub_004E2C50, 004E2C50h, 1
    invoke PatchAddress, _hProcess, loc_008CED20, 008CED20h, 1
    invoke PatchAddress, _hProcess, loc_008CED20_1, 008CED20h, 1

    patch_code_cave 009DDB79h, 009DDB7Fh
    invoke PatchAddress, _hProcess, loc_009DDBB4, 009DDBB4h, 1

    patch_code_cave 004EE07Fh, 004EE085h
    invoke PatchAddress, _hProcess, loc_00586DFF, 00586DFFh, 1
    invoke PatchAddress, _hProcess, loc_00586DFF_1, 00586DFFh, 1
    
    patch_code_cave 004EE2FEh, 004EE304h
    invoke PatchAddress, _hProcess, loc_00586E11, 00586E11h, 1
    invoke PatchAddress, _hProcess, loc_00586E11_1, 00586E11h, 1

    patch_code_cave 006A8FE1h, 006A8FE7h
    invoke PatchAddress, _hProcess, sub_0044CB0A, 0044CB0Ah, 1
    invoke PatchAddress, _hProcess, loc_006A8FEA, 006A8FEAh, 1
    invoke PatchAddress, _hProcess, loc_006A8FEA_1, 006A8FEAh, 1
    invoke PatchAddress, _hProcess, loc_006A900C, 006A900Ch, 1
    
    patch_code_cave 009DDD80h, 009DDD86h
    invoke PatchAddress, _hProcess, loc_009DDD9E, 009DDD9Eh, 1
    invoke PatchAddress, _hProcess, loc_009DDD92, 009DDD92h, 1
    
    patch_code_cave 004741F0h, 004741F6h
    invoke PatchAddress, _hProcess, loc_004743DD, 004743DDh, 1
    invoke PatchAddress, _hProcess, loc_004741F6, 004741F6h, 1
    invoke PatchAddress, _hProcess, loc_00689BBE, 00689BBEh, 1

    patch_code_cave 004EEDB4h, 004EEDBAh
    invoke PatchAddress, _hProcess, loc_004EEE18, 004EEE18h, 1
    
    patch_code_cave 004EEE9Eh, 004EEEA4h
    invoke PatchAddress, _hProcess, loc_004ED756, 004ED756h, 1

	ret
PatchFarmAnim endp