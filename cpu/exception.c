#include "exception.h"
#include "idt.h"
#include "../drivers/display.h"

void exception_handler() {
  kprint("Exception received !\n");
}

void init_exception() {
  register_exception(0, (u32)except0);
  register_exception(1, (u32)except1);
  register_exception(2, (u32)except2);
  register_exception(3, (u32)except3);
  register_exception(4, (u32)except4);
  register_exception(5, (u32)except5);
  register_exception(6, (u32)except6);
  register_exception(7, (u32)except7);
  register_exception(8, (u32)except8);
  register_exception(9, (u32)except9);
  register_exception(10, (u32)except10);
  register_exception(11, (u32)except11);
  register_exception(12, (u32)except12);
  register_exception(13, (u32)except13);
  register_exception(14, (u32)except14);
  register_exception(15, (u32)except15);
  register_exception(16, (u32)except16);
  register_exception(17, (u32)except17);
  register_exception(18, (u32)except18);
  register_exception(19, (u32)except19);
  register_exception(0, (u32)except20);
  register_exception(21, (u32)except21);
  register_exception(22, (u32)except22);
  register_exception(23, (u32)except23);
  register_exception(24, (u32)except24);
  register_exception(25, (u32)except25);
  register_exception(26, (u32)except26);
  register_exception(27, (u32)except27);
  register_exception(28, (u32)except28);
  register_exception(29, (u32)except29);
  register_exception(30, (u32)except30);
  register_exception(31, (u32)except31);
  }

/*
 * just a bounding function
 */
  void register_exception(int id, u32 handler) { add_idt_entry(id, handler); }
