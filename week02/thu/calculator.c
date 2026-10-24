#include <stdio.h>
#include "calculator.h"
#include <math.h>
typedef double (*func_p) (double, double);
static double add(double a, double b) { return a + b; }
static double sub(double a, double b) { return a - b; }
static double mul(double a, double b) { return a * b; }
static double divl(double a, double b) { return a / b; }
double calcu(double a, double b, char c)
{
	int k=-1;
	func_p tab[] = { add,sub,mul,divl};
	char ops[] = "+-*/";
	for (int i = 0; i < 4; i++)
	{
		if (ops[i] == c)
		{
			k = i;
			break;
		}
	}
	if (k == -1)
	{
		printf("error");
		return -2;
	}
	if (ops[k] == '/' && b == 0)
	{
		printf("除数不能为零");
		return -1;
	}
	printf("%.2f\n", tab[k](a, b));
	return 0;
}