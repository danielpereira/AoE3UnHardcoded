#include "patcher.h"

int main() {
    FILE *executable;
    PatchInfo *patches;
    int i;
    char file_flags[MAX_FILES], *filename, patch_applied = 0, opt;
    wchar_t proto[11], randomapstr[21], randomnames[17], strtable[17], techtree[14], unithelp[20], AI[5], RM[5], trigger[9], Data[7];
    
    filename = (*char) calloc(257, sizeof(char));
    
    patches = (*PatchInfo) calloc(MAX_OPTIONS, sizeof(PatchInfo));
    InitializeStructs(patches);
    
    memset(option_flags, 0, MAX_OPTIONS)
    memset(file_flags, 0, MAX_FILES)
    
    
    do {
        printf("AoE3 UnHardcode Patcher\n");
        printf("Version 1.00\n\n");
        //printf("Insert a text to tell the user to select an option\n");
        printf("\t0 - Apply\n");
        printf("\t1 - Set Options\n");
        printf("\t2 - Set Custom File names\n");
        printf("\t3 - Exit\n");
        scanf("%c", &opt);
        scanf("");
        
        switch (opt) {
            case '0':
                fgets(filename, 256, stdin);
                executable = fopen(filename)
                if (executable != NULL) {
                    for (i = 0; i < MAX_OPTIONS; i++) {
                        if (patches[i].enabled)
                            PatchData(executable, &patches[i]);
                    }
                }
                patch_applied = 1;
                fclose(executable)
                break;
            case '3':
                patch_applied = 1;
        }
                   
    } while (!patch_applied);
    
    return 0;
}