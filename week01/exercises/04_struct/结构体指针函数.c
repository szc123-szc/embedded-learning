//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//typedef double (*opfunc)(double, double);
//double add(double a, double b) { return a + b; };
//double sub(double a, double b) { return a - b; };
//double mul(double a, double b) { return a * b; };
//double divi(double a, double b) { return a / b; };
//int main()
//{
//	double a, b;
//	char c;
//	int k;
//	opfunc s[] = { add,sub,mul,divi };
//	char ops[] = { '+','-','*','/' };
//	printf("请输入要计算的内容:");
//	if (scanf("%lf%c%lf", &a, &c, &b) != 3)
//	{
//		printf("输入有误\n");
//		return -1;
//	}
//	else
//	{
//		int i;
//		for (i = 0; i < 4; i++)
//		{
//			if (c == ops[i])
//			{
//				k = i;
//				break;
//			}
//		}
//	}
//	if (k == -1)//判断输入的运算符是否在运算符数组中
//	{
//		printf("error\n");
//		return 0;
//	}
//	if (c == '/' && b == 0)
//	{
//		printf("除数不能为0\n");
//		return -1;
//	}
//	printf("%.2lf\n",s[k](a, b));
//}