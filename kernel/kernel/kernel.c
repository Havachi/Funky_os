#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#if defined(__linux__)
#error "You are not using a cross-compiler"
#endif

#if !defined(__i386__)
#error "Not using i386 compiler" 
#endif
#include <kernel/tty.h>
#include <kernel/gdt.h>
#include "../arch/i386/vga.h"
size_t strlen(const char* str)

{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

void kernel_main(void) {
	terminal_initialize();

	terminal_setcolor(vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK));
	terminal_writestring("Hello, kernel world!\n");
	terminal_setcolor(vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK));
	terminal_writestring("Hello, kernel world!\n");
	terminal_setcolor(vga_entry_color(VGA_COLOR_BLUE, VGA_COLOR_BLACK));
	terminal_writestring("Hello, kernel world!\n");
	terminal_setcolor(vga_entry_color(VGA_COLOR_CYAN, VGA_COLOR_BLACK));
	terminal_writestring("Hello, kernel world!\n");
	terminal_setcolor(vga_entry_color(VGA_COLOR_LIGHT_BROWN, VGA_COLOR_BLACK));
	terminal_writestring("Hello, kernel world!\n");
	terminal_setcolor(vga_entry_color(VGA_COLOR_MAGENTA, VGA_COLOR_BLACK));
	terminal_writestring("Hello, kernel world!\n");

}
