#include "vga.h"
#include "../console/console.h"

/*
 * print a string in kernel mode.
 */
void kprint(char *str) {
  vga_print(str);
  if (str[0] == '\n') {
    set_prompt();
  }
}

void clear() {
  vga_clear();
}
