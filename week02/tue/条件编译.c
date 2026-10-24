//条件编译开关测试
#include <stdio.h>
#define DEBUG 0
#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif
int add(int a, int b)
{
	int sum = a + b;
	LOG("%d\n", a);
	LOG("%d\n", b);
	LOG("%d\n", sum);
	return sum;
}
int main(void)
{
	int a = 10;
	int b = 20;
	int x = add(a, b);
	printf("%d\n", x);
	return 0;
}