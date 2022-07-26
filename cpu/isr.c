#include "../drivers/display.h"
#include "isr.h"
#include "idt.h"
#include "io.h"
#include "pic.h"
#include "../libc/string.h"

/* To print the message which defines every exception */
char *exception_messages[] = {"Division By Zero",
                              "Debug",
                              "Non Maskable Interrupt",
                              "Breakpoint",
                              "Into Detected Overflow",
                              "Out of Bounds",
                              "Invalid Opcode",
                              "No Coprocessor",

                              "Double Fault",
                              "Coprocessor Segment Overrun",
                              "Bad TSS",
                              "Segment Not Present",
                              "Stack Fault",
                              "General Protection Fault",
                              "Page Fault",
                              "Unknown Interrupt",

                              "Coprocessor Fault",
                              "Alignment Check",
                              "Machine Check",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",

                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved"
};

irq_h handlers[256];

void exception_handler(registers_t r) {
  kprint("received interrupt: ");
  char s[3];
  itoa(r.int_no, s);
  kprint(s);
  kprint("\n");
  kprint(exception_messages[r.int_no]);
  kprint("\n");
}

void init_isr() {
  add_idt_entry(0, (u32)except0);
  add_idt_entry(1, (u32)except1);
  add_idt_entry(2, (u32)except2);
  add_idt_entry(3, (u32)except3);
  add_idt_entry(4, (u32)except4);
  add_idt_entry(5, (u32)except5);
  add_idt_entry(6, (u32)except6);
  add_idt_entry(7, (u32)except7);
  add_idt_entry(8, (u32)except8);
  add_idt_entry(9, (u32)except9);
  add_idt_entry(10, (u32)except10);
  add_idt_entry(11, (u32)except11);
  add_idt_entry(12, (u32)except12);
  add_idt_entry(13, (u32)except13);
  add_idt_entry(14, (u32)except14);
  add_idt_entry(15, (u32)except15);
  add_idt_entry(16, (u32)except16);
  add_idt_entry(17, (u32)except17);
  add_idt_entry(18, (u32)except18);
  add_idt_entry(19, (u32)except19);
  add_idt_entry(0, (u32)except20);
  add_idt_entry(21, (u32)except21);
  add_idt_entry(22, (u32)except22);
  add_idt_entry(23, (u32)except23);
  add_idt_entry(24, (u32)except24);
  add_idt_entry(25, (u32)except25);
  add_idt_entry(26, (u32)except26);
  add_idt_entry(27, (u32)except27);
  add_idt_entry(28, (u32)except28);
  add_idt_entry(29, (u32)except29);
  add_idt_entry(30, (u32)except30);
  add_idt_entry(31, (u32)except31);

  init_pic();

  add_idt_entry(32, (u32)irq0);
  add_idt_entry(33, (u32)irq1);
}

void register_handler(int n, irq_h handler) {
  handlers[n] = handler;
}

void irq_handler(registers_t r) {


  if (r.int_no == 33) {
    handlers[33](r);
  }

  if (r.int_no >= 40)
    out8(0xA0, 0x20); /* slave */
  out8(0x20, 0x20);   /* master */

  
}
