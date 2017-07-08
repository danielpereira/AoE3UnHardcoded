.model flat, stdcall
option casemap :none

include UHC.inc

extern pUHCInfo:UHCInfoPtr
extern hProcess:DWORD

.code

RegisterSyscallGroup proto stdcall groupName:DWORD, :DWORD

GroupAI = 0h
GroupHC = 01h
GroupKB = 02h
GroupRM = 03h
GroupTR = 04h
GroupUI = 05h
GroupUI2 = 06h
GroupXS = 07h

; AI
code_cave_begin 07294F4h
	invoke RegisterSyscallGroup, GroupAI, esi
code_cave_end 07294F4h

; HC
code_cave_begin 05B5E08h
	invoke RegisterSyscallGroup, GroupHC, esi
code_cave_end 05B5E08h

; KB
code_cave_begin 0885D14h
	invoke RegisterSyscallGroup, GroupKB, esi
code_cave_end 0885D14h

; RM
code_cave_begin 060B8BFh
	invoke RegisterSyscallGroup, GroupRM, esi
code_cave_end 060B8BFh

; TR
code_cave_begin 0988E03h
	invoke RegisterSyscallGroup, GroupTR, esi
code_cave_end 0988E03h

; UI
code_cave_begin 0539542h
	invoke RegisterSyscallGroup, GroupUI, esi
code_cave_end 0539542h

; UI2
code_cave_begin 053575Eh
	invoke RegisterSyscallGroup, GroupUI2, esi
code_cave_end 053575Eh

; XS
code_cave_begin 06257D9h
	invoke RegisterSyscallGroup, GroupXS, esi
code_cave_end 06257D9h

public stdcall PatchSyscall
PatchSyscall proc
	patch_code_cave 07294F4h, 07294F4h ; AI
	patch_code_cave 05B5E08h, 05B5E08h ; HC
	patch_code_cave 0885D14h, 0885D14h ; KB
	patch_code_cave 060B8BFh, 060B8BFh ; RM
	patch_code_cave 0988E03h, 0988E03h ; TR
	patch_code_cave 0539542h, 0539542h ; UI
	patch_code_cave 053575Eh, 053575Eh ; UI2
	patch_code_cave 06257D9h, 06257D9h ; XS
	ret
PatchSyscall endp

end