PatchData proto stdcall hProcess:DWORD, dwAddress:DWORD, lpBuffer:DWORD, dwSize:DWORD
PatchCodeCave proto stdcall hProcess:DWORD, dwAddress:DWORD, dwAddressEnd:DWORD, dwCCAddress:DWORD, dwCCAddressEnd:DWORD
PatchAddress proto stdcall hProcess:DWORD, lpBaseAddress:DWORD, lpDestAddress:DWORD, bRelAddr:DWORD

FARM = 0
RECTFARM = 1
MARKET = 2
ASIAN = 3
NATIVE = 4
TACTIC_SWITCHING = 5
BIGBUTTON_CIVS = 6
NO_BIGBUTTON_BLDS = 7

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

UHCFarmRadius struct
	RefIndex dd ?
	X dd ?
	Z dd ?
UHCFarmRadius ends

UHCFarmRadiusPtr typedef ptr UHCFarmRadius

TABLE_COUNT = 8
GROUP_COUNT = 8

UHCInfo struct
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
	FarmRadiusInfoCount dd ?
	FarmRadiusInfo UHCFarmRadiusPtr ?
UHCInfo ends

UHCInfoPtr typedef ptr UHCInfo

; instruction macros, used for patching executable memory
jmp_rel32 macro address
	db 0E9h
	@CatStr(<loc_>, <address>, < : >)
    dd 0FFFFFFFAh
endm

call_rel32 macro address
	db 0E8h
	@CatStr(<sub_>, <address>, < : >)
    dd 0FFFFFFFAh
endm

je_rel32 macro address
	db 0Fh, 84h
	@CatStr(<loc_>, <address>, < : >)
    dd 0FFFFFFFAh
endm

jne_rel32 macro address
	db 0Fh, 85h
	@CatStr(<loc_>, <address>, < : >)
    dd 0FFFFFFFAh
endm

; code cave macros
code_cave_begin macro address
	@CatStr(<loc_>, <address>, <_begin:>)
endm

code_cave_end macro address
	@CatStr(<loc_>, <address>, <_end:>)
	db 0E9h, 0FBh, 0FFh, 0FFh, 0FFh
endm

patch_code_cave macro address, address_end
	push @CatStr(<loc_>, <address_end>, <_end>)
	push @CatStr(<loc_>, <address>, <_begin>)
	push address_end
	push address
	push hProcess
	call PatchCodeCave
endm