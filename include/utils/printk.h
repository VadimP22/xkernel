#pragma once
#include "types.h"

enum PrintkArgumentType {
    BYTE,
    SPACE,
    STRING,
    NEWLINE
};


struct PrintkArgumentsList {
    PrintkArgumentType argument_types[16];
    u32 argument_count;
};


/**
 * @brief Parses format string, returns KprintArguments.
 * @param fmt Format string.
*/
PrintkArgumentsList parse_printk_format_string(const char* fmt);


/**
 * @brief Prints what do you want to vga text buffer/framebuffer/serial port/file (depends on configuration).
 * First, calls parse_printk_format_string(), then uses this info to print args.
 * This function is abstraction over vga text mode/framebuffer/serial. So I decided to
 * make dedicated color enum for this.
 * 
 * @bug On first call prints string with some spaces. On second call prints on the same string.
 * 
 * @param fmt Formating expression. s - string, b - byte, ' ' - space, n - newline
 * @example kprintf("%-s, %-s", "Hello", "world!")
 * 
 * */ 
void printk(const char* fmt, ...);