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
	
    ;invoke   MessageBoxA,0,_msg,_cap,MB_ABORTRETRYIGNORE
    
    stdcall PatchCodeCave,esi,0x00603B0B,NewAIs,11 ;nomad setting
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_00603C4F,0x00603C4F,1
	and	edi,eax
    
	mov	eax,edi
	pop	edi esi
	ret
	
endp

NewAIs:
	push 2h
	mov dword[esp + 28h], 0h
	mov byte[esp + 1fh], 0h
	sub esp, 458h
	push 0h
	push 0h
	push 0h
	call HeapCreate
	mov ebp, eax
	push esp
	push 209h
	call GetCurrentDirectoryW
	push esp
	call lstrlenW
	mov word[esp + 2h * eax], 5ch ; hex value of '\'
	push 00be3a98h ; offset of unicode "AI3"
	lea eax, [esp + 2h * eax + 6h]
	push eax
	call lstrcpyW
	push esp
	call lstrlenW
	mov word[esp + 2h * eax], 2ah ; hex value of '*'
	push 00c0b39ch ; offset of unicode ".personality"
	lea eax, [esp + 2h * eax + 6h]
	push eax
	call lstrcpyW
	lea eax, [esp + 208h]
	push eax
	lea eax, [esp + 4h]
	push eax
	call FindFirstFileW
	mov dword[esp + 4ech], eax
	xor esi, esi
	push 4h
	push 0h
	push ebp
	call HeapAlloc
	jmp assign
	loop_main:
	lea edi, [esi + 3h * esi + 4h]
	push edi
	push ebx
	push 0
	push ebp
	call HeapReAlloc
	assign:
	mov ebx, eax
	xor edi, edi
	loop_string:
	cmp word[esp + 2 * edi + 234h], 2eh ; hex value of '.'
	je found
	inc edi
	jmp loop_string
	found:
	inc edi
	lea eax, [edi + edi]
	push eax
	push 0h
	push ebp
	call HeapAlloc
	mov dword[ebx + 4h * esi], eax
	push edi
	lea eax, [esp + 238h]
	push eax
	push dword[ebx + 4h * esi]
	call lstrcpynW
	inc esi
	lea eax, [esp + 208h]
	push eax
	push dword[esp + 4F0h]
	call FindNextFileW
	cmp eax, 0h
	jne loop_main
	push dword[esp + 4ech]
	call FindClose
	add esp, 45ch
	mov dword[esp + 40h], esi
	mov dword[esp + 50h], ebx
	jmp near $
	loc_00603C4F = $-4

;--------------------------------------------------

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
