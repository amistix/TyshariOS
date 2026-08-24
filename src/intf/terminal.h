#pragma once
#include <stdint.h>

enum terminal_color {
    TERMINAL_BLACK = 0,
    TERMINAL_BLUE = 1,
    TERMINAL_GREEN = 2,
    TERMINAL_CYAN = 3,
    TERMINAL_RED = 4,
    TERMINAL_MAGENTA = 5,
    TERMINAL_BROWN = 6,
    TERMINAL_LIGHT_GRAY = 7,
    TERMINAL_DARK_GRAY = 8,
    TERMINAL_LIGHT_BLUE = 9,
    TERMINAL_LIGHT_GREEN = 10,
    TERMINAL_LIGHT_CYAN = 11,
    TERMINAL_LIGHT_RED = 12,
    TERMINAL_PINK = 13,
    TERMINAL_YELLOW = 14,
    TERMINAL_WHITE = 15
};

static uint8_t color = TERMINAL_WHITE | ( TERMINAL_BLACK << 4);

void terminal_init(void);

void terminal_putchar(char c);
void terminal_write(const char* str);

void terminal_backspace(void);
void terminal_clear(void);

void terminal_set_color(uint8_t foreground,
                        uint8_t background);
