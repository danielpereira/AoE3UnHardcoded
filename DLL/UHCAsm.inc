PatchData proto stdcall hProcess:DWORD, dwAddress:DWORD, lpBuffer:DWORD, dwSize:DWORD
PatchCodeCave proto stdcall hProcess:DWORD, dwAddress:DWORD, dwAddressEnd:DWORD, dwCCAddress:DWORD, dwCCAddressEnd:DWORD
PatchAddress proto stdcall hProcess:DWORD, lpBaseAddress:DWORD, lpDestAddress:DWORD, bRelAddr:DWORD

UHCRefTable struct
	RefCount dd ?
	Refs dd ?
	RefIDs dd ?
UHCRefTable ends

UHCSyscallGroup struct
	SyscallCount dd ?
	Syscalls dd ?
UHCSyscallGroup ends

UHCCheat struct
	String dd ?
	Enable dd ?
	FunctionPtr dd ?
UHCCheat ends

UHCCheatPtr typedef ptr UHCCheat

TABLE_COUNT = 7
GROUP_COUNT = 8

UHCInfo struct
	hHeap dd ?
	Enable dd ?
	Tables UHCRefTable TABLE_COUNT dup (<>)
	BasePop dd ?
	ExtraPop dd ?
	DeckCardCount dd ?
	SyscallGroups UHCSyscallGroup GROUP_COUNT dup (<>)
	CheatCount dd ?
	Cheats UHCCheatPtr ?	
	PersonalityCount dd ?
	Personalities dd ?
	AsianCivCount dd ?
	AsianCivNames dd ?
	NativeCivCount dd ?
	NativeCivNames dd ?
UHCInfo ends

UHCInfoPtr typedef ptr UHCInfo

; instruction macros, used for patching executable memory
jmp_rel32 macro address
	db 0E9h
	@catstr(<loc_>, <address>, < : >)
    dd 0FFFFFFFAh
endm

call_rel32 macro address
	db 0E8h
	@catstr(<sub_>, <address>, < : >)
    dd 0FFFFFFFAh
endm

je_rel32 macro address
	db 0Fh, 84h
	@catstr(<loc_>, <address>, < : >)
    dd 0FFFFFFFAh
endm

jne_rel32 macro address
	db 0Fh, 85h
	@catstr(<loc_>, <address>, < : >)
    dd 0FFFFFFFAh
endm

; code cave macros
code_cave_begin macro address
	@catstr(<loc_>, <address>, <_begin:>)
endm

code_cave_end macro address
	@catstr(<loc_>, <address>, <_end:>)
	db 0E9h, 0FBh, 0FFh, 0FFh, 0FFh
endm

patch_code_cave macro address, address_end
	push @catstr(<loc_>, <address_end>, <_end>)
	push @catstr(<loc_>, <address>, <_begin>)
	push address_end
	push address
	push _hProcess
	call PatchCodeCave
endm