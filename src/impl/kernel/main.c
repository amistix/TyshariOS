#include "terminal.h"
#include "io.h"

void enter_command()
{
    terminal_putchar('\n');
    terminal_write("/home/user69/TyshariOS/> ");
}

void get_key() {
    while (!(inb(0x64) & 0x01)) {
        __asm__ volatile ("pause");
    }

    int status = inb(0x64);
        if (status & 0x01)
        {
            uint8_t scan_code = inb(0x60);
            switch (scan_code) {
                case 0x02: terminal_putchar('1'); break;
                case 0x03: terminal_putchar('2'); break;
                case 0x04: terminal_putchar('3'); break;
                case 0x05: terminal_putchar('4'); break;
                case 0x06: terminal_putchar('5'); break;
                case 0x07: terminal_putchar('6'); break;
                case 0x08: terminal_putchar('7'); break;
                case 0x09: terminal_putchar('8'); break;
                case 0x0A: terminal_putchar('9'); break;
                case 0x0B: terminal_putchar('0'); break;
                case 0x10: terminal_putchar('q'); break;
                case 0x11: terminal_putchar('w'); break;
                case 0x12: terminal_putchar('e'); break;
                case 0x13: terminal_putchar('r'); break;
                case 0x14: terminal_putchar('t'); break;
                case 0x15: terminal_putchar('y'); break;
                case 0x16: terminal_putchar('u'); break;
                case 0x17: terminal_putchar('i'); break;
                case 0x18: terminal_putchar('o'); break;
                case 0x19: terminal_putchar('p'); break;
                case 0x1E: terminal_putchar('a'); break;
                case 0x1F: terminal_putchar('s'); break;
                case 0x20: terminal_putchar('d'); break;
                case 0x21: terminal_putchar('f'); break;
                case 0x22: terminal_putchar('g'); break;
                case 0x23: terminal_putchar('h'); break;
                case 0x24: terminal_putchar('j'); break;
                case 0x25: terminal_putchar('k'); break;
                case 0x26: terminal_putchar('l'); break;
                case 0x2C: terminal_putchar('z'); break;
                case 0x2D: terminal_putchar('x'); break;
                case 0x2E: terminal_putchar('c'); break;
                case 0x2F: terminal_putchar('v'); break;
                case 0x30: terminal_putchar('b'); break;
                case 0x31: terminal_putchar('n'); break;
                case 0x32: terminal_putchar('m'); break;
                case 0x39: terminal_putchar(' '); break;
                case 0x0E: terminal_backspace()   ; break;
                case 0x1C: enter_command(); break;
            }

        }
}

void kernel_main() {
    terminal_clear();
    terminal_set_color(TERMINAL_WHITE, TERMINAL_BLACK);

    terminal_write("Welcome to our Brand New World!");

    enter_command();


    while (true){
        get_key();
    }
}
