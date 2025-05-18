#include "sios.h"

unsigned char port_byte_in(unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void port_byte_out(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

void enter_command()
{
    print_newline();
    print_str("/home/user69/TyshariOS/> ");
}

void get_key() {
    int status = port_byte_in(0x64);
        if (status & 0x01)
        {
            uint8_t scan_code = port_byte_in(0x60);
            switch (scan_code) {
                case 0x02: print_char('1'); break;
                case 0x03: print_char('2'); break;
                case 0x04: print_char('3'); break;
                case 0x05: print_char('4'); break;
                case 0x06: print_char('5'); break;
                case 0x07: print_char('6'); break;
                case 0x08: print_char('7'); break;
                case 0x09: print_char('8'); break;
                case 0x0A: print_char('9'); break;
                case 0x0B: print_char('0'); break;
                case 0x10: print_char('q'); break;
                case 0x11: print_char('w'); break;
                case 0x12: print_char('e'); break;
                case 0x13: print_char('r'); break;
                case 0x14: print_char('t'); break;
                case 0x15: print_char('y'); break;
                case 0x16: print_char('u'); break;
                case 0x17: print_char('i'); break;
                case 0x18: print_char('o'); break;
                case 0x19: print_char('p'); break;
                case 0x1E: print_char('a'); break;
                case 0x1F: print_char('s'); break;
                case 0x20: print_char('d'); break;
                case 0x21: print_char('f'); break;
                case 0x22: print_char('g'); break;
                case 0x23: print_char('h'); break;
                case 0x24: print_char('j'); break;
                case 0x25: print_char('k'); break;
                case 0x26: print_char('l'); break;
                case 0x2C: print_char('z'); break;
                case 0x2D: print_char('x'); break;
                case 0x2E: print_char('c'); break;
                case 0x2F: print_char('v'); break;
                case 0x30: print_char('b'); break;
                case 0x31: print_char('n'); break;
                case 0x32: print_char('m'); break;
                case 0x39: print_char(' '); break;
                case 0x1C: enter_command(); break;
            }

        }
}

void kernel_main() {
    clear_screen();
    set_color(COLOR_YELLOW, COLOR_BLACK);

    print_str("Welcome to our new brand world!");

    enter_command();
    while (true){
        get_key();
    }
}