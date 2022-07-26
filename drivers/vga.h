#define VGA_RAM 0xb8000
/*
 * VGA driver home made, without outb, inb.
 */
#define VGA_CONTROL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_CURSOR_HIGH_BYTE 14
#define VGA_CURSOR_LOW_BYTE 15

// VGA TEXT MODE
#define VGA_TM_SCREEN_SIZE 80
#define VGA_TM_SCREEN_COL 25
#define MAX_LINE_CHAR VGA_TM_SCREEN_SIZE * 2
#define NEW_LINE '\n'

void vga_print(char *s);
void vga_clear();
