#include "../lib/type.h"
#include "idt.h"

idt_entry_t idt[IDT_MAX_ENTRY];
idt_register_t idt_ptr;

void init_idt() {
  idt_ptr.base = (u32) &idt;
  idt_ptr.size = ((IDT_MAX_ENTRY - 1) * sizeof(idt_entry_t));
  __asm__("lidt (%0)" :: "r"(&idt_ptr));
}

void add_idt_entry(int id, u32 handler) {
  idt_entry_t entry;
  entry.offset_low = (handler & 0xFFFF);
  entry.selector = 0x08;
  entry.zero = 0;
  entry.flags = 0b10001110;
  entry.offset_high = (handler >> 16) & 0xFFFF;
  idt[id] = entry;
}
