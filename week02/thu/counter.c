#include <stdio.h>
#include "counter.h"
static s_count = 0;//全局变量，全文可调用
void count_int(void)
{
	//static s_count = 0;//局部变量，只能在本函数中调用，只初始化一次，值得以保存
	s_count++;//调用一次void count_int(void)s_count加一
}
int count_get(void)
{
	return s_count;
}