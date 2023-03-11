#include <stdbool.h>
#include <stddef.h>
#include "types.h"
#include "utils/vga_writer.h"
#include "utils/string.h"


VgaWriter::VgaWriter() {
	
}


u8 VgaWriter::make_color(VgaColor fg, VgaColor bg) {
	return fg | bg << 4;
}


void VgaWriter::write_string(const char * str, VgaColor fg, VgaColor bg) {
	auto len = string_len(str);
	for(auto i = 0; i < len; i++) {
		this->wriete_byte(str[i], fg, bg);
	}
}


void VgaWriter::new_line() {
	this->current_offset = 0;

	for (u16 i = 1; i <= VGA_HEIGHT; i++) {
		auto previos_row_address = (u16*) VGA_TEXT_BUFFER_ADDRESS + (i - 1)*VGA_WIDTH;
		auto current_row_address = (u16*) VGA_TEXT_BUFFER_ADDRESS + i*VGA_WIDTH;

		for (u16 j = 0; j < VGA_WIDTH; j++) {
			auto symbol = *(current_row_address + j);
			*(previos_row_address + j) = symbol;
		}
	}
}


void VgaWriter::wriete_byte(u8 byte, VgaColor fg, VgaColor bg) {
	u8* symbol_address = ((u8*) VGA_TEXT_BUFFER_ADDRESS) + (VGA_WIDTH * (VGA_HEIGHT - 1)) + 2*this->current_offset;

	if (this->current_offset == (VGA_WIDTH - 1)) {
		this->new_line();
	}

	if (byte == '\n') {
		this->new_line();
	}
	else {
		*(symbol_address) = byte;
		*(symbol_address + 1) = make_color(fg, bg);
		this->current_offset += 1;
	}
}