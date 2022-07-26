#include "../lib/type.h"

#define IDT_MAX_ENTRY 256

typedef struct idt_entry {
  u16 offset_low;
  u16 selector;
  u8 zero;
  u8 flags;
  u16 offset_high;
} __attribute__((packed)) idt_entry_t;

typedef struct idt_register {
  u16 size;
  u32 base;
} __attribute__((packed)) idt_register_t;


void init_idt();
void add_idt_entry(int id, u32 handler);
