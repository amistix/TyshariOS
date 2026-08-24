#include "vga.h"

#define CURSOR_PORT_CMD 0x3D4
#define CURSOR_PORT_DATA 0x3D5
#define VGA_MEMORY_ADDRESS 0xB8000

static volatile struct Char* buffer =
    (volatile struct Char*)VGA_MEMORY_ADDRESS;

struct Char {
    uint8_t character;
    uint8_t color;
};

static inline void outb(uint16_t port, uint8_t val) {
    __asm__ volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

void vga_move_cursor(size_t row, size_t col)
{
    uint16_t position = row * NUM_COLS + col;
 
    outb(CURSOR_PORT_CMD, 0x0E);
    outb(CURSOR_PORT_DATA, (position >> 8) & 0xFF);

    outb(CURSOR_PORT_CMD, 0x0F);
    outb(CURSOR_PORT_DATA, position & 0xFF);
}

void vga_clear_row(size_t row)
{
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void vga_clear_screen()
{
    for (size_t row = 0; row < NUM_ROWS; row++) {
        vga_clear_row(row);
    }
}

void vga_put_char(
    size_t row,
    size_t col,
    char character,
    uint8_t color)
{
    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };  
}

void vga_scroll_down()
{
    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    } 
    vga_clear_row(NUM_ROWS - 1);
}

void vga_init(){}
