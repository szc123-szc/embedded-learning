#include <stdio.h>
#include <assert.h>
#include <string.h>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	//或
	/*
	if (a == b) return;
	*a ^= *b; 10=10^20;
	*b ^= *a; 
	*a ^= *b;
	*/
}
size_t my_strlen(const char* p)
{
	if (p == NULL)return 0;
	const char* q = p;
	while (*q)
	{
		q++;
	}
	return q - p;
}
void test_swap(void)
{
	int x, y;

	// 用例1：正常情况
	x = 3; y = 5;
	swap(&x, &y);
	assert(x == 5 && y == 3);

	// 用例2：边界情况（含0和负数）
	x = 0; y = -7;
	swap(&x, &y);
	assert(x == -7 && y == 0);

	// 用例3：特殊情况（两个值相等）
	x = 9; y = 9;
	swap(&x, &y);
	assert(x == 9 && y == 9);
	printf("swap测试通过\n");
}
void test_strlen(void)
{
	// 用例1：正常情况
	assert(my_strlen("hello") == 5);

	// 用例2：边界情况（空字符串）
	assert(my_strlen("") == 0);

	// 用例3：特殊情况（中间有空格；中间有 '\0' 只算到它之前）
	assert(my_strlen("a b c") == 5);
	assert(my_strlen("ab\0cd") == 2);
	printf("my_strlen测试通过\n");
}
int main()
{
	test_swap();
	test_strlen();
	return 0;
}