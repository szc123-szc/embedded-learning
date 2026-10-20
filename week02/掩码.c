#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#define Set_bit(x,n)	((x)|=(1U<<(n)))                
#define Cle_bit(x,n)	((x)&=~(1U<<(n)))
#define Rev_bit(x,n)	((x)^=(1U<<(n)))
#define Read_bit(x,n)	(((x)>>(n))&1U)
void printf_bin(int n)
{
	for (int i = 7; i >= 0; i--)
	{
		putchar( '0' + ((n >> i) & 1U));//传ASC||码也行 ‘0’（字符）+数字=字符
		if (i == 4)putchar(' ');
	}
}
void show(const char* p, int v)
{
	printf("%-18s	0x%02X  ", p, v);//%x打印16进制	%s需要传入首地址
	printf_bin(v);
	printf("\n");
}
int main()
{
	uint8_t x;
	x = 0xA5;
	show("初始值", x);
	Set_bit (x,1);                  // bit1 原来是0，置位后 1010 0111
	show("Set_bit(x,1)", x);
	assert(x == 0xA7);

	x = 0xA5;
	Set_bit(x,0);
	show("Set_bit(x,0)", x);
	assert(x == 0xA5);

	x = 0xA5;
	Cle_bit (x,0);
	show("Cle_bit (x,0)", x);
	assert(x == 0xA4);

	x = 0xA5;
	Cle_bit (x, 7);                // 0010 0101
	show("Cle_bit (x, 7)", x);
	assert(x == 0x25);
	// ----------REV_BIT----------
		x = 0xA5;
	Rev_bit(x, 0);               // 1变0：1010 0100
	show("Rev_bit(x, 0)", x);
	assert(x == 0xA4);

	x = 0xA5;
	Rev_bit(x, 1);               // 0变1：1010 0111
	show("Rev_bit(x, 1)", x);
	assert(x == 0xA7);

	// 连续取反两次，应该回到原值
	x = 0xA5;
	Rev_bit(x, 3);
	Rev_bit(x, 3);
	assert(x == 0xA5);

	// ---------- READ_BIT ----------
	x = 0xA5;                       // 1010 0101
	printf("Read_bit(x,0)=%u\n", Read_bit(x, 0));
	printf("Read_bit(x,1)=%u\n", Read_bit(x, 1));
	assert(Read_bit(x, 0) == 1);
	assert(Read_bit(x, 1) == 0);
	assert(Read_bit(x, 2) == 1);
	assert(Read_bit(x, 6) == 0);
	assert(Read_bit(x, 7) == 1);

	// 读位不应该修改x
	assert(x == 0xA5);
	uint8_t a = 0x01, b = 0x00;
	assert(Read_bit(a | b, 2) == 0);   // 括号不全会在这里失败

	int i = 2;
	x = 0x00;
	Set_bit(x, i | 1);                 // 应该置 bit3，结果 0x08
	assert(x == 0x08);

	printf("All passed\n");
	return 0;
}