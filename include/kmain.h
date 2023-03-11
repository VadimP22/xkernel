#pragma once


#include "types.h"

/**
 * @brief Kernel entry. Called by multiboot.S (in project root)
*/
extern "C" u32 kmain();