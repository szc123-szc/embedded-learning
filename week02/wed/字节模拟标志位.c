#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define BIT(n) (1U<<n)
uint8_t flags=0x00;
uint8_t flag1=0x00;
typedef enum
{
	flag_done = BIT(1),
	flag_tiemout=BIT(2),
	flag_error=BIT(3)
}FLAG;
void printf_bin(uint8_t x)
{
	for (int i = 7; i >= 0; i--)
	{
		putchar('0' + ((x >> i) & 1U));
		if (i == 4)putchar(' ');
	}
	printf("\n");
}
int main ()
{
	flags |= flag_done;					// 收到数据，置标志
	if ((flags) & (flag_done))// 主循环里检查
	{
		flags &= ~flag_done;			// 处理完清掉
	}
	flag1 |= BIT(3);          // 置位第3位
	printf_bin(flag1);
	flag1 &= ~BIT(3);          // 清零第3位
	printf_bin(flag1);
	flag1 ^= BIT(3);          // 翻转第3位
	printf_bin(flag1);
	uint8_t v = (flag1 >> 3) & 1;   // 读第3位
	printf_bin(v);
	return 0;
}
