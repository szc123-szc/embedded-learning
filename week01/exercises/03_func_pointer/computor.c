////函数指针
//#include<stdio.h>
//int add(int a, int b) { return a + b; };
//int sub(int a, int b) { return a - b; };
//int mul(int a, int b) { return a * b; };
//int my_div(int a, int b) { return a / b; };
//int main()
//{
//	int (*p)(int, int);
//	p = &add;								//加不加&都行，把函数地址赋给p，p通过地址调用函数
//	printf("%d\n", p(6, 3));
//	p = &sub;
//	printf("%d\n", p(6, 3));
//	p = &mul;
//	printf("%d\n", p(6, 3));
//	p = &my_div;
//	printf("%d\n", p(6, 3));
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef double (*op_func)(double, double);//定义函数指针类型 op_func函数指针类型别名
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double my_div(double a, double b) { return a / b; }
int main()
{
	double x; double y; char c;
	int k = -1;
	op_func tablet[] = { add,sub,mul,my_div };//op_funcd定义tablet为函数指针数组，调用时直接写tablet[k](a,b) 
	char    ops[] = { '+','-','*','/' };//运算符数组
	printf("请输入要计算的数学公式：");
	if (scanf("%lf   %c    %lf", &x, &c, &y) != 3)//判断输入的格式是否正确    lf是LF读取double类型，%lf是long float的意思，%f是float类型
	{
		printf("error\n");
		return 0;
	}
	for (int i = 0; i < 4; i++)
	{
		if (ops[i] == c)//判断输入的运算符是否在运算符数组中
		{
			k = i;//如果在运算符数组中，k就等于运算符数组的下标
			break;
		}	
	}
	if (k == -1)//如果输入的运算符不在运算符数组中，k就等于-1
	{
		printf("error\n");
		return 0;
	}
	
	if (c == '/' && y == 0)
	{
		printf("除数不能为0\n");
	}
	else
	{
		printf("%.2f\n", tablet[k](x, y));
	}
	return 0;
}
