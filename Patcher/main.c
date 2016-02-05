#include "patcher.h"

int main() {
    FILE *executable;
    char option_flags[MAX_OPTIONS], file_flags[MAX_FILES], *filename, patch_applied = 0, opt;
    wchar_t proto[11], randomapstr[21], randomnames[17], strtable[17], techtree[14], unithelp[20], AI[5], RM[5], trigger[9], Data[7];
    
    *filename = (*char) calloc(257, sizeof(char));
    
    memset(option_flags, 0, MAX_OPTIONS)
    memset(file_flags, 0, MAX_OPTIONS)
    
    do {
        printf("AoE3 UnHardcode Patcher\n");
        printf("Version 1.00\n\n");
        //printf("Insert a text to tell the user to select an option\n");
        printf("\t0 - Apply\n");
        printf("\t1 - Set Options\n");
        printf("\t2 - Set Custom File names\n");
        printf("\t3 - Exit\n");
        scanf("%c ", &opt);
        
        switch (opt) {
            case '0':
                fgets(filename, 256, stdin);
                executable = fopen(filename)
                if (executable != NULL) {
                    
    } while (!patch_applied);
    
    return 0;
}