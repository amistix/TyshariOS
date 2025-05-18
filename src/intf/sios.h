//Simple Input/Output System
#pragma once

#include <stdint.h>
#include <stddef.h>

enum {
    COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GRAY = 7,
	COLOR_DARK_GRAY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_PINK = 13,
	COLOR_YELLOW = 14,
	COLOR_WHITE = 15,
};

static inline void outb(uint16_t port, uint8_t val);
void move_cursor(uint8_t row, uint8_t col);

void clear_screen();
void print_newline();
void print_char(char character);
void print_str(char* string);
void set_color(uint8_t foreground, uint8_t background);