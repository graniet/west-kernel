#include "drivers/vga.h"
#include "drivers/util.h"
#include "cpu/idt.h"
#include "cpu/isr.h"
#include "cpu/exception.h"
#include "drivers/display.h"
#include "drivers/keyboard.h"
#include "console/console.h"

void main() {
  vga_clear();
  kprint("Loading kernel...\n");
  kprint("loading CPU exception, IRQ ...\n");
  init_isr();
  kprint("initialization of keyboard drivers...\n");
  init_keyboard();
  kprint("initialization of interrupt descriptor table...\n");
  init_idt();

  kprint("init a console...\n");
  init_console();
  __asm__("sti");
}

