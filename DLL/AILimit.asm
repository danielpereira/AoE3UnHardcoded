LoadPersonalities proto stdcall info:UHCInfoPtr

code_cave_begin 00603B0Bh
	invoke LoadPersonalities, _UHCInfoPtr
	mov edi, _UHCInfoPtr
	mov esi, [edi].UHCInfo.PersonalityCount
	mov dword ptr ss:[esp + 040h], esi
	mov esi, [edi].UHCInfo.Personalities
	mov dword ptr ss:[esp + 050h], esi
code_cave_end 00603C4Fh

public stdcall PatchAILimit
PatchAILimit proc
	patch_code_cave 00603B0Bh, 00603C4Fh
	ret
PatchAILimit endp