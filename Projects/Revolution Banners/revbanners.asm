format PE GUI 4.0 DLL at 0x00400000 as 'dll'
entry DllEntryPoint

;==================================================
; Includes
;==================================================

include 'win32a.inc'

;# made by Tomasz Grysztar
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

	push	esi edi
	invoke	GetCurrentProcess
	mov	esi,eax
	mov	edi,1
	
    stdcall PatchCodeCave,esi,0x0081A64F,NewRevs,5
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_0081a7ec,0x0081a7ec,1
	and	edi,eax
    
    stdcall PatchAddress,esi,sub_00401a12,0x00401a12,1
	and	edi,eax
    
    stdcall PatchAddress,esi,sub_00638823,0x00638823,1
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_0081a7ec_1,0x0081a7ec,1
	and	edi,eax
    
	mov	eax,edi
	pop	edi esi
	ret
	
endp
NewRevs:

    mov edi,_XPRevolution ; "XPRevolution"
    mov esi, eax
    mov ecx,0ch ; length of "XPRevolution"
    xor edx,edx ; ignored?
    repe cmpsb
    jne near $
    loc_0081a7ec = $-4
    ;sub esp, 208h
    stdcall memset,_pathtmp,0,208h
    add esp,0Ch
    push _Path ; unicode "ui\ingame\politicians\REV_banner_"
    lea eax,[_pathtmp]
    push eax
    call dword[00b84290h] ; lstrcpyW
    push esi
    call dword[00b843ach] ; lstrlenA
    push eax
    lea eax,[_pathtmp+42h]
    push eax
    push 0ffffffffh
    push esi
    push 0h
    push 0h
    call dword[00b841fch] ; MultiByteToWideChar
    push _pathtmp
    lea ecx, [esp+2ch]
    call near $
    sub_00401a12 = $-4
    ;add esp,208h
    lea eax, [esp + 28h]
    push eax
    mov ecx,ebp
    call near $
    sub_00638823 = $-4
    lea ecx, [esp + 28h]
    jmp near $
    loc_0081a7ec_1 = $-4

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

_XPRevolution db 'XPRevolution',0
_Path du 'ui\ingame\politicians\REV_banner_',0
dd 0

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
