#pragma once


#include "types.h"
#include "initializable.h"


#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define VGA_TEXT_BUFFER_ADDRESS 0xB8000


enum VgaColor {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15,
};


class VgaWriter {
    public:
        VgaWriter();
        void write_string(const char * str, VgaColor fg, VgaColor bg);
		void wriete_byte(u8 byte, VgaColor fg, VgaColor bg);

    private:
        u8 current_offset = 0;

        void new_line();
        u8 make_color(VgaColor fg, VgaColor bg);
};


static Initializable<VgaWriter*> VGA_WRITER = Initializable<VgaWriter*>();