DumpSyscallRegister proto stdcall :DWORD, :DWORD, :DWORD
DumpSyscallParam proto stdcall :DWORD, :DWORD
DumpSyscallEnd proto stdcall
DumpSyscallComment proto stdcall :DWORD

; syscall_register dump
code_cave_begin 0624F52h
	mov _this, ecx
	push dword ptr ds:[esp + 0Ch]
	push dword ptr ds:[esp + 0Ch]
	push dword ptr ds:[esp + 0Ch]
	call DumpSyscallRegister
	mov ecx, _this
code_cave_end 0624F52h

code_cave_begin 0624DC9h
	mov _this, ecx
	push dword ptr ds:[esp + 08h]
	push dword ptr ss:[esp + 08h]
	call DumpSyscallParam
	mov ecx, _this
code_cave_end 0624DC9h

; end
code_cave_begin 062513Ah
	mov _this, ecx
	call DumpSyscallEnd
	mov ecx, _this
code_cave_end 062513Ah

; comment
code_cave_begin 0624E7Ch
	mov _this, ecx
	push [esp + 04h]
	call DumpSyscallComment
	mov ecx, _this
code_cave_end 0624E7Ch

PatchDumpSyscall proc 
	patch_code_cave 0624F52h, 0624F52h

	patch_code_cave 0624DC9h, 0624DC9h

	patch_code_cave 062513Ah, 062513Ah

	patch_code_cave 0624E7Ch, 0624E7Ch
	ret
PatchDumpSyscall endp