format PE GUI 4.0 DLL at 0x00400000 as 'dll'
entry DllEntryPoint

;==================================================
; Includes
;==================================================

include 'win32a.inc'

struc db [data]
{
	common . db data 
	sizeof.#. = $ - .
}

;==================================================
section '.text' code readable executable
;==================================================

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved

	mov	eax,dword[fdwReason]
	dec	eax
	jz	.DllMain
	push	TRUE
	pop	eax
	jmp	.end
	.DllMain:
	stdcall DllMain,dword[hinstDLL],1,dword[lpvReserved]
	.end:
	ret
endp

proc DllMain hinstDLL,fdwReason,lpvReserved

	push	esi edi ebx
    
    invoke LoadLibrary,_config
    invoke GetProcAddress,eax,_funcname
    mov dword[UHCInitInfo],eax
    invoke HeapCreate,0,0,0
    mov [_HeapHandle],eax
    push eax
    push _ConfigPath
    call dword[UHCInitInfo]
    add esp,8
    test eax,eax
    jne .cfg_loaded
    
    mov [_UHCInfoPtr],0
    jmp .end
    
    .cfg_loaded:
    mov eax,[eax+04]
    mov [_UHCInfoPtr],eax
    
    invoke	GetCurrentProcess
	mov	esi,eax
    mov edi,1
    
    stdcall PatchCodeCave,esi,0x005EE78B,loc_005EE78B,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_005A2346,0x005A2346,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_005EE791,0x005EE791,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x004EDA85,loc_004EDA85,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004E3069,0x004E3069,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004EDA8B,0x004EDA8B,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_006A8A55,0x006A8A55,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x0050DE33,loc_050DE33,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_006A8E67_1,0x006A8E67,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_0050DF51,0x0050DF51,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_006A8E67,0x006A8E67,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004EDD6C,0x004EDD6C,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x0073D41A,loc_0073D41A,8
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_0073D264,0x0073D264,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_0073D427,0x0073D427,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_0073D49B,0x0073D49B,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x008CEC9F,loc_008CEC9F,5
	and	edi,eax
    
    stdcall PatchAddress,esi,sub_004E2C50,0x004E2C50,1
    and	edi,eax
    
    stdcall PatchAddress,esi,loc_008CED20,0x008CED20,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_008CECA4,0x008CECA4,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_008CED20_1,0x008CED20,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x009DDB79,loc_009DDB79,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_009DDBB4,0x009DDBB4,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_009DDB7F,0x009DDB7F,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x004EE07F,loc_004EE07F,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_00586DFF,0x00586DFF,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_00586DFF_1,0x00586DFF,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004EE085,0x004EE085,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x004EE2FE,loc_004EE2FE,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_00586E11,0x00586E11,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_00586E11_1,0x00586E11,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004EE304,0x004EE304,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x006A8FE1,loc_006A8FE1,6
	and	edi,eax
    
    stdcall PatchAddress,esi,sub_0044CB0A,0x0044CB0A,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_006A8FEA,0x006A8FEA,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_006A8FEA_1,0x006A8FEA,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_006A900C,0x006A900C,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x009DDD80,loc_009DDD80,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_009DDD9E,0x009DDD9E,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_009DDD92,0x009DDD92,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x004741F0,loc_004741F0,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004743DD,0x004743DD,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004741F6,0x004741F6,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_00689BBE,0x00689BBE,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x004EEDB4,loc_004EEDB4,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004EEE18,0x004EEE18,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004EEDBA,0x004EEDBA,1
	and	edi,eax
    
    stdcall PatchCodeCave,esi,0x004EEE9E,loc_004EEE9E,6
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004ED756,0x004ED756,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_004EEEA4,0x004EEEA4,1
	and	edi,eax
    
	mov	eax,edi
    
    .end:
	pop	ebx edi esi
	ret
	
endp

loc_005EE78B:
    mov edi,[esi+140h]
    mov ecx,edi
    stdcall getIDs,0
    mov ecx,edi
    stdcall getIDs,1
    mov edi,[esi+140h]
    jmp near $
    loc_005EE791 = $-4

loc_004EDA85:    
    mov ecx,esi
    mov ecx,[ecx+5Ch]
    test ecx,ecx
    jne .null
    or ecx,-1
    jmp .check
    
    .null:
    mov ecx,[ecx+08h]
    
    .check:
    stdcall checkID,0,ecx
    test eax,eax
    jne near $
    loc_004E3069 = $-4
    
    .rect_farm:
    mov ecx,esi
    mov ecx,[ecx+5Ch]
    test ecx,ecx
    jne .not_null_r
    or ecx,-1
    jmp .check_r
    
    .not_null_r:
    mov ecx,[ecx+08h]
    
    .check_r:
    stdcall checkID,1,ecx
    test eax,eax
    je .end
    jmp near $
    loc_006A8A55 = $-4
    
    .end:
    mov ebp,[00C66234h]
    mov edx,[ebp+140h]
    jmp near $
    loc_004EDA8B = $-4
    
loc_050DE33:
    je near $
    loc_006A8E67_1 = $-4
    mov ecx,edi
    mov ecx,[ecx+5Ch]
    test ecx,ecx
    jne .not_null
    or ecx,-1
    jmp .check
    
    .not_null:
    mov ecx,[ecx+08h]
    
    .check:
    stdcall checkID,0,ecx
    test eax,eax
    jne near $
    loc_006A8E67 = $-4
    
    .rect_farm:
    mov ecx,edi
    mov ecx,[ecx+5Ch]
    test ecx,ecx
    jne .not_null_r
    or ecx,-1
    jmp .check_r
    
    .not_null_r:
    mov ecx,[ecx+08h]
    
    .check_r:
    stdcall checkID,1,ecx
    test eax,eax
    je near $
    loc_004EDD6C = $-4
    jmp near $
    loc_0050DF51 = $-4

loc_0073D41A:
    je .sacred_field
    mov edx,eax
    stdcall checkID,0,ebx
    test eax,eax
    jne .mill
    stdcall checkID,1,ebx
    test eax,eax
    jne .mill
    mov eax,edx
    jmp near $
    loc_0073D427 = $-4
    
    .mill:
    mov eax,edx
    jmp near $
    loc_0073D49B = $-4
    
    .sacred_field:
    mov eax,[eax+5F4Ch]
    jmp near $
    loc_0073D264 = $-4
 
loc_008CEC9F:
    call near $
    sub_004E2C50 = $-4
    stdcall checkID,0,esi
    test eax,eax
    jne near $
    loc_008CED20 = $-4
    stdcall checkID,1,esi
    test eax,eax
    je near $
    loc_008CECA4 = $-4
    jmp near $
    loc_008CED20_1 = $-4
    
    
loc_009DDB79:
    mov ebx,eax
    stdcall checkID,0,ecx
    test eax,eax
    mov eax,ebx
    je .back
    xor ebx,ebx
    jmp near $
    loc_009DDBB4 = $-4
    
    .back:
    xor ebx,ebx
    cmp ecx,[eax+5E58h]
    jmp near $
    loc_009DDB7F = $-4
    
    
loc_004EE07F:
    je near $
    loc_00586DFF = $-4
    stdcall checkID,0,eax
    test eax,eax
    je near $
    loc_004EE085 = $-4
    jmp near $
    loc_00586DFF_1 = $-4
    
    
loc_004EE2FE:
    je near $
    loc_00586E11 = $-4
    mov eax,ebp
    mov eax,[eax+5Ch]
    test eax,eax
    jne .not_null
    or eax,-1
    jmp .check
    
    .not_null:
    mov eax,[eax+08h]
    
    .check:
    stdcall checkID,0,eax
    test eax,eax
    je near $
    loc_004EE304 = $-4
    jmp near $
    loc_00586E11_1 = $-4
    
    
loc_006A8FE1:

    call near $
    sub_0044CB0A = $-4
    cmp eax,ebx
    je near $
    loc_006A8FEA = $-4
    mov edx,eax
    stdcall checkID,0,eax
    test eax,eax
    je near $
    loc_006A900C = $-4
    jmp near $
    loc_006A8FEA_1 = $-4

loc_009DDD80:

    mov edx,[00C66234h]
    mov ecx,[edi+5Ch]
    mov eax,[edx+140h]
    mov ecx,[ecx+04]
    mov ebp,eax
    stdcall checkID,1,ecx
    test eax,eax
    mov eax,ebp
    jne near $
    loc_009DDD9E = $-4
    jmp near $
    loc_009DDD92 = $-4
    
loc_004741F0:

    je near $
    loc_004743DD = $-4
    mov ecx,[ebx+5Ch]
    test ecx,ecx
    jne .not_null
    or ecx,-1
    jmp .check
    
    .not_null:
    mov ecx,[ecx+08]
    
    .check:
    stdcall checkID,1,ecx
    test eax,eax
    je near $
    loc_004741F6 = $-4
    mov ecx,[ebx+18h]
    mov [esp+14h],ecx
    jmp near $
    loc_00689BBE = $-4
    
loc_004EEDB4:

    mov ecx,[edi+5Ch]
    test ecx,ecx
    jne .not_null
    or ecx,-1
    jmp .check
    
    .not_null:
    mov ecx,[ecx+08]
    
    .check:
    stdcall checkID,1,ecx
    test eax,eax
    jne near $
    loc_004EEE18 = $-4
    mov ecx,[00C66234h]
    jmp near $
    loc_004EEDBA = $-4
    
loc_004EEE9E:

    mov ecx,[edi+5Ch]
    test ecx,ecx
    jne .not_null
    or ecx,-1
    jmp .check
    
    .not_null:
    mov ecx,[ecx+08]
    
    .check:
    stdcall checkID,1,ecx
    test eax,eax
    jne near $
    loc_004ED756 = $-4
    mov ecx,[00C66234h]
    jmp near $
    loc_004EEEA4 = $-4

;--------------------------------------------------

proc checkID type,unitID

    push edi esi ebx
    mov ebx,12
    mov eax,dword[type]
    imul ebx,eax
    mov eax,[_UHCInfoPtr]
    lea eax,[eax+ebx]
    mov ebx,dword[eax]
    test ebx,ebx
    je .end
    
    mov esi,dword[eax+08]
    mov edi,dword[unitID]
    dec ebx
    
    .loop:
    cmp edi,dword[esi+ebx*4]
    je .valid_id
    dec ebx
    cmp ebx,0
    jge .loop
    jmp .end
    
    .valid_id:
    mov eax,1
    pop ebx esi edi
    ret
    
    .end:
    xor eax,eax
    pop ebx esi edi
    ret
    
endp

proc getIDs type

    push edi esi ebx
    mov ebx,12
    mov esi,ecx
    mov edi,dword[type]
    imul ebx,edi
    mov edi,[_UHCInfoPtr]
    lea edi,[edi+ebx]
    mov ebx,[edi]
    test ebx,ebx
    je .end
    
    dec ebx
    
    .loop:
    mov eax,[edi+04]
    mov eax,[eax+ebx*4]
    push eax
    mov ecx,esi
    call near $
    loc_005A2346 = $-4
    mov ecx,[edi+08]
    mov [ecx+ebx*4],eax
    dec ebx
    cmp ebx,0
    jge .loop
    
    .end:
    pop ebx esi edi
    ret

endp

;--------------------------------------------------

proc memset c ptr,value,num

        mov     ecx,dword[num]
        jecxz	.end
        push    edi
        mov     eax,dword[value]
        mov     ah,al
        mov     dx,ax
        shl     eax,16
        mov     ax,dx
        mov     edi,dword[ptr]
        mov     edx,ecx
        shr     ecx,2
        rep     stosd
        mov     ecx,edx
        and     ecx,3
        rep     stosb
        pop     edi
        .end:              
        mov     eax,dword[ptr]
        ret
endp

proc PatchAddress hProcess,lpBaseAddress,lpDestAddress,bRelAddr

        push    ebx
        mov     eax,dword[lpBaseAddress]
        lea     ecx,[eax+4]
        lea     edx,[lpDestAddress]
        neg     dword[bRelAddr]
        sbb     ebx,ebx
        and     ecx,ebx
        sub     dword[edx],ecx
        stdcall PatchData,dword[hProcess],eax,edx,4
        pop     ebx
        ret
endp

proc PatchData hProcess,lpBaseAddress,lpBuffer,nSize

        push    ebx esi edi
        mov     ebx,dword[nSize]
        mov     esi,dword[lpBaseAddress]
        mov     edi,dword[lpBuffer]
        xor     eax,eax
        cmp     ebx,eax
        je      .end
        lea     eax,[nSize]
        invoke  VirtualProtectEx,dword[hProcess],esi,ebx,PAGE_EXECUTE_READWRITE,eax
        test    eax,eax
        jz      .end
        invoke  WriteProcessMemory,dword[hProcess],esi,edi,ebx,0
        mov     edi,eax
        lea     eax,[nSize]
        invoke  VirtualProtectEx,dword[hProcess],esi,ebx,dword[eax],eax
        test    eax,eax
        jz      .end
        test    edi,edi
        setnz   cl
        movzx   eax,cl
        .end:
        pop     edi esi ebx
        ret
endp

proc PatchCodeCave hProcess,lpBaseAddress,lpDestProc,nSize

        push    ebx esi edi
        mov     ebx,dword[nSize]
        xor     eax,eax
        cmp     ebx,5
        jb      .end
        mov     esi,dword[lpBaseAddress]
        mov     edi,dword[hProcess]
        lea     eax,[nSize]
        mov     byte[eax],0xE9
        stdcall PatchData,edi,esi,eax,1
        test    eax,eax
        jz      .end
        inc     esi
        stdcall PatchAddress,edi,esi,dword[lpDestProc],1
        test    eax,eax
        jz      .end
        sub     ebx,5
        jz      .end
        add     esi,4
        mov     byte[nSize],0x90
        .loop:
        lea     eax,[nSize]
        stdcall PatchData,edi,esi,eax,1
        test    eax,eax
        jz      .end
        inc     esi
        dec     ebx
        jnz     .loop
        .end:
        pop     edi esi ebx
        ret
endp

	
;==================================================
section '.idata' import data readable
;==================================================

library advapi32,'ADVAPI32.DLL',\
	comctl32,'COMCTL32.DLL',\
	comdlg32,'COMDLG32.DLL',\
	gdi32,'GDI32.DLL',\
	kernel32,'KERNEL32.DLL',\
	shell32,'SHELL32.DLL',\
	user32,'USER32.DLL',\
	wsock32,'WSOCK32.DLL'

include 'api\advapi32.inc'
include 'api\comctl32.inc'
include 'api\comdlg32.inc'
include 'api\gdi32.inc'
include 'api\kernel32.inc'
include 'api\shell32.inc'
include 'api\user32.inc'
include 'api\wsock32.inc'

;==================================================
section '.data' data readable writeable
;==================================================

UHCInitInfo dd 0

_UHCInfoPtr dd 0

; _UnitAmount dd 0
; _UnitNameArrayPtr dd 0
; _UnitIDArrayPtr dd 0
; _RectUnitAmount dd 0
; _RectUnitNameArrayPtr dd 0
; _RectUnitIDArrayPtr dd 0


_config db 'uhc.dll',0

_funcname db 'UHCInitInfo',0

_XPRevolution db 'XPRevolution',0
_Path du 'ui\ingame\politicians\REV_banner_',0

_ConfigPath du 'Startup\uhc.cfg',0

_HeapHandle dd 0

_pathtmp db 208 dup 0x00

;==================================================
section '.rsrc' resource readable
;==================================================

directory RT_VERSION,versions

resource versions,\
    1,LANG_NEUTRAL,version
versioninfo version,VOS__WINDOWS32,VFT_APP,VFT2_UNKNOWN,LANG_ENGLISH+SUBLANG_DEFAULT,0,\
	'FileDescription','Library to enable extra AIs for AoE3 Mods',\
	'FileVersion','1.0',\
    'ProductName', 'AoE3 AI Library for mods',\
	'ProductVersion','1.0',\
	'OriginalFilename','AI.DLL'
        
;==================================================
section '.reloc' fixups data readable discardable
;==================================================

if ~ $-$$
	dd 0,8
end if
