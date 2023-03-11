#include "kmain.h"
#include "utils/vga_writer.h"
#include "utils/string.h"
#include "utils/printk.h"


extern "C" u32 kmain() {
    
    VgaWriter vga_writer = VgaWriter();
    VGA_WRITER.initialize(&vga_writer);

    printk("n");
    printk("ssns", "Hello, ", "My name is:", "Vadim");


    return 0;
}