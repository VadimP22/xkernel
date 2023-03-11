#include "utils/string.h"
#include "stdarg.h"


u32 string_len(const char * str) {
    u32 len = 0;

    while(str[len] != 0) {
        len += 1;
    }

    return len;
}