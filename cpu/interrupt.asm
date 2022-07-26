[extern exception_handler]
[extern irq_handler]

_exception_handler:
  pusha
  mov ax, ds
  push eax
  mov ax, 0x10
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  call exception_handler

  pop eax
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  popa
  add esp, 0x8
  sti
  iret

irq_common_stub:
  pusha
  mov ax, ds
  push eax
  mov ax, 0x10
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  call irq_handler ; Different than the ISR code
  pop ebx  ; Different than the ISR code
  mov ds, bx
  mov es, bx
  mov fs, bx
  mov gs, bx
  popa
  add esp, 8
  sti
  iret

global except0
global except1
global except2
global except3
global except4
global except5
global except6
global except7
global except8
global except9
global except10
global except11
global except12
global except13
global except14
global except15
global except16
global except17
global except18
global except19
global except20
global except21
global except22
global except23
global except24
global except25
global except26
global except27
global except28
global except29
global except30
global except31
global irq0
global irq1

except0:
  cli
  push byte 0
  push byte 0
  jmp _exception_handler


except1:
  cli
  push byte 0
  push byte 1
  jmp _exception_handler

except2:
  cli
  push byte 0
  push byte 2
  jmp _exception_handler

except3:
  cli
  push byte 0
  push byte 3
  jmp _exception_handler

except4:
  cli
  push byte 0
  push byte 4
  jmp _exception_handler

except5:
  cli
  push byte 0
  push byte 5
  jmp _exception_handler

except6:
  cli
  push byte 0
  push byte 6
  jmp _exception_handler

except7:
  cli
  push byte 0
  push byte 7
  jmp _exception_handler

except8:
  cli
  push byte 0
  push byte 8
  jmp _exception_handler

except9:
  cli
  push byte 0
  push byte 9
  jmp _exception_handler

except10:
  cli
  push byte 0
  push byte 10
  jmp _exception_handler

except11:
  cli
  push byte 0
  push byte 11
  jmp _exception_handler

except12:
  cli
  push byte 0
  push byte 12
  jmp _exception_handler

except13:
  cli
  push byte 0
  push byte 13
  jmp _exception_handler

except14:
  cli
  push byte 0
  push byte 14
  jmp _exception_handler

except15:
  cli
  push byte 0
  push byte 15
  jmp _exception_handler


except16:
  cli
  push byte 0
  push byte 16
  jmp _exception_handler

except17:
  cli
  push byte 0
  push byte 17
  jmp _exception_handler

except18:
  cli
  push byte 0
  push byte 18
  jmp _exception_handler

except19:
  cli
  push byte 0
  push byte 19
  jmp _exception_handler

except20:
  cli
  push byte 0
  push byte 20
  jmp _exception_handler

except21:
  cli
  push byte 0
  push byte 21
  jmp _exception_handler

except22:
  cli
  push byte 0
  push byte 22
  jmp _exception_handler

except23:
  cli
  push byte 0
  push byte 23
  jmp _exception_handler

except24:
  cli
  push byte 0
  push byte 24
  jmp _exception_handler

except25:
  cli
  push byte 0
  push byte 25
  jmp _exception_handler

except26:
  cli
  push byte 0
  push byte 26
  jmp _exception_handler

except27:
  cli
  push byte 0
  push byte 27
  jmp _exception_handler

except28:
  cli
  push byte 0
  push byte 28
  jmp _exception_handler

except29:
  cli
  push byte 0
  push byte 29
  jmp _exception_handler

except30:
  cli
  push byte 0
  push byte 30
  jmp _exception_handler

except31:
  cli
  push byte 0
  push byte 31
  jmp _exception_handler

  ; IRQ handlers
irq0:
	cli
	push byte 0
	push byte 32
	jmp irq_common_stub

irq1:
	cli
	push byte 1
	push byte 33
	jmp irq_common_stub

