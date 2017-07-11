.model flat, stdcall
option casemap :none

include UHC.inc

extern pUHCInfo:UHCInfoPtr
extern hProcess:DWORD

TableIDExists proto stdcall dwType:DWORD, id:DWORD

.code

getIDs PROC stdcall dwType:DWORD
    push edi
	push esi
	push ebx
    mov ebx, UHCRefTable
    mov esi, ecx
    mov edi, dwType
    imul ebx, edi
    mov edi, pUHCInfo
	lea edi, [edi].UHCInfo.Tables
    lea edi, [edi+ebx]
    mov ebx, [edi].UHCRefTable.RefCount
    test ebx, ebx
    je getids_end
    
    dec ebx
    
getids_loop:
    mov eax, [edi].UHCRefTable.Refs
    mov eax, [eax+ebx*4]
    push eax
    mov ecx, esi
    mov eax,  005A2346h
	call eax
    mov ecx, [edi].UHCRefTable.RefIDs
    mov [ecx+ebx*4], eax
    dec ebx
    jns getids_loop
    
getids_end:
    pop ebx
	pop esi
	pop edi
    ret

getIDs ENDP

getFarmRadiusData PROC stdcall id:DWORD
	push edi
	push esi
	push ebx
	xor eax,eax
	mov edi, pUHCInfo
	mov ecx,[edi].UHCInfo.FarmRadiusInfoCount
	test ecx,ecx
	je getfarmradiusdata_end
	mov ebx, UHCRefTable
	lea esi,[edi].UHCInfo.Tables
	imul ebx,FARM
	lea esi,[esi+ebx]
	mov ecx,[esi]
	test ecx,ecx
	je getfarmradiusdata_end
	mov ebx,id
	mov esi,[esi+08]
	dec ecx

getfarmradiusdata_loop1:
	mov edx,[esi+ecx*4]
	cmp edx,ebx
	je getfarmradiusdata_loop_end
	dec ecx
	jns getfarmradiusdata_loop1
	jmp getfarmradiusdata_end

getfarmradiusdata_loop_end:
	mov ebx,ecx
	inc ebx
	mov ecx,[edi].UHCInfo.FarmRadiusInfoCount
	mov edi,[edi].UHCInfo.FarmRadiusInfo
	dec ecx

getfarmradiusdata_loop2:
	mov esi,[edi]
	cmp esi,ebx
	je getfarmradiusdata_loop2_found
	add edi,UHCFarmRadius
	dec ecx
	jns getfarmradiusdata_loop2
	jmp getfarmradiusdata_end

getfarmradiusdata_loop2_found:
	mov eax,edi	

getfarmradiusdata_end:
	pop ebx
	pop esi
	pop edi
	ret

getFarmRadiusData ENDP

; Farm animation
; Enable user-created buildings to play farming animations

; Farm Patch #1
code_cave_begin 004EDA85h
    mov ecx, esi
    mov ecx, [ecx+5Ch]
    test ecx, ecx
    jne farm_patch1_null
    or ecx, -1
    jmp farm_patch1_check
    
farm_patch1_null:
    mov ecx, [ecx+08h]
    
farm_patch1_check:
    invoke TableIDExists, FARM, ecx
    test eax, eax
    jne_rel32 004E3069
    
farm_patch1_rect_farm:
    mov ecx, esi
    mov ecx, [ecx+5Ch]
    test ecx, ecx
    jne farm_patch1_not_null_r
    or ecx, -1
    jmp farm_patch1_check_r
    
farm_patch1_not_null_r:
    mov ecx, [ecx+08h]
    
farm_patch1_check_r:
    invoke TableIDExists, RECTFARM, ecx
    test eax, eax
    je farm_patch1_end
    jmp_rel32 006A8A55
    
farm_patch1_end:
    mov ebp, dword ptr ds:[00C66234h]
    mov edx, [ebp+140h]
code_cave_end 004EDA8Bh

;Farm Patch #2
code_cave_begin 0050DE33h
    je_rel32 006A8E67
    mov ecx, edi
    mov ecx, [ecx+5Ch]
    test ecx, ecx
    jne farm_patch2_not_null
    or ecx, -1
    jmp farm_patch2_check
    
farm_patch2_not_null:
    mov ecx, [ecx+08h]
    
farm_patch2_check:
    invoke TableIDExists, FARM, ecx
    test eax, eax
    jne_rel32 006A8E67_1
    
farm_patch2_rect_farm:
    mov ecx, edi
    mov ecx, [ecx+5Ch]
    test ecx, ecx
    jne farm_patch2_not_null_r
    or ecx, -1
    jmp farm_patch2_check_r
    
farm_patch2_not_null_r:
    mov ecx, [ecx+08h]
    
farm_patch2_check_r:
    invoke TableIDExists, RECTFARM, ecx
    test eax, eax
    je_rel32 004EDD6C
    jmp_rel32 0050DF51
code_cave_end 0050DE39h

;Farm Patch #3
code_cave_begin 0073D41Ah
    je farm_patch3_sacred_field
    invoke TableIDExists, FARM, ebx
    test eax, eax
    jne farm_patch3_mill
    invoke TableIDExists, RECTFARM, ebx
    test eax, eax
    jne farm_patch3_mill
    mov eax, dword ptr ds:[00C66234h]
	mov eax, dword ptr [eax+140h]
    jmp_rel32 0073D427
    
farm_patch3_mill:
    mov eax, dword ptr ds:[00C66234h]
	mov eax, dword ptr [eax+140h]
    jmp_rel32 0073D49B
    
farm_patch3_sacred_field:
    mov eax, [eax+5F4Ch]
    jmp_rel32 0073D264
code_cave_end 0073D422h
 
;Farm Patch #4
code_cave_begin 008CEC9Fh
    call_rel32 004E2C50
    invoke TableIDExists, FARM, esi
    test eax, eax
    jne_rel32 008CED20
    invoke TableIDExists, RECTFARM, esi
    test eax, eax
    jne_rel32 008CED20_1
code_cave_end 008CECA4h

;Farm Patch #5    
code_cave_begin 009DDB79h
    invoke TableIDExists, FARM, ecx
    test eax, eax
	mov eax, dword ptr ds:[00C66234h]
	mov eax,[eax+140h]
	mov ecx,[edi+5Ch]
	mov ecx,[ecx+4]
    je farm_patch5_back
    jmp_rel32 009DDBB4
    
farm_patch5_back:
    cmp ecx, [eax+5E58h]
code_cave_end 009DDB7Fh

;Farm Patch #6
code_cave_begin 004EE07Fh
    je_rel32 00586DFF
    invoke TableIDExists, FARM, eax
    test eax, eax
    jne_rel32 00586DFF_1
code_cave_end 004EE085h

;Farm Patch #7    
code_cave_begin 004EE2FEh
    je_rel32 00586E11
    mov eax, ebp
    mov eax, [eax+5Ch]
    test eax, eax
    jne farm_patch7_not_null
    or eax, -1
    jmp farm_patch7_check
    
farm_patch7_not_null:
    mov eax, [eax+08h]
    
farm_patch7_check:
    invoke TableIDExists, FARM, eax
    test eax, eax
    jne_rel32 00586E11_1
code_cave_end 004EE304h

;Farm Patch #8     
code_cave_begin 006A8FE1h
    call_rel32 0044CB0A
    cmp eax, ebx
    je_rel32 006A8FEA
    mov edx, eax
    invoke TableIDExists, FARM, eax
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
    invoke TableIDExists, RECTFARM, ecx
    test eax, eax
	mov ecx, [edi+5Ch]
	mov ecx, [ecx+04]
	mov edx, dword ptr ds:[00C66234h]
	mov eax, [edx+140h]
    jne_rel32 009DDD9E
    jmp_rel32 009DDD92
code_cave_end 009DDD86h

;Rect Farm Patch #2
code_cave_begin 004741F0h
    je_rel32 004743DD
    mov ecx, [ebx+5Ch]
    test ecx, ecx
    jne rect_farm_patch2_not_null
    or ecx, -1
    jmp rect_farm_patch2_check
    
rect_farm_patch2_not_null:
    mov ecx, [ecx+08]
    
rect_farm_patch2_check:
    invoke TableIDExists, RECTFARM, ecx
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
    jne rect_farm_patch3_not_null
    or ecx, -1
    jmp rect_farm_patch3_check
    
rect_farm_patch3_not_null:
    mov ecx, [ecx+08]
    
rect_farm_patch3_check:
    invoke TableIDExists, RECTFARM, ecx
    test eax, eax
    jne_rel32 004EEE18
    mov ecx, dword ptr ds:[00C66234h]
code_cave_end 004EEDBAh

;Rect Farm Patch #4     
code_cave_begin 004EEE9Eh
    mov ecx, [edi+5Ch]
    test ecx, ecx
    jne rect_farm_patch4_not_null
    or ecx, -1
    jmp rect_farm_patch4_check
    
rect_farm_patch4_not_null:
    mov ecx, [ecx+08]
    
rect_farm_patch4_check:
    invoke TableIDExists, RECTFARM, ecx
    test eax, eax
    jne_rel32 004ED756
    mov ecx, dword ptr ds:[00C66234h]
code_cave_end 004EEEA4h

public stdcall PatchFarmAnim
PatchFarmAnim proc

    patch_code_cave 004EDA85h, 004EDA8Bh
    invoke PatchAddress, hProcess, loc_004E3069, 004E3069h, 1
    invoke PatchAddress, hProcess, loc_006A8A55, 006A8A55h, 1
    
    patch_code_cave 0050DE33h, 0050DE39h
    invoke PatchAddress, hProcess, loc_006A8E67_1, 006A8E67h, 1
    invoke PatchAddress, hProcess, loc_0050DF51, 0050DF51h, 1
    invoke PatchAddress, hProcess, loc_006A8E67, 006A8E67h, 1
    invoke PatchAddress, hProcess, loc_004EDD6C, 004EDD6Ch, 1
    
    patch_code_cave 0073D41Ah, 0073D422h
    invoke PatchAddress, hProcess, loc_0073D264, 0073D264h, 1
    invoke PatchAddress, hProcess, loc_0073D427, 0073D427h, 1
    invoke PatchAddress, hProcess, loc_0073D49B, 0073D49Bh, 1
    
	patch_code_cave 008CEC9Fh, 008CECA4h
    invoke PatchAddress, hProcess, sub_004E2C50, 004E2C50h, 1
    invoke PatchAddress, hProcess, loc_008CED20, 008CED20h, 1
    invoke PatchAddress, hProcess, loc_008CED20_1, 008CED20h, 1

    patch_code_cave 009DDB79h, 009DDB7Fh
    invoke PatchAddress, hProcess, loc_009DDBB4, 009DDBB4h, 1

    patch_code_cave 004EE07Fh, 004EE085h
    invoke PatchAddress, hProcess, loc_00586DFF, 00586DFFh, 1
    invoke PatchAddress, hProcess, loc_00586DFF_1, 00586DFFh, 1
    
    patch_code_cave 004EE2FEh, 004EE304h
    invoke PatchAddress, hProcess, loc_00586E11, 00586E11h, 1
    invoke PatchAddress, hProcess, loc_00586E11_1, 00586E11h, 1

    patch_code_cave 006A8FE1h, 006A8FE7h
    invoke PatchAddress, hProcess, sub_0044CB0A, 0044CB0Ah, 1
    invoke PatchAddress, hProcess, loc_006A8FEA, 006A8FEAh, 1
    invoke PatchAddress, hProcess, loc_006A8FEA_1, 006A8FEAh, 1
    invoke PatchAddress, hProcess, loc_006A900C, 006A900Ch, 1
    
    patch_code_cave 009DDD80h, 009DDD86h
    invoke PatchAddress, hProcess, loc_009DDD9E, 009DDD9Eh, 1
    invoke PatchAddress, hProcess, loc_009DDD92, 009DDD92h, 1
    
    patch_code_cave 004741F0h, 004741F6h
    invoke PatchAddress, hProcess, loc_004743DD, 004743DDh, 1
    invoke PatchAddress, hProcess, loc_004741F6, 004741F6h, 1
    invoke PatchAddress, hProcess, loc_00689BBE, 00689BBEh, 1

    patch_code_cave 004EEDB4h, 004EEDBAh
    invoke PatchAddress, hProcess, loc_004EEE18, 004EEE18h, 1
    
    patch_code_cave 004EEE9Eh, 004EEEA4h
    invoke PatchAddress, hProcess, loc_004ED756, 004ED756h, 1

	ret
PatchFarmAnim endp

; Farm Radius
; Allows user-created mill-like buildings to have a custom settler walking radius

code_cave_begin 009DE04Dh
	mov ecx,[edi+5Ch]
	mov ecx,[ecx+4]
	invoke getFarmRadiusData,ecx
	test eax,eax
	je fr_patch_back
	mov edx,eax
	mov ecx,[edx+04]
	push ecx
	push ebp
	push 2
	mov ecx,00C66588h
	call_rel32 00422648
	fstp dword ptr [esp+14h]
	mov edx,[edx+08]
	jmp_rel32 009DE06B

fr_patch_back:
	mov ecx,ds:[00C0BBE0h]
code_cave_end 009DE053h

public stdcall PatchFarmRadius
PatchFarmRadius proc
	
	patch_code_cave 009DE04Dh, 009DE053h
	invoke PatchAddress, hProcess, sub_00422648, 00422648h, 1
	invoke PatchAddress, hProcess, loc_009DE06B, 009DE06Bh, 1

	ret

PatchFarmRadius endp


; Market
; Allows user-created buildings to use market features

marketCheck PROC stdcall
    push ebx
	push edi
    mov ebx,  UHCRefTable
    imul ebx,  MARKET
    mov edi, [pUHCInfo]
	lea edi, [edi].UHCInfo.Tables
    lea edi, [edi+ebx]
    mov ebx, [edi].UHCRefTable.RefCount
    test ebx, ebx
    je marketcheck_invalid_id
    dec ebx
    mov edi, [edi].UHCRefTable.RefIDs
    
marketcheck_loop:
    mov eax, [edi+ebx*4]
    mov edx, [esp+1Ch]
    mov ecx, [esi+80h]
    push 0
    push 2
    push eax
    push edx
    mov eax,  004C846Dh
	call eax
    test eax, eax
    jg marketcheck_valid_id
    dec ebx
    jns marketcheck_loop
    
marketcheck_invalid_id:
    xor eax, eax
    pop edi
	pop ebx
    ret
    
marketcheck_valid_id:
    mov eax, 1
    pop edi
	pop ebx
    ret
marketCheck ENDP

code_cave_begin 007DEF70h
    invoke marketCheck
    test eax, eax
    jne_rel32 007DEFC3
    mov edx, dword ptr ds:[00C66234h]
    mov ecx, [esi+80h]
    jmp_rel32 007DEF76
code_cave_end 007DEF75h

public stdcall PatchMarketUnits
PatchMarketUnits proc
	patch_code_cave 007DEF70h,  007DEF75h
	invoke PatchAddress, hProcess, loc_007DEFC3, 007DEFC3h, 1
	invoke PatchAddress, hProcess, loc_007DEF76, 007DEF76h, 1
	ret
PatchMarketUnits endp


; Tactic Switching
; Allows user-created buildings to switch tactics implemented through protounicommands

code_cave_begin 005C161Ch
	je_rel32 005C10F1
	invoke TableIDExists, TACTIC_SWITCHING, eax
	test eax,eax
	jne_rel32 005C1A73
code_cave_end 005C1622h

code_cave_begin 006949CDh
	mov ecx,esi
	call_rel32 0044CB0A_1
	invoke TableIDExists, TACTIC_SWITCHING, eax
	test eax,eax
	jne_rel32 00694CD4
	mov eax, dword ptr ds:[00C66234h]
code_cave_end 006949D2h

public stdcall PatchTacticSwitching
PatchTacticSwitching proc
	patch_code_cave 005C161Ch, 005C1622h
	invoke PatchAddress, hProcess, loc_005C10F1, 005C10F1h, 1
	invoke PatchAddress, hProcess, loc_005C1A73, 005C1A73h, 1

	patch_code_cave 006949CDh, 006949D2h
	invoke PatchAddress, hProcess, sub_0044CB0A_1, 0044CB0Ah, 1
	invoke PatchAddress, hProcess, loc_00694CD4, 00694CD4h, 1
	ret
PatchTacticSwitching endp

; Unit check
; Get farm and market IDs

code_cave_begin 005EE78Bh
	mov edi,  [esi+140h]
	mov ecx, edi
	invoke getIDs, FARM
	mov ecx, edi
	invoke getIDs, RECTFARM
	mov ecx, edi
	invoke getIDs, MARKET
	mov ecx, edi
	invoke getIDs, NO_BIGBUTTON_BLDS
	mov ecx, edi
	invoke getIDs, TACTIC_SWITCHING
code_cave_end 005EE78Bh

public stdcall PatchUnitCheck
PatchUnitCheck proc
	patch_code_cave 005EE78Bh,  005EE78Bh
	retn
PatchUnitCheck endp

end