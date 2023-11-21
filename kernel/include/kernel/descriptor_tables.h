#ifndef _DESCRIPTOR_TABLES_H
#define _DESCRIPTOR_TABLES_H
#include <stdint.h>
#include <string.h>

struct gdt_ptr_struct
{
	uint16_t	limit;
	uint32_t	base;
}__attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

struct gdt_entry_bits 
{
	uint16_t	limit_low;
	uint16_t	base_low;
	uint8_t		base_middle;
	uint8_t		accessed;
	uint8_t		read_write;
	uint8_t		conforming;
	uint8_t		code;
	uint8_t		code_data_segment;
	uint8_t		DPL;
	uint8_t		present;
	uint8_t		limit_high;
	uint8_t		available;
	uint8_t		long_mode;
	uint8_t		big;
	uint8_t		gran;
	uint8_t		base_high;
} __attribute__((packed));
typedef struct gdt_entry_bits gdt_entry_t;

struct idt_entry_struct
{
   uint16_t	base_lo;
   uint16_t	sel;   
   uint8_t	always0;
   uint8_t	flags; 
   uint16_t	base_hi;
} __attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;

struct idt_ptr_struct
{
   uint16_t limit;
   uint32_t	base;
} __attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

extern void isr0 ();
extern void isr1 ();
extern void isr2 ();
extern void isr3 ();
extern void isr4 ();
extern void isr5 ();
extern void isr6 ();
extern void isr7 ();
extern void isr8 ();
extern void isr9 ();
extern void isr10 ();
extern void isr11 ();
extern void isr12 ();
extern void isr13 ();
extern void isr14 ();
extern void isr15 ();
extern void isr16 ();
extern void isr17 ();
extern void isr18 ();
extern void isr19 ();
extern void isr20 ();
extern void isr21 ();
extern void isr22 ();
extern void isr23 ();
extern void isr24 ();
extern void isr25 ();
extern void isr26 ();
extern void isr27 ();
extern void isr28 ();
extern void isr29 ();
extern void isr30 ();
extern void isr31 ();

/*Prototypes*/
extern void gdt_flush(uint32_t);
extern void idt_flush(uint32_t);

static void init_gdt();
static void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

static void init_idt();
static void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

/* Global vars */

gdt_entry_t	gdt_entries[5];
gdt_ptr_t	gdt_ptr;
idt_entry_t	idt_entries[256];
idt_ptr_t	idt_ptr;

#endif
