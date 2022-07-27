#include "keyboard.h"
#include "../console/menu.h"
#include "../cpu/io.h"
#include "display.h"
#include "../cpu/isr.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include "../console/console.h"
char buffer[MAX_BUFFER];
int pos = -1;

const char keys[] = {
    '?', '?', '1', '2', '3', '4', '5', '6', '7', '8', '9',  '0', '-', '=',  '?',
    '?', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',  '[', ']', '?',  '?',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', '?', '\\', 'Z',
    'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '?', '?',  '?', ' '};

void process_keyboard(registers_t regs) {

  unsigned char scancode = in8(0x60);


  if (scancode > 57) {
    return;
  }

  if (pos >= MAX_BUFFER) {
    kprint("command so long...\n");
    memset(buffer, 256, '\0');
    pos = -1;
  }

  if (scancode == K_ENTER) {
    menu_exec(buffer); // execute menu interaction
    memset(buffer, pos, '\0'); // reset a buffer with nullb value
    pos = -1; // set buffer position to 0
    return;

  } else if (scancode == K_BACKSPACE) {
    if (pos <= -1) {
      pos = -1;
      return;
    }

    buffer[pos] = '\0';
    pos--;

    vga_write_begin_line(prompt);
    kprint(buffer);
    return;
  }


  char c = keys[scancode]; // cast to int hex value.
  if (c == '?') {
    return;
  }
  char letter[2] = {c, '\0'};
  pos++;
  buffer[pos] = c;
  kprint(letter);
}

void init_keyboard() {
  register_handler(33, process_keyboard);
}
