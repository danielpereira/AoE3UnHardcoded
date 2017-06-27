.model flat, stdcall

include UHCAsm.inc

.data

_UHCInfoPtr UHCInfoPtr ?
_hProcess dd ?

_AsianWndrNamesPtr dd ?
_NativeCouncilNamesPtr dd ?
_HeapHandle dd ?

;_this dd ?

.code

include Utilities.asm
include FarmAnim.asm
include Syscall.asm
;include DumpSyscall.asm
include Cheat.asm
include TeamLimit.asm
include AILimit.asm
include RevBanner.asm
include RegistryPath.asm
include DeckLimit.asm
include PopLimit.asm
include MarketUnits.asm
include UnitChecking.asm
include CivChecking.asm
include Asians.asm
include Natives.asm
include BigButton.asm

public stdcall UHCAsmInit
UHCAsmInit proc info:UHCInfoPtr, hProcess:DWORD
	mov eax, hProcess
	mov _hProcess, eax
	mov eax, info
	mov _UHCInfoPtr, eax
	ret
UHCAsmInit endp


END