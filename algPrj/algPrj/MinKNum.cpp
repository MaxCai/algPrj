/************************************************************************
**ye.cai
**2015.4.1
**输入n个整数，输出其中最小的K个数。

**维护一个K个数的最大堆；当新数比堆顶更小时，删掉堆顶，重新调整堆
************************************************************************/
#include <stdio.h>
#include <memory.h>


void adjustHeap(int *arr, int k, int cur)
{
	while(cur < k)
	{
		int child = 2*cur + 1;
		if(child >= k)
			break;

		int temp = 2*(cur + 1);
		if(temp < k && arr[temp] > arr[child] )
			child = temp;
		if(arr[child] > arr[cur])
		{
			int t = arr[child];
			arr[child] = arr[cur];
			arr[cur] = t;

			cur = child;
		}
		else
			break;
	}
}
void createHeap(int *arr, int k)
{
	if(k <= 1)
		return;

	for(int i = k/2 - 1; i >= 0;--i)
	{
		int cur = i;
		adjustHeap(arr, k, cur);
	}
}

void getMinKNum(int *a, int n, int k)
{
	if(k <= 0)
		return;

	if(k < n)
	{
		int *arr = new int[k];
		memcpy(arr, a, k * sizeof(int));

		createHeap(arr, k);

		for(int i = k; i < n; ++i)
		{
			//printf("%d || ", a[i]);
			if(a[i] < arr[0])
			{
				arr[0] = a[i];
				adjustHeap(arr, k, 0);
				
				
				//for(int i = 0; i < k; ++i)
				//	printf("%d ", arr[i]);
			}
			//printf("\n");
		}

		for(int i = 0; i < k; ++i)
			printf("%d ", arr[i]);
		printf("\n");

		delete [] arr;
	}
	else
	{
		for(int i = 0; i < n; ++i)
			printf("%d ", a[i]);
		printf("\n");
	}
}
/*********************************
************test case*************
int a[10] = {0,1,2,3,4,5,6,7,8,9};
getMinKNum(a, 10, 5);
int b[10] = {9,8,7,6,5,4,3,2,1,0};
getMinKNum(b, 10, 5);
int c[10] = {5,6,3,2,9,7,0,8,4,1};
getMinKNum(c, 10, 5);
*********************************/
