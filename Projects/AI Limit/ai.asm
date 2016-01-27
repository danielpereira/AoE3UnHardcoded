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
    
    stdcall PatchCodeCave,esi,0x00603BA7,NewAIs,11 ;nomad setting
	and	edi,eax
    
    stdcall PatchAddress,esi,loc_00603C4F,0x00603C4F,1
	and	edi,eax
    
	mov	eax,edi
	pop	edi esi
	ret
	
endp

NewAIs:
    
    lea edx,[aipointers]
    mov dword[edx],00BACC4Ch ;brit
    mov dword[edx+4],00BACC38h ;german
    mov dword[edx+8],00BACC2Ch ;port
    mov dword[edx+0Ch],00BACC18h ;spanish
    mov dword[edx+10h],00BACC98h ;russian
    mov dword[edx+14h],00BACC84h ;french
    mov dword[edx+18h],00BACC70h ;ottoman
    mov dword[edx+1Ch],00BACC60h ;dutch
    mov dword[edx+20h],00BACC04h ;iroquois
    mov dword[edx+24h],00BACBECh ;sioux
    mov dword[edx+28h],00BACBD4h ;aztecs
    mov dword[edx+2Ch],00BACCB4h ;japanese
    mov dword[edx+30h],00BACCA4h ;chinese
    mov dword[edx+34h],00BACCC8h ;indian
    mov dword[edx+38h],ai_15 ;new
    mov dword[edx+3Ch],ai_16 ;new
    mov dword[edx+40h],ai_17 ;new
    mov dword[edx+44h],ai_18 ;new
    sub esp,4
    add esp,8
    lea eax,[aipointers]
    mov dword[esp+40h],18
    mov [esp+50h],eax
    
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
section '.data' data readable writeable
;==================================================

_cap db 'It loads!',0
_msg db 'Game loads ai.dll through a codecave',0

ai_15 db 's',0,'a',0,'o',0,'p',0,'a',0,'u',0,'l',0,'o',0,0,0
ai_16 db 'c',0,'z',0,'e',0,'c',0,'h',0,0,0
ai_17 db 'w',0,'p',0,'r',0,'c',0,0,0
ai_18 db 's',0,'a',0,'v',0,'o',0,'y',0,0,0

aipointers db 72 dup 0x00

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
