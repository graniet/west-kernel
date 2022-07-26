#include "vga.h"

int position_y = 0;
int position_x = 0;

int color = 0x0f; // black background and white color
char *vga = (char *)VGA_RAM; // VGA ram buffer address

/*
 * print a string on screen and intepret a new line char.
 * in VGA two bytes represent a char we have (first=char, second=option like bgcolor, color etc..)
 */
void vga_print(char *s) {
  while (position_y >= 25) {
    scroll_down();
  }

  for (int x = 0; s[x] != 0; x++) {

    if (s[x] == NEW_LINE) {
      position_y += 1;
      position_x = 0;
      continue;
    }

    int position_final = (position_y * MAX_LINE_CHAR) + position_x;

    vga[position_final] = s[x];
    vga[position_final + 1] = color;

    position_x += 2;
    if (position_x >= MAX_LINE_CHAR) {
      position_y += 1;
      position_x = 0;
    }
  }
}

/*
 * function scroll when we have more then 25 line in VGA text mode
 * default size if 80 * 25
 */
void scroll_down() {
  for (int x = 1; x < 25; x++) {

    int off = (x * MAX_LINE_CHAR) + 0xb8000;
    int l_off = ((x-1) * MAX_LINE_CHAR) + 0xb8000;

    char * offset = (char *)off;
    char * last_offset = (char *) l_off;

    for (int i = 0; i < MAX_LINE_CHAR; i++) {
      *(last_offset + i) = *(offset + i);
    }
  }

  int last_off = (24 * MAX_LINE_CHAR) + 0xb8000;
  char * off = (char *) last_off;

  for (int i = 0; i < MAX_LINE_CHAR; i+= 2) {
    *(off + i) = ' ';
    *(off + (i + 1)) = color;
  }

  position_x = 0;
  position_y--;
}


/*
 * clear all text on screen
 */
void vga_clear() {
  int limit = MAX_LINE_CHAR * 25;
  for (int x = 0; x <= limit; x+=2) {
    vga[x] = ' ';
    vga[x + 1] = color;
  }

  position_x = 0;
  position_y = 0;
}
