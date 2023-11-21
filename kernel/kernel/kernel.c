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
#include <kernel/descriptor_tables.h>
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
	asm volatile ("int $0x3");
	asm volatile ("int $0x4");
}
