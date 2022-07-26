[bits 16]
[org 0x7c00]

KERNEL_OFFSET: equ 0x1000

_init:
  mov sp, 0x9000
  mov ax, 2401h                 ; al = 01h sub function, ah = 24h function
  int 15h                       ; activation A20
  mov ax, 0003h                 ; function, sub function
  int 10h                       ; enable VGA mode

  mov [disk], dl                ; numero de disque fournis par le BIOS, car il charge lui meme le boot sector sur ce disk !

  mov ah, 0x2                   ; fonction read
  mov al, 0x24                   ; nombre de secteur a lire
  mov ch, 0x0                  ; cylindre 0
  mov dh, 0x00                  ; tete de lecture
  mov cl, 0x02                   ; numero de secteur
  mov dl, [disk]                ; disque id
  mov bx, KERNEL_OFFSET           ; buffer pour store le resultat de lecture dans la memoire
  int 13h                       ; invocation de l'interuption
  cli
  lgdt [_gdt_pointer]           ; chargement de la GDT

  mov eax, cr0                  ; recuperation de la valeur du registre de control cr0
  or eax, 0x1                   ; on met 1 dans eax
  mov cr0, eax                  ; on ajoute 1 dans le premier bit de cr0 pour activer le mode 32 bit (protected mode)
  mov ax, DATA_SEGMENT          ; on prepare les segment de data
  mov ds, ax                    ; same
  mov es, ax                    ; same
  mov fs, ax                    ; same
  mov gs, ax                    ; same
  mov ss, ax                    ;same

  jmp CODE_SEGMENT:say_hello    ; on jump dans notre partie 32 bits !

_gdt_start:
  dq 0x0
_gdt_code:
  dw 0xFFFF                     ; segment limit 2 bytes (1 word)
  dw 0x0000                     ; segment base 2 bytes (1 word)
  db 0x0                        ; segment base 2 ?
  db 10011010b                  ; access byte for code segment
  db 11001111b                  ; limit, flags
  db 0x0                        ; byte for base
_gdt_data:
  dw 0xFFFF                     ; segment limit 2 bytes (1 word)
  dw 0x0000                     ; segment base 2 bytes (1 word)
  db 0x0                        ; segment base 2 ?
  db 10010010b                  ; access byte for code segment
  db 11001111b                  ; limit, flags
  db 0x0                        ; byte for base
_gdt_end:

_gdt_pointer:
  dw _gdt_end - _gdt_start
  dd _gdt_start

disk:
  db 0

CODE_SEGMENT: equ _gdt_code - _gdt_start
DATA_SEGMENT: equ _gdt_data - _gdt_start

[bits 32]

westworld:  db 'Ghost in the Shell!',0    ; chaine used pour le print !

say_hello:
  mov esi, westworld
  mov ebx, 0xb8000              ; text vga buffer

.loop:
  lodsb
  or al, al
  jz halt
  or eax, 0x0200
  mov word [ebx], ax
  add ebx, 2
  jmp .loop

load_kernel:
  call KERNEL_OFFSET

halt:
  cli
  hlt

times (510 - ($-$$)) db 0
dw 0xaa55
