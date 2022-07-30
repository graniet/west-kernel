GCC = i386-linux-gcc
LD = i386-linux-ld
all: build
build: clean
		nasm -f bin -o boot.bin boot/boot.asm
		nasm -f elf -o kernel-entry.o boot/kernel_entry.asm
		nasm -f elf -o kernel-isr.o cpu/interrupt.asm
		$(GCC) -ffreestanding -o driver.o -c drivers/util.c
		$(GCC) -ffreestanding -o vga.o -c drivers/vga.c
		$(GCC) -ffreestanding -o idt.o -c cpu/idt.c
		$(GCC) -ffreestanding -o isr.o -c cpu/isr.c
		$(GCC) -ffreestanding -o io.o -c cpu/io.c
		$(GCC) -ffreestanding -o string.o -c libc/string.c
		$(GCC) -ffreestanding -o pic.o -c cpu/pic.c
		$(GCC) -ffreestanding -o screen.o -c drivers/display.c
		$(GCC) -ffreestanding -o keyboard.o -c drivers/keyboard.c
		$(GCC) -ffreestanding -o kernel.o -c kmain.c
		$(GCC) -ffreestanding -o menu.o -c console/menu.c
		$(GCC) -ffreestanding -o console.o -c console/console.c
		$(GCC) -ffreestanding -o mem.o -c libc/mem.c
		$(GCC) -ffreestanding -o heap.o -c sys/heap.c
		$(GCC) -ffreestanding -o kheap.o -c sys/kheap.c
		$(LD) -o kernel.bin -Ttext 0x1000 --oformat binary kernel-entry.o kernel.o screen.o driver.o vga.o idt.o isr.o kernel-isr.o io.o pic.o string.o keyboard.o console.o mem.o menu.o heap.o kheap.o
		cat boot.bin kernel.bin > os

clean:
		rm -rf *.o *.bin os*
