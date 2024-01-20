gdt32_start:
    dq 0x00         ;Null segment

gdt32_code:
    dw 0xFFFF       ;Segment length
    dw 0x00         ;Segment base
    db 0x00         ;Segment base
    db 0b10011010   ;Flags
    db 0b11001111   ;Flags (4 bits) and segment length
    db 0x00         ;Segment base

gdt32_data:
    dw 0xFFFF
    dw 0x00
    db 0x00
    db 0b10010010
    db 0b11001111
    db 0x00

gdt32_end:

gdt32_descriptor:
    dw gdt32_end - gdt32_start - 1
    dd gdt32_start

CODE32_SEG equ gdt32_code - gdt32_start
DATA32_SEG equ gdt32_data - gdt32_start