.model flat, stdcall
option casemap :none

include UHC.inc

extern pUHCInfo:UHCInfoPtr
extern hProcess:DWORD

.code

code_cave_begin 0057CB54h
code_cave_end 006420A1h

public stdcall PatchRegistryPath
PatchRegistryPath proc
	patch_code_cave 0057CB54h, 006420A1h
	ret
PatchRegistryPath endp

end