#ifndef __OS_TERMINAL_H__
#define __OS_TERMINAL_H__

#include <stdint.h>

void terminal_init(void);
void terminal_clear(void);
void terminal_set_colour(uint8_t);
void terminal_put_char(uint8_t);
void terminal_put_char_at(uint8_t, uint8_t, uint8_t, uint8_t);
void terminal_scroll(uint8_t);
void terminal_delete_last_line();
void terminal_write(const char*, uint8_t);
void terminal_write_string(const char*);

#endif