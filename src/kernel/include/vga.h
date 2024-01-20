#ifndef __OS_VGA_H__
#define __OS_VGA_H__

#include <stdint.h>

enum vga_colour {
    VGA_COLOUR_BLACK = 0x0,
    VGA_COLOUR_BLUE = 0x1,
    VGA_COLOUR_GREEN = 0x2,
    VGA_COLOUR_CYAN = 0x3,
    VGA_COLOUR_RED = 0x4,
    VGA_COLOUR_MAGENTA = 0x5,
    VGA_COLOUR_BROWN = 0x6,
    VGA_COLOUR_LIGHT_GRAY = 0x7,
    VGA_COLOUR_DARK_GRAY = 0x8,
    VGA_COLOUR_LIGHT_BLUE = 0x9,
    VGA_COLOUR_LIGHT_GREEN = 0xA,
    VGA_COLOUR_LIGHT_CYAN = 0xB,
    VGA_COLOUR_LIGHT_RED = 0xC,
    VGA_COLOUR_LIGHT_MAGENTA = 0xD,
    VGA_COLOUR_LIGHT_BROWN = 0xE,
    VGA_COLOUR_WHITE = 0xF,
};

static inline uint8_t vga_entry_colour(enum vga_colour foreground, enum vga_colour background) {
    return foreground | background << 0x4;
}

static inline uint16_t vga_entry(unsigned char c, uint8_t colour) {
    return (uint16_t) c | (uint16_t) colour << 0x8;
}

#endif