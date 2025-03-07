ORG 0x7C00      ; BIOS loads boot sector here
USE16         ; 16-bit real mode

start:
    ; Print "Booting..."
    mov si, msg
    call print_string

    ; Hang (loop forever)
    jmp $

print_string:
    mov ah, 0x0E    ; BIOS Teletype function
.loop:
    lodsb           ; Load character from SI into AL
    or al, al       ; Check if null terminator
    jz done
    int 0x10        ; Print character
    jmp .loop
done:
    ret

msg db "Booting Twice...", 0

; Fill the rest of the sector with zeros until offset 0x1FE
times 510-($-$$) db 0  

; Boot signature (BIOS requires this)
dw 0xAA55  
