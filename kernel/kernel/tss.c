#include <kernel/tss.h>

void write_tss(struct gdt_entry_bits *g)
{
	uint32_t base = (uint32_t) &tss_entry
	uint32_t limit = sizeof tss_entry;

	g->limit_low = limit;
	g->base_low = base;
	g->accessed = 1;
	g->read_write = 0;
	g->comforming = 0;
	g->code = 1;
	g->code_data_segment = 0;
	g->DPL = 0;
	g->present = 1;
	g->limit_high = (limit & (0xf << 16)) >> 16;
	g->available = 0;
	g->long_mode = 0;
	g->big = 0;
	g->gran = 0;
	g->base_high = (base & (0xff << 24)) >> 24;
	memset(&tss_entry, 0, sizeof tss_entry);
	tss_entry.ss0 = REPLACE_KERNEL_DATA_SEGMENT
	tss_entry.esp0 = REPLACE_KERNEL_STACK_ADDRESS;
}

void set_kernel_stack(uint32_t stack)
{
	tss_entry.esp0 = stack;
}

void test_user_function(void)
{
	__asm__("cli");
}
