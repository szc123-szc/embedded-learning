#include <stdio.h>
#include <stdint.h>
#include "led.h"
#define SET_BIT(led,n) ((led)|=(1U<<n))
#define CLR_BIT(led,n) ((led)&=~(1U<<n))
#define TOG_BIT(led,n) ((led)^=(1U<<n))
#define READ_BIT(led,n) (((led)>>n)&1U)
static uint8_t state =0x00;
int led_on(uint8_t n)
{
	if (n >= LED_COUNT)
	{
		return -1;
	}
		SET_BIT(state, n);
		return 0;
}
int led_off(uint8_t n)
{
	if (n >= LED_COUNT)
	{
		return -1;
	}
	CLR_BIT(state, n);
	return 0;
}
int led_tog(uint8_t n)
{
	if (n >= LED_COUNT)
	{
		return -1;
	}
	TOG_BIT(state, n);
	return 0;
}
void led_show(void)
{
	printf("LED: ");
	for (int i = 7; i >=0; i--)
	{
		putchar('0' + READ_BIT(state, i));
		if (i == 4)putchar(' ');
	}
	printf("\n");
}

