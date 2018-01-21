.model flat, stdcall
option casemap :none

include UHC.inc

extern pUHCInfo:UHCInfoPtr
extern hProcess:DWORD

.code

patch_begin RegistryPath

code_cave_begin 0057CB54h
code_cave_end 006420A1h

patch_end RegistryPath

end