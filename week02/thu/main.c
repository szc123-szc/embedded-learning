#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "calculator.h"
int main()
 {
	double x, y;
	char z;
	printf("«Î ‰»Î:");
	if (scanf("%lf   %c    %lf", &x, &z, &y) != 3)
	{
		printf("error\n");
		return 0;
	}
	calcu(x, y, z);
	count_int();
	printf("%d\n", count_get());
	return 0;
}