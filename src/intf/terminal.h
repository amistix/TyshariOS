#pragma once

#include "sios.h"
#include "vga.h"

void terminal_init(void);

void terminal_putchar(char c);
void terminal_write(const char* str);

void terminal_backspace(void);
void terminal_clear(void);

void terminal_set_color(uint8_t foreground,
                        uint8_t background);
