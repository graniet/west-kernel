#include "io.h"
#include "../lib/type.h"

void out8(u16 port, u8 data) {
  __asm__("out %%al, %%dx" : : "a"(data), "d"(port));
}

u8 in8(u16 port) {
  u8 result;
  __asm__("in %%dx, %%al" : "=a"(result) : "d"(port));
}

void out16(u16 port, u16 data) {
  __asm__("out %%ax, %%dx" : : "a"(data), "d"(port));
}

u16 in16(u16 port) {
  u16 result;
  __asm__("in %%dx, %%ax" : "=a"(result) : "d"(port));
  return result;
}
