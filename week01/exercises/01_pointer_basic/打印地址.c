#include<stdio.h>
int main()
{
	int a[] = { 10,20,30 };
	int* p = &a;
	char* q = NULL;
	double* d = NULL;
	int b = 66;
	int* z = &b;
	int c = 30;
	int* x = &c;
	printf("%p\n", (void*)&c);
	printf("%p\n", &x);
	printf("%p\n", (void*) & b);//b的地址
	printf("%p\n", (&x - &z));
	printf("%p\n", (x - z));
	printf("%d\n", *z);//66
	printf("%d\n", b);//66
	printf("%p\n", z);//b的地址
	printf("%p\n", (void*)&z);//z本身的地址
	printf("%p    %p     %p\n", (void*)&a[0], (void*)&a[1], (void*)&a[2]);//打印a自身的地址
	printf("%p    %p     %p\n", (void*)p, (void*)(p + 1), (void*)(p + 2));//打印p指向的地址
	printf("%p\n", (void*)&p);											  //打印p自身的地址
	printf("%p    %p     %p\n", (void*)q, (void*)(q + 1), (void*)(q + 2));//打印q指向的地址
	printf("%p    %p     %p\n", (void*)d, (void*)(d + 1), (void*)(d + 2));//打印d指向的地址
	printf("%p    %p     %p\n", (void*)p, (void*)(p - 1), (void*)(p - 2));
	printf("%p    %p     %p\n", (void*)q, (void*)(q - 1), (void*)(q - 2));
	printf("%p    %p     %p\n", (void*)d, (void*)(d - 1), (void*)(d - 2));
	printf("%p\n", (void*)&q);
	printf("%p\n", (void*)&d);
	return 0;
}