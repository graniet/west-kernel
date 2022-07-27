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

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHT_GREY 7
#define DARK_GREY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15

#define BG_BLACK 0x0
#define BG_BLUE 0x1
#define BG_GREEN 0x2
#define BG_CYAN 0x3
#define BG_RED 0x4

void vga_disable_cursor();
void set_color(int c);
void vga_print(char *s);
void vga_clear();
void vga_write_begin_line(char *s);
