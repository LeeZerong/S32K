#ifndef __XMODEM_H__
#define __XMODEM_H__
//#include "common.h"
#include <stdbool.h>
#include <stdint.h>

#define APP_IMAGE_START     0x5000

void xmodem_init(void);
void xmodem_uart_pinmux_config(void);
uint32_t xmodem_download(void);
bool xmodem_is_active(void);
void xmodem_queue_byte(uint8_t byte);
void xmodem_putchar(char x);
bool xmodem_getchar_present(void);
void xmodem_uart_handler(void);

#endif
