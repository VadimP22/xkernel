#pragma once


#include "types.h"


/**
 * @brief Get lenght of C (null-terminatid) string.
 * @return String length
 * @bug Causes undefined behavior if string isn't null-terminated
*/
u32 string_len(const char * str);