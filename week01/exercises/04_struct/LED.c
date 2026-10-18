#include<stdio.h>
typedef enum
{
	LEDON,//0
	LEDOFF,//1
	LEDBLINK//2
}Ledstates;
int main()
{
	Ledstates led = LEDON;
	switch (led)
	{
	case LEDON :   printf ("LEDµÆÁÁ\n");break;//==case 0
	case LEDOFF:   printf("LEDµÆÃð\n"); break;//==case 1
	case LEDBLINK: printf("LEDµÆÉÁË¸\n"); break;//==case 2
	default:       printf("LEDµÆ×´Ì¬´íÎó\n"); break;//
	}
}
