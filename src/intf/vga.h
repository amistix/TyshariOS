#pragma once

#include "sios.h"

void vga_init(void);

void vga_put_char(
    size_t row,
    size_t col,
    char character,
    uint8_t color
);

void vga_clear_row(size_t row);
void vga_clear_screen(void);

void vga_scroll_down(void);

void vga_move_cursor(size_t row, size_t col);
