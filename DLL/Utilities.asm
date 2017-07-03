HeapAlloc proto stdcall :DWORD, :DWORD, :DWORD
UHCAnsiStrToWideStr proto stdcall hHeap:DWORD, lpStr:DWORD

checkID PROC stdcall dwType:DWORD, unitID:DWORD

    push edi
	push esi
	push ebx
    mov ebx, UHCRefTable
    mov eax, dwType
    imul ebx,eax
    mov eax,_UHCInfoPtr
	lea eax,[eax].UHCInfo.Tables
    lea eax,[eax+ebx]
    mov ebx,[eax].UHCRefTable.RefCount
    test ebx,ebx
    je checkid_end1
    
    mov esi,[eax].UHCRefTable.RefIDs
    mov edi,unitID
    dec ebx
    
    checkid_loop1:
    cmp edi,dword ptr ds:[esi+ebx*4]
    je checkid_valid_id
    dec ebx
    jns checkid_loop1
    jmp checkid_end1
    
    checkid_valid_id:
    mov eax,1
    pop ebx
	pop esi
	pop edi
    ret
    
    checkid_end1:
    xor eax,eax
    pop ebx
	pop esi
	pop edi
    ret

checkID ENDP

getIDs PROC stdcall dwType:DWORD

    push edi
	push esi
	push ebx
    mov ebx,UHCRefTable
    mov esi,ecx
    mov edi,dwType
    imul ebx,edi
    mov edi,_UHCInfoPtr
	lea edi,[edi].UHCInfo.Tables
    lea edi,[edi+ebx]
    mov ebx,[edi].UHCRefTable.RefCount
    test ebx,ebx
    je getids_end
    
    dec ebx
    
    getids_loop:
    mov eax,[edi].UHCRefTable.Refs
    mov eax,[eax+ebx*4]
    push eax
    mov ecx,esi
    mov eax, 005A2346h
	call eax
    mov ecx,[edi].UHCRefTable.RefIDs
    mov [ecx+ebx*4],eax
    dec ebx
    jns getids_loop
    
    getids_end:
    pop ebx
	pop esi
	pop edi
    ret

getIDs ENDP

marketCheck PROC stdcall
    push ebx
	push edi
    mov ebx, UHCRefTable
    imul ebx, MARKET
    mov edi,[_UHCInfoPtr]
	lea edi,[edi].UHCInfo.Tables
    lea edi,[edi+ebx]
    mov ebx,[edi].UHCRefTable.RefCount
    test ebx,ebx
    je marketcheck_invalid_id
    dec ebx
    mov edi,[edi].UHCRefTable.RefIDs
    
    marketcheck_loop:
    mov eax,[edi+ebx*4]
    mov edx,[esp+1Ch]
    mov ecx,[esi+80h]
    push 0
    push 2
    push eax
    push edx
    mov eax, 004C846Dh
	call eax
    test eax,eax
    jg marketcheck_valid_id
    dec ebx
    jns marketcheck_loop
    
    marketcheck_invalid_id:
    xor eax,eax
    pop edi
	pop ebx
    ret
    
    marketcheck_valid_id:
    mov eax,1
    pop edi
	pop ebx
    ret
marketCheck ENDP

getCivIDs PROC stdcall dwType:DWORD

    push edi
	push esi
	push ebx
    mov ebx, UHCRefTable
    mov esi,ecx
    mov edi, dwType
    imul ebx,edi
    mov edi,_UHCInfoPtr
	lea edi,[edi].UHCInfo.Tables
    lea edi,[edi+ebx]
    mov ebx,[edi].UHCRefTable.RefCount
    test ebx,ebx
    je getCivIDs_end
    dec ebx
    
    getCivIDs_loop:
    mov eax,[edi].UHCRefTable.Refs
    mov eax,[eax+ebx*4]
    push eax
    mov ecx,esi
    mov eax, 0058E71Fh
	call eax
    mov ecx,[edi].UHCRefTable.RefIDs
    mov [ecx+ebx*4],eax
    dec ebx
    jns getCivIDs_loop
    
    getCivIDs_end:
    pop ebx
	pop esi
	pop edi
    ret

getCivIDs ENDP

checkWonders PROC stdcall esiPtr:DWORD,ediPtr:DWORD

    push edi
	push esi
	push ebx
    mov ebx,UHCRefTable
    mov esi,ecx
    mov edi, ASIAN
    imul ebx,edi
    mov edi,_UHCInfoPtr
	lea edi,[edi].UHCInfo.Tables
    lea edi,[edi+ebx]
    mov ebx,[edi].UHCRefTable.RefCount
    test ebx,ebx
    je checkWonders_end
    dec ebx
    mov ecx,[edi].UHCRefTable.RefIDs
    cmp dword ptr ds:[esi+24h],0
    jg checkWonders_not_null
    or eax,-1
    jmp checkWonders_loop
    
    checkWonders_not_null:
    mov eax,[esi+20h]
    mov eax,[eax]
    
    checkWonders_loop:
    cmp eax,[ecx+ebx*4]
    je checkWonders_load_wonders
    dec ebx
    jns checkWonders_loop
    jmp checkWonders_end
    
    checkWonders_load_wonders:
    mov esi,esiPtr
    mov edi,ediPtr
    push -1
    push 0
	mov eax,_UHCInfoPtr
    mov eax,[eax].UHCInfo.AsianCivNames
    mov eax,[eax+ebx*4]
    push eax
    mov eax,[esi+18Ch]
    lea ecx,[eax+edi+8]
    mov eax, 00443C10h
	call eax
    test eax,eax
    jne checkWonders_end
    mov eax,1
    pop ebx
	pop esi
	pop edi
    ret
    
    checkWonders_end:
    xor eax,eax
    pop ebx
	pop esi
	pop edi
    ret

checkWonders ENDP

checkCouncil PROC stdcall civID:DWORD,esiPtr:DWORD,ediPtr:DWORD

    push edi
	push esi
	push ebx
    mov ebx, UHCRefTable
    mov edi, NATIVE
    imul ebx,edi
    mov edi,_UHCInfoPtr
	lea edi,[edi].UHCInfo.Tables
	mov esi,[edi].UHCInfo.NativeCivNames
    lea edi,[edi+ebx]
    mov ebx,[edi].UHCRefTable.RefCount
    test ebx,ebx
    je checkcouncil_end
    mov edi,[edi].UHCRefTable.RefIDs
    dec ebx
    
    checkcouncil_loop:
    mov eax,civID
    mov ecx,[edi+ebx*4]
    cmp eax,ecx
    je checkcouncil_check
    dec ebx
    cmp ebx,0
    jge checkcouncil_loop
    jmp checkcouncil_end
    
    checkcouncil_check:
    mov eax,esiPtr
    mov eax,[eax+18Ch]
    mov ecx,ediPtr
    lea ecx,[eax+ecx+8]
    push -1
    push 0
    mov eax,[esi+ebx*4]
    push eax
    mov eax, 00443C10h
	call eax
    test eax,eax
    jne checkcouncil_end
    mov eax,1
    pop ebx
	pop esi
	pop edi
    ret
    
    checkcouncil_end:
    xor eax,eax
    pop ebx
	pop esi
	pop edi
    ret
    
checkCouncil ENDP

NatCivCheck1 PROC STDCALL ebxVal:DWORD

    push edi
	push esi
	push ebx
    mov ebx, UHCRefTable
    mov esi,ecx
    mov edi, NATIVE
    imul ebx,edi
    mov edi,_UHCInfoPtr
	lea edi,[edi].UHCInfo.Tables
    lea edi,[edi+ebx]
    mov ebx,[edi].UHCRefTable.RefCount
    test ebx,ebx
    je natcivcheck1_end
    dec ebx
    
    natcivcheck1_loop:
    mov eax,[edi].UHCRefTable.Refs
    mov eax,[eax+ebx*4]
    push eax
    mov ecx,esi
    mov eax, 0052D6FFh
	call eax
    xor ecx,ecx
    cmp eax,ecx
    je natcivcheck1_next
    mov ecx,ebxVal
    mov [eax+10h],ecx

    natcivcheck1_next:
    dec ebx
    cmp ebx,0
    jge natcivcheck1_loop
    
    natcivcheck1_end:
    pop ebx
	pop esi
	pop edi
    ret
    
NatCivCheck1 ENDP