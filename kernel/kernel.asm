;----------------------------------------------------------------
use16         ; 16-bit real mode                                |
org 0x1000    ;                                                 |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Defining bytes                                                |
promptText: db '~/home/amistix>', 0     ;                       |
currentRow: db 0                        ;                       |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Print first command prompt                                    |
mov si, promptText      ; Load 1st symbol to SI (Source index)  |
jmp printPrompt         ; Jump to startup prompt                |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Get character from keyboard                                   |
inputAwaiting:          ;                                       |
    mov ah, 0x00        ; Get key mode                          |
    int 0x16            ; Call keyboard interrupt               |
                        ;                                       |
    cmp al, 0xD         ; Chech code for ENTER                  |
    jz newLine          ; Create new line                       |
                        ;                                       |
    mov ah, 0xE         ; Display character                     |
    int 0x10            ; Call video interrupt                  |
jmp inputAwaiting       ; Loop it                               |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Creating prompt                                               |
printPrompt:            ;                                       |
    mov al, [si]        ; Move address of symbol into AL        |   
    mov ah, 0xE         ; Display character                     |          
                        ;                                       |
    inc si              ; Increment address                     |
    cmp al, 0           ; Chech for terminatig zero             |
    je inputAwaiting    ; Retun access to typing                |
                        ;                                       |
    int 0x10            ; Call video interrupt                  |
jmp printPrompt         ; Loop it                               |
;----------------------------------------------------------------

;----------------------------------------------------------------
; Create a new line                                             |
newLine:                    ;                                   |
    mov ah, 0x02            ; Moving cursor subroutine          |
    mov dl, 0x00            ; Set column position               |
    mov dh, [currentRow]    ; Set row position                  |
                            ;                                   |
    inc dh                  ; Increase variable                 |
    mov [currentRow], dh    ;                                   |
    int 0x10                ; Call display interrupt            |
    mov si, promptText      ;                                   |
jmp printPrompt             ; Back to awaiting                  |
;----------------------------------------------------------------

jmp $

;----------------------------------------------------------------
; Halt the processor                                            |
haltProcessor:  ;                                               |
    cli         ; stop receiving interrupts                     |
    hlt         ; Halt processor command                        |
;----------------------------------------------------------------

