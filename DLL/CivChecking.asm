code_cave_begin 008D0318h
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx,[ecx+140h]
    invoke getCivIDs,3
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx,[ecx+140h]
    invoke getCivIDs,4
    mov eax, dword ptr ds:[00C66234h]
    jmp_rel32 008D031D
code_cave_end 008D031Ch

code_cave_begin 008DABA3h
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx,[ecx+140h]
    invoke getCivIDs,3
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx,[ecx+140h]
    invoke getCivIDs,4
    mov ecx, dword ptr ds:[00C66234h]
    mov ecx,[ecx+140h]
    invoke getCivIDs,5
    mov edx, dword ptr ds:[00C66234h]
    jmp_rel32 008DABA9
code_cave_end 008DABA8h

public stdcall PatchCivChecking
PatchCivChecking proc

	patch_code_cave 008D0318h, 008DABA8h
	invoke PatchAddress, _hProcess, loc_008D031D, 008D031Dh, 1
	
	patch_code_cave 008DABA3h, 008DABA8h
	invoke PatchAddress, _hProcess, loc_008DABA9, 008DABA9h, 1
	ret
PatchCivChecking endp

