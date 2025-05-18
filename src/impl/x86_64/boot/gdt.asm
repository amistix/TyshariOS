global gdt64_pointer
global gdt64_code_segment

section .rodata
bits 32

gdt64:
    dq 0                                ; Null descriptor
.code_segment:
    dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53)
gdt64_pointer:
    dw $ - gdt64 - 1
    dq gdt64

gdt64_code_segment equ 0x08
