BUILDDIR ::= ./build
SRCDIR ::= ./src
INCDIR ::= ./src/kernel/include

AS ::= nasm
CC ::= $(HOME)/opt/i386-elf-cross/bin/i386-elf-gcc

all:	run

$(BUILDDIR)/kernel.bin:		$(BUILDDIR)/kernel-entry.o		$(BUILDDIR)/kernel.o
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

$(BUILDDIR)/kernel-entry.o:		$(SRCDIR)/kernel/kernel-entry.asm
	$(AS) $< -f elf -o $@

$(BUILDDIR)/kernel.o:		$(SRCDIR)/kernel/kernel.c
	$(CC) -m32 -ffreestanding -c $< -o $@

$(BUILDDIR)/boot.bin:		$(SRCDIR)/bootloader/boot.asm
	$(AS) $< -f bin -o $@

$(BUILDDIR)/os-image.bin:		$(BUILDDIR)/boot.bin		$(BUILDDIR)/kernel.bin
	cat $^ > $@

run:		$(BUILDDIR)/os-image.bin
	qemu-system-i386 -fda $<

clean:
	rm -r $(BUILDDIR)/*.bin $(BUILDDIR)/*.o