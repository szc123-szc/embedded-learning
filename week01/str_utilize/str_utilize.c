#include <stdio.h>
#include <string.h>
#include "str_utilize.h"
size_t my_strlen(const char* p)//不能通过p改内容，可以通过p改指针，用其他的指针改值
{
	const char* q = p;
	while (*q)
	{
		q++;
	}
	return q - p;
}
char* my_strcpy(char* dst, const char* src)
{
	char *ret = dst;
	while ((*dst++ = *src++) != '\0');
	return ret;
}
int my_strcmp(const char* s1, const char* s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}
char* my_strcat(char* dst, const char* src)
{
	char* ret = dst;
	while (*dst)
	{
		dst++;
	}
	while ((*dst++ = *src++) != '\0');
	return ret;
}
int my_reverse(char* p,int n)
{
	if (p == NULL || n <= 0)
	{
		return -2;//指针为空或者长度小于等于0，返回-2 直接结束函数
	}
	int i;
	for (i = 0; i < n / 2; i++)
	{
		char a = p[i];
		p[i] = p[n - 1 - i];
		p[n - 1 - i] = a;
	}
	return 0;
}
int my_symmetry(char* p, int n)//判断字符串是否对称
{
	int i;
	int j = 0;
	for (i = 0; i < (n - 1 + 1) / 2; i++)
	{
		if (p[i] == p[n - 2 - i])
		{
			j++;
		}
		else
		{
			printf("不是对称的\n");
			return 0;

		}
		if (j == (n - 1 + 1) / 2)
		{
			printf("是对称的\n");
		}

	}
	return 1;
}
int my_symmetry_int(const int* p, int n)//判断数字是否对称
{
	int i;
	int j = 0;
	for (i = 0; i < (n + 1) / 2; i++)
	{
		if (p[i] == p[n -1 - i])
		{
			j++;
		}
		else
		{
			printf("不是对称的\n");
			return 0;

		}
		if (j == (n + 1) / 2)
		{
			printf("是对称的\n");
		}

	}
	return 1;
}