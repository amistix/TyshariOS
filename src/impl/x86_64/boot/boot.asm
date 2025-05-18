global start
extern check_multiboot
extern check_cpuid
extern check_long_mode
extern setup_page_tables
extern enable_paging
extern gdt64_pointer
extern gdt64_code_segment
extern long_mode_start

section .text
bits 32
start:
    mov esp, stack_top

    call check_multiboot
    call check_cpuid
    call check_long_mode

    call setup_page_tables
    call enable_paging

    lgdt [gdt64_pointer]
    jmp gdt64_code_segment:long_mode_start

    hlt

section .bss
align 4096
stack_bottom:
    resb 4096 * 4
stack_top:
