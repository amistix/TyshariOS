;----------------------------------------------------------------
use16                       ; 16-bit real mode                  |
org 0x7c00                  ; BIOS loads boot sector here       |
KERNEL_OFFSET equ 0x1000    ;                                   |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Set up the screen                                             |
mov ah, 0x00  ; Clear screen                                    |               
mov al, 0x03  ; Set video mode to 3                             |
int 0x10      ; Run graphics interrupt                          |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Load kernel                                                   |
load_kernel:               ;                                    |
   mov [boot_disk], dl     ;                                    |
   mov bx, KERNEL_OFFSET   ;                                    |
   mov dh, 15              ;                                    |
   mov dl, [boot_disk]     ;                                    |
                           ;                                    |
   mov ah, 0x02            ;                                    |
   mov al, dh              ;                                    |
   mov ch, 0x00            ;                                    |
   mov dh, 0x00            ;                                    |
   mov cl, 0x02            ;                                    |
   int 0x13                ;                                    |
   jmp KERNEL_OFFSET       ;                                    |
jmp $                      ;                                    |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Define variables                                              |
boot_disk: db 0      ;                                          |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Bootale requirement                                           |
times 510-($-$$) db 0   ; Fill with zeros until offset 0x1FE    |
dw 0xaa55               ; Boot signature                        |                                      
;----------------------------------------------------------------
