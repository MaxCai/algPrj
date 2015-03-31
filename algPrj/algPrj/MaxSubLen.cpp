/************************************************************************
**ye.cai
**2015.3.31
**最长递增子序列
************************************************************************/

#include <stdio.h>

void MaxsubLen(int *a, int n)
{
	if(n < 1)
		return;
	int *LenK = new int[n];//以a[k]为结尾的最长子序列长度
	int *PreK = new int[n];//以a[k]为结尾的最长子序列上一个元素的位置

	//init
	int MaxLen = 1;
	int pos = 0;
	LenK[0] = 1;
	PreK[0] =  -1;

	for(int i = 1; i < n; ++i)
	{
		int iMaxLen = 1;//以a[i]结尾的最长递增序列长度
		int iPrePos = -1;//以a[i]结尾的最长递增序列的上一个元素
		for(int j = 0; j < i; ++j)
		{
			if(a[i] > a[j] && LenK[j] + 1 > iMaxLen)
			{
				iMaxLen = LenK[j] + 1;
				iPrePos = j;
			}
		}

		PreK[i] = iPrePos;
		LenK[i] = iMaxLen;

		if(MaxLen < iMaxLen)
		{
			MaxLen = iMaxLen;
			pos = i;
		}
	}

	printf("max length is: %d\n", MaxLen);
	printf("from back to front is:\n");
	while (pos >= 0)//用栈输出的话则从前往后
	{
		printf("%d ", a[pos]);
		pos = PreK[pos];
	}

	printf("\n");

}

/**********************************
************test case**************
int a[10] = {1,3,4,0,5,7,8,2,6,9}; 
MaxsubLen(a, 10);
***********************************/