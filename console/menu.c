#include "menu.h"
#include "../drivers/display.h"
#include "../libc/string.h"
#include "console.h"
#include "../drivers/vga.h"

void menu_exec(char *line) {

  // checking menu
  if (strcmp("net.run", line) == 0) {
    kprint_color("\n[info] running networking configuration...\n", (BG_BLACK | LIGHT_GREY));
  }
  else {
    kprint_color("\ncommand not found, please use: help or h\n", (BG_BLACK | RED));
  }

  // reinitialize a console prompt
  set_prompt();
}
