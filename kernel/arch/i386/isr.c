#include <common.h>
#include <arch/i386/isr.h>
#include <stdio.h>

void isr_handler(registers_t regs)
{
	printf("[INT] received interrupt: %s\n", regs.int_no);
}
