#include "patcher.h"

char PatchData(FILE *exe, const DWORD offset, const char *data) {
    if (!fseek(exe, offset, SEEK_SET);)
        if(fwrite(data, sizeof(data), 1, exe) == 1)
            return 1;
    
    return 0;
}

char PatchFileName(FILE *exe, const DWORD offset, const wchar_t *filename) {
    if (!fseek(exe, offset, SEEK_SET);)
        if(fwrite(filename, sizeof(wchar_t), wcslen(filename) + 1, exe) == wcslen(filename) + 1)
            return 1;
    
    return 0;
}

char NopOMatic(FILE *exe, const DWORD offset, const unsigned int size) {
    if (!fseek(exe, offset, SEEK_SET);)
        //TODO
    
    return 0;
}