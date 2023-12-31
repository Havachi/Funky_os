#ifndef _ISR_H
#define _ISR_H

#include "common.h"

typedef struct registers
{
	uint32_t ds;
	uint32_t edi, esi, ebp, esp, ebx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
} registers_t;

#endif
