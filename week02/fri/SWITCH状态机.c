#include <stdio.h>
typedef enum
{
	KEY_IDLE,
	KEY_DEBOUNCE,
	KEY_PRESSED,
	KEY_RELEAS
}Keystate;
int count;
static Keystate state = KEY_IDLE;//定义枚举变量
int key_scan(int level)
{
	int temp = -1;//标志
	switch (state)
	{
	case KEY_IDLE:
		if (level == 0)
		{
			state = KEY_DEBOUNCE;
		}
		break;
	case KEY_DEBOUNCE:
		if (level == 0)
		{
			state = KEY_PRESSED;
			temp = 0;
			count++;
		}
		else
			state = KEY_IDLE;
		break;
	case KEY_PRESSED:
		if (level == 1)
		{
			state = KEY_RELEAS;
		}
		break;
	case KEY_RELEAS:
		if (level == 1)
		{
			state = KEY_IDLE;
			temp = 1;
		}
		else
			state = KEY_PRESSED;
		break;
	}
	return temp;
}
int main()
{
	int s[] = { 1,1,0,1,0,0,0,0,1,0,1,1,1 };
	int n = sizeof(s) / sizeof(s[0]);
	for (int i = 0; i < n; i++)
	{
		int x = key_scan(s[i]);
		printf("t=%d   电平状态%d\n", i,s[i]);//0按下1松开
		if (x == 0)
		{
			printf("按键按下状态\n");
		}
		if (x == 1)
		{
			printf("按键松开状态\n");
		}
	}
	printf("按键按下了%d次\n", count);
	return 0;
}