[bits 16]
[org 0x7C00]

KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl

mov bp, 0x9000
mov sp, bp

call load_kernel
call switch_protected_mode

jmp $

%include "./src/bootloader/disk.asm"
%include "./src/bootloader/gdt32.asm"
%include "./src/bootloader/protected_mode.asm"

[bits 16]
load_kernel:
    mov bx, KERNEL_OFFSET
    mov dh, 0x02
    mov dl, [BOOT_DRIVE]
    call disk_load
    ret

[bits 32]
BEGIN_32bit:
    call KERNEL_OFFSET
    jmp $

BOOT_DRIVE db 0

times 0x1FE - ($-$$) db 0
dw 0xAA55