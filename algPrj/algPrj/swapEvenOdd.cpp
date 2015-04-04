/************************************************************************
**ye.cai
**2015.4.4
**输入一个整数数组，调整数组中数字的顺序，使得所有奇数位于数组的前半部分，
**所有偶数位于数组的后半部分。要求时间复杂度为O(n)。
************************************************************************/

#include <stdio.h>

void swapEvenOdd(int *a, int n)
{
	if(n <= 1)
		return;

	int low = 0;
	int high = n - 1;
	int temp;
	while(true)
	{
		while(a[low] % 2)
			++low;
		while(a[high] % 2 == 0)
			--high;
		if(low < high )
		{
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
		else
			break;
		++low;
		--high;
	}
	
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*********************************
*************test case************
int a[10] = {0,1,2,3,4,5,6,7,8,9};
swapEvenOdd(a, 10);
int b[6] = {4,3,5,2,7,6};
swapEvenOdd(b, 6);
**********************************/