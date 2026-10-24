#include <stdio.h>
int main()
{
	int a;
	printf("请输入数判断是否为2的幂：\n");
	scanf_s("%d", &a);
	if ((a > 0) && ((a & (a - 1)) == 0))
	{
		printf("是2的幂\n");
	}
	else
	{
		printf("不是2的幂\n");
	}
	return 0;
}