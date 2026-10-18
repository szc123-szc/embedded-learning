//指针遍历，求和，反转数组
#include <stdio.h>
void qiuhe(int *p,int n)
{
	int *q = p;
	int i;
	int sum = 0;
	int L = n;
	for (i = 0; i < L; i++)
	{
		sum = sum + q[i];
	}
	printf("%d\n", sum);
}
void fanzhuan(int *p,int n)
{
	int* q = p;
	int L = n;
	for (int i = 0; i < L/2; i++)
	{
		int temp = *(q + i);
		*(q + i) = *(q + (L-1-i));
		*(q + (L - i - 1)) = temp;
	}
}
void printf_(int* p, int n)
{

	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=%d\n", i, *(p + i));
	}
}
int main()
{
	int a[] = { 10,20,30,40,50};
	qiuhe(a, sizeof(a)/sizeof(a[0]));
	fanzhuan(a, sizeof(a) / sizeof(a[0]));
	printf_(a, sizeof(a) / sizeof(a[0]));
}