#include <stdio.h>
#include <assert.h>
typedef struct
{
	int id;
	char name[20];
	float score;
}Student;
int Print_Student(const Student* s, int n)
{
	if (s == NULL)return 0;
	for (int i = 0; i < n; i++)
	{
		printf("%d   %s   %.2f\n", (s + i)->id, (s + i)->name, (s + i)->score);
	}
}
int sort_score(Student* s, int n)
{
	int i, j;
	if (n <= 0 || s == NULL)//判断数据是否有误
	{
		printf("数据有误\n");
		return -1;
	}
	for (i = 0; i < n - 1; i++)//冒泡排序
	{
		for(j = 1; j < n - i; j++)
		{
			if (s[j].score > s[j - 1].score)
			{
				Student temp = s[j-1];
				s[j - 1] = s[j];
				s[j] = temp;
			}
		}
	}
	return 0;
}
int main()
{
	Student s[5] = {
		{2001,"张三",90},
		{2002,"李四",98},
		{2003,"王五",88},
		{2004,"赵六",92},
		{2005,"孙七",95}
	};
	int L = sizeof(s) / sizeof(s[0]);//计算数组元素个数，一个{}算一个元素
	Student* p = s;
	printf("排序前的排名:\n");
	Print_Student(s, L);
	printf("按成绩排序后:\n");
	sort_score(p, L);
	Print_Student(p, L);
	assert(sort_score(NULL, 5) == -1);
	return 0;
}