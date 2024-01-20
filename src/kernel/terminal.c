#include "Terminal.h"
#include "VGA.h"

#include <stdint.h>

static const uint8_t TERMINAL_WIDTH = 80;
static const uint8_t TERMINAL_HEIGHT = 25;
static uint16_t* const TERMINAL_MEMORY = (uint16_t*) 0xB8000;

static uint8_t row;
static uint8_t column;
static uint8_t colour;
static uint16_t* terminal_buffer;

void terminal_init(void) {
    row = 0;
    column = 0;
    colour = vga_entry_colour(VGA_COLOUR_LIGHT_GRAY, VGA_COLOUR_BLACK);
    terminal_buffer = TERMINAL_MEMORY;

    terminal_clear();
}

void terminal_clear() {
    for (uint8_t i = 0; i < TERMINAL_WIDTH; i++) {
        for (uint8_t j = 0; j < TERMINAL_HEIGHT; j++) {
            const uint16_t temp = j * TERMINAL_WIDTH + i;
            terminal_buffer[temp] = vga_entry(' ', colour);
        }
    }
}

void terminal_set_colour(uint8_t new_colour) {
    colour = new_colour;
}

void terminal_put_char(uint8_t c) {

}

void terminal_put_char_at(uint8_t c, uint8_t colour, uint8_t x_pos, uint8_t y_pos) {

}

void terminal_scroll(uint8_t line) {

}

void terminal_delete_last_line(void) {
    int *ptr;

    for (int i = 0; i < )
}

void terminal_write(const char* data, uint8_t length) {
    for (uint8_t i = 0; i < length; i++) {
        terminal_put_char(data[i]);
    }
}

void terminal_write_string(const char* data) {
    terminal_write(data, strlen(data));
}