#include <stdio.h>
#include <string.h>
#include <assert.h>
// 修改为包含本地头文件
#include "str_utilize.h"

int main()
{
	char buf[32];
	int x[] = { 1, 2, 3, 2, 1 };
	//strlen
	assert(my_strlen("hello") == 5);
	assert(my_strlen("") == 0);
	assert(my_strlen("a") == 1);
	assert(my_strlen("hello world") == 11);

	//strcpy
	my_strcpy(buf,"hello");
	assert(strcmp(buf, "hello") == 0);
	my_strcpy(buf, "");
	assert(buf[0] =='\0');
	strcpy_s(buf, sizeof(buf), "abcdefg");
	my_strcpy(buf, "hi");
	assert(strcmp(buf, "hi") == 0);
	assert(my_strcpy(buf, "x") == buf);
	//strcat
	strcpy_s(buf, sizeof(buf), "abc");
	my_strcat(buf, "def");
	assert(strcmp(buf, "abcdef") == 0);
	strcpy_s(buf, sizeof(buf), "abc");
	my_strcat(buf, "");
	assert(strcmp(buf, "abc") == 0);
	buf[0] = '\0';
	my_strcat(buf, "xyz");
	assert(strcmp(buf, "xyz") == 0);
	buf[0] = '\0';
	my_strcat(buf, "ab");
	my_strcat(buf, "cd");
	assert(strcmp(buf, "abcd") == 0);


	//reverse
	strcpy_s(buf, sizeof(buf), "abc");
	my_reverse(buf, 3);
	assert(strcmp(buf, "cba") == 0);
	strcpy_s(buf, sizeof(buf), "abcd");
	my_reverse(buf, 4);
	assert(strcmp(buf, "dcba") == 0);
	strcpy_s(buf, sizeof(buf), "a");
	my_reverse(buf, 1);
	assert(strcmp(buf, "a") == 0);

	//symmetry
	my_strcpy(buf, "abcba");
	assert(my_symmetry(buf, 6) == 1);
	my_strcpy(buf, "abccba");
	assert(my_symmetry(buf, 7) == 1);
	my_symmetry_int(x, 5);

	assert(my_reverse(NULL, 0) == -2);
	assert(my_strcmp("abc", "abc") == 0);
	assert(my_strcmp("abc", "abd") < 0);
	assert(my_strcmp("b", "a") > 0);
	assert(my_strcmp("ab", "abc") < 0);
	assert(my_strcmp("", "") == 0);



	assert(my_symmetry("abcba", 6) == 1);// n: 字符串长度 + 1（含 '\0'），例如 "abcba" 传 6
	assert(my_symmetry("abccba", 7) == 1);
	assert(my_symmetry("abcd", 5) == 0);
	assert(my_symmetry("a", 2) == 1);
	assert(my_symmetry_int(x, 5) == 1);
	printf("All passed\n");


	return 0;
}
