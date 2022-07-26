#include "../lib/type.h"

/* Struct which aggregates many registers */
typedef struct {
  u32 ds; /* Data segment selector */
  u32 edi, esi, ebp, esp, ebx, edx, ecx, eax; /* Pushed by pusha. */
  u32 int_no, err_code; /* Interrupt number and error code (if applicable) */
  u32 eip, cs, eflags, useresp, ss; /* Pushed by the processor automatically */
} registers_t;

void exception_handler(registers_t regs);
void init_isr();

extern void except0();
extern void except1();
extern void except2();
extern void except3();
extern void except4();
extern void except5();
extern void except6();
extern void except7();
extern void except8();
extern void except9();
extern void except10();
extern void except11();
extern void except12();
extern void except13();
extern void except14();
extern void except15();
extern void except16();
extern void except17();
extern void except18();
extern void except19();
extern void except20();
extern void except21();
extern void except22();
extern void except23();
extern void except24();
extern void except25();
extern void except26();
extern void except27();
extern void except28();
extern void except29();
extern void except30();
extern void except31();

extern void irq0();
extern void irq1();

typedef void (*irq_h)(registers_t);
void irq_handler(registers_t r);
void register_handler(int n, irq_h handler);
