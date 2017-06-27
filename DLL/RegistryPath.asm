PatchData proto stdcall hProcess:DWORD, dwAddress:DWORD, lpBuffer:DWORD, dwSize:DWORD

RegistryPathPatch db 0EBh, 7Ch, 90h, 90h, 90h, 90h

public stdcall PatchRegistryPath
PatchRegistryPath proc
	invoke PatchData,_hProcess,0057CB54h,RegistryPathPatch,6
	ret
PatchRegistryPath endp