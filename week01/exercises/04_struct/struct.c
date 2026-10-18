#include <stdio.h>
typedef struct
{
	int x;
	int y;
}Point;
void Print_Point(const Point* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d%d\n", (p + i)->x, (p + i)->y);
	}
}
int main()
{
	Point s[] =
	{
		{1,2},
		{3,4},
		{5,6},
	};
	int L = sizeof(s) / sizeof(s[0]);
	Print_Point(s, L);
}