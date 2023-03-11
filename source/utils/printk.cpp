#include "utils/printk.h"
#include "utils/string.h"
#include "stdarg.h"
#include "utils/vga_writer.h"


PrintkArgumentsList parse_printk_format_string(const char* fmt) {
    PrintkArgumentsList argument_list;
    argument_list.argument_count = 0;

    auto len = string_len(fmt);

    for (auto i = 0; i < len; i++) {
        switch (fmt[i])
        {
            case 's':
                argument_list.argument_types[argument_list.argument_count] = PrintkArgumentType::STRING;
                argument_list.argument_count += 1;
                break;
            case ' ':
                argument_list.argument_types[argument_list.argument_count] = PrintkArgumentType::SPACE;
                argument_list.argument_count += 1;
                break;
            case 'b':
                argument_list.argument_types[argument_list.argument_count] = PrintkArgumentType::BYTE;
                argument_list.argument_count += 1;
                break;
            case 'n':
                argument_list.argument_types[argument_list.argument_count] = PrintkArgumentType::NEWLINE;
                argument_list.argument_count += 1;
                break;
            
            default:
                break;
        }
    }

    return argument_list;
}


void printk(const char* fmt, ...) {
    auto parsed_arguments = parse_printk_format_string(fmt);
    auto function_arguments= va_list();

    va_start(function_arguments, fmt);

    for (u32 i = 0; i < parsed_arguments.argument_count; i++) {
        switch (parsed_arguments.argument_types[i])
        {
            case PrintkArgumentType::STRING:
                VGA_WRITER.get()->write_string(va_arg(function_arguments, char*), VgaColor::LIGHT_GREEN, VgaColor::BLACK);
                break;
            case PrintkArgumentType::NEWLINE:
                VGA_WRITER.get()->wriete_byte('\n', VgaColor::BLACK, VgaColor::BLACK);
            default:
                break;
        }
    }
}