#include <stdio.h>
#include <stdint.h>
//指针型
int is_little_endin()
{
	uint16_t x = 0x0001;//16位2字节
	uint8_t* p = (uint8_t*)&x;//(uint8_t*)&x定义为字节指针,指向x地址的的第一个字节(8位为1字节,每次加1字节)(uint16_t*)指向x地址的的第一，二个字节(16位为2字节,每次加2字节)
	return *p;//返回第一个字节中存放的值
}
//联合体型
union//共占一块内存，大小是最大变量内存的大小
{
	uint16_t w; uint8_t b[2];
}U;
int main()
{
	U.w = 0x0001;
	uint8_t y = is_little_endin();
	printf("%02x\n", y);
	printf("%02x\n", U.b[0]);
	return 0;
}
//输出01为小端 低字节放低地址
//输出00为大端 低字节放高地址
