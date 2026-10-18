//#include<stdio.h>
//int get_max_min(const int* p, int n, int* max, int* min)
//{
//	*max = *p;
//	*min = *p;
//	if (p == NULL || max == NULL || min == NULL || n <= 0)//判断指针是否为空，n是否小于等于0
//	{
//		return -1;
//	}
//	for (int x = 1; x < n; x++)
//	{
//		if (p[x] > *max)
//		{
//			*max = *(p + x);
//		}
//		if (p[x] < *min)
//		{
//			*min = *(p + x);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int L = sizeof(arr) / sizeof(arr[0]);
//	int max;
//	int min;
//	
//	if( (get_max_min(arr, L, &max, &min)) == 0)
//	{
//		printf("max=%d\n", max);
//		printf("min=%d\n", min);
//	}
//	else
//		printf("error\n");
//	
//}