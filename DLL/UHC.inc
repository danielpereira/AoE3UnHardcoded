PatchData proto stdcall hProcess:DWORD, dwAddress:DWORD, lpBuffer:DWORD, dwSize:DWORD
PatchCodeCave proto stdcall hProcess:DWORD, dwAddress:DWORD, dwAddressEnd:DWORD, dwCCAddress:DWORD, dwCCAddressEnd:DWORD
PatchAddress proto stdcall hProcess:DWORD, lpBaseAddress:DWORD, lpDestAddress:DWORD, bRelAddr:DWORD
PatchFakeInstructions proto stdcall hProcess:DWORD, lpAddress:DWORD, lpAddressEnd:DWORD

FARM = 0
RECTFARM = 1
MARKET = 2
ASIAN = 3
NATIVE = 4
TACTIC_SWITCHING = 5
BIGBUTTON_CIVS = 6
NO_BIGBUTTON_BLDS = 7
ATTACK_TYPE_ICONS = 8
TWO_SCOUT_CIVS = 9
EXPLORER_UNITS = 10

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

UHCTypeIcons struct
	IconPath dd ?
	StringID dd ?
	IconData dd ?
UHCTypeIcons ends

UHCExplorer struct
	ExplorerType dd ?
	DeathStringID dd ?
UHCExplorer ends

UHCFarmRadiusPtr typedef ptr UHCFarmRadius
UHCTypeIconsPtr typedef ptr UHCTypeIcons
UHCExplorerPtr typedef ptr UHCExplorer

TABLE_COUNT = 11
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
	UplFilepathCount dd ?
	UplFilepaths dd ?
	PersonalityCount dd ?
	Personalities dd ?
	AsianCivCount dd ?
	AsianCivNames dd ?
	NativeCivCount dd ?
	NativeCivNames dd ?
	FarmRadiusInfoCount dd ?
	FarmRadiusInfo UHCFarmRadiusPtr ?
	TypeIconInfoCount dd ?
	TypeIconInfo UHCTypeIconsPtr ?
	ExplorerInfoCount dd ?
	ExplorerInfo UHCExplorerPtr ?
	HCXpIconData dd ?
	HCFameIconData dd ?
	Decoder dd ?
UHCInfo ends

UHCInfoPtr typedef ptr UHCInfo

extern pUHCInfo:UHCInfoPtr
extern hProcess:DWORD

; fake instruction, requires to be updated by PatchFakeInstructions() defined in Utitiles.cpp
fak macro opcode, address
	db 0F1h
	db opcode
	dd address
endm

call_rel32 macro address
	fak 0, address
endm

jmp_rel32 macro address
	fak 1, address
endm

je_rel32 macro address
	fak 2, address
endm

jne_rel32 macro address
	fak 3, address
endm

; patch jump table offset, usually used by switch statement
case macro address
	fak 4, address
endm

; code cave macros
code_cave_begin macro address
	fak 5, address
	@CatStr(<loc_>, <address>, <_begin:>)
endm

code_cave_end macro address
	@CatStr(<loc_>, <address>, <_end:>)
	db 0E9h, 0FBh, 0FFh, 0FFh, 0FFh
	fak 6, address
endm

patch_code_cave macro address, address_end
	push @CatStr(<loc_>, <address_end>, <_end>)
	push @CatStr(<loc_>, <address>, <_begin>)
	push address_end
	push address
	push hProcess
	call PatchCodeCave
endm

; patch macros, any 'fake' instructions or code caves enclosed by patch_begin and patch_end will be patched automatically by the procedure 'PatchXXX'
patch_begin macro name
	@CatStr(<patch_>, <name>, <_begin:>)
endm

patch_end macro name
	@CatStr(<patch_>, <name>, <_end:>)
	public stdcall @CatStr(<Patch>, <name>)
	@CatStr(<Patch>, <name>) proc
		invoke PatchFakeInstructions, hProcess, @CatStr(<patch_>, <name>, <_begin>), @CatStr(<patch_>, <name>, <_end>)
		ret
	@CatStr(<Patch>, <name>) endp
endm