#include "vga.h"
#include "../console/console.h"
#include "../libc/string.h"

/*
 * print a string in kernel mode.
 */
void kprint(char *str) {
  vga_print(str);
}


void kprint_color(char *str, int c) {
  set_color(c);
  kprint(str);
  set_color(0x0f);
}


void kprintln(char *str) {
  int len = strlen(str);
  vga_print(str);
  kprint("\n");
}

void clear() {
  vga_clear();
}
