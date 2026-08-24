#include "terminal.h"
#include "vga.h"

static size_t current_row = 0;
static size_t current_col = 0;

void terminal_init(){}

void print_newline() {
    current_col = 0;

    if (current_row < NUM_ROWS - 1) {
        current_row++;
        return;
    }

    vga_scroll_down();
    vga_move_cursor(current_row, current_col);
}

void terminal_putchar(char c) 
{
    if (c == '\n') 
    {
        print_newline();
        return;
    }

    if (current_col >= NUM_COLS) {
        print_newline();
    }

    vga_put_char(current_row, current_col, c, color);
    current_col++;
    vga_move_cursor(current_row, current_col);
}

void terminal_backspace()
{
    if (current_col == 0) return;
    current_col--;
    vga_move_cursor(current_row, current_col);
    vga_put_char(current_row, current_col, ' ', color);
}

void terminal_clear()
{
    vga_clear_screen();
}

void terminal_write(const char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') return;

        terminal_putchar(character);
    }
}

void terminal_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}
