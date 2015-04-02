/************************************************************************
**ye.cai
**2015.4.2
**输入一个已经按升序排序过的数组和一个数字，
**在数组中查找两个数，使得它们的和正好是输入的那个数字。
**要求时间复杂度是O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。
************************************************************************/
#include <stdio.h>

void sumof2eq(int *a, int n, int sum)
{
	if(n < 2)
		return;
	if(sum < a[0])
		return;

	int low = 0;
	int high = n - 1;
	while(low < high)
	{
		while(a[low] + a[high] < sum)
			++low;
		while(a[low] + a[high] > sum)
			--high;
		if(low < high && (a[low] + a[high]) == sum)
		{
			printf("%d + %d = %d\n", a[low], a[high], sum);
			break;
		}
	}
}

/********************************
**********test case**************
int a[8] = {1,3,5,9,9,11,13,16};
sumof2eq(a, 8, 20);
int b[5] = {2,4,6,8,10};
sumof2eq(b, 5, 7);
sumof2eq(b, 5, 14);
********************************/