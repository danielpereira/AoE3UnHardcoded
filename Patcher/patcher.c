#include "patcher.h"

/* char PatchData(FILE *exe, const DWORD offset, const char *patchData, const patchSize, const NopSize) {
    if (!fseek(exe, offset, SEEK_SET)) {
        if(fwrite(data, patchSize, sizeof(char), exe) == 1) {
            if (NopSize) {
                char *nop_array = calloc(NopSize, sizeof(char));
                memset(nop_array, NOP, NopSize);
                
                if (!fwrite(nop_array, NopSize, sizeof(char),exe) == 1)
                    return 0;
                    
                free(nop_array);
            }
            
            return 1;
        }
    }
    
    return 0;
} */

char PatchData(FILE *exe, patchInfo *patch) {
    if (!fseek(exe, patch->patchAddress, SEEK_SET)) {
        if(fwrite(patch->patchData, patch->patchSize, sizeof(char), exe) == 1) {
            if (NopSize) {
                char *nop_array = calloc(patch->NopSize, sizeof(char));
                memset(nop_array, NOP, patch->NopSize);
                
                if (!fwrite(nop_array, patch->NopSize, sizeof(char),exe) == 1)
                    return 0;
                    
                free(nop_array);
            }
            
            return 1;
        }
    }
    
    return 0;
}

char PatchFileName(FILE *exe, const DWORD offset, const wchar_t *filename) {
    lenght = wcslen(filename) + 1
    if (!fseek(exe, offset, SEEK_SET))
        if(fwrite(filename, sizeof(wchar_t), lenght, exe) == lenght)
            return 1;
    
    return 0;
}

void InitializeStructs(patchData *patches) {
    patchOption i;
    
    for (i = 0; i < MAX_OPTIONS; i++) {
        switch (i) {
            case PATCH_AI_LIMIT:
                patches[i] = { 0, patchAILimitAddress, patchAILimit, patchAILimitSize, patchAILimitNopSize }
                break;
            case PATCH_REV_BANNERS:
                patches[i] = { 0, patchRevBannerAddress, patchRevBanner, patchRevBannerSize, patchRevBannerNopSize }
        }
    }
}