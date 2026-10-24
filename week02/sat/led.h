#ifndef LED_H
#define LED_H
#define LED_COUNT 8
#include <stdint.h>
int led_on(uint8_t n);
int led_off(uint8_t n);
int led_tog(uint8_t n);
void led_show(void);

#endif