/************************************************************************
**ye.cai
**2015.3.24
**求整型数组的最大子串和
************************************************************************/

#include <stdio.h>


void maxSubSum(int *a, int n)
{
	if(n < 1)
		return;

	int curVal = a[0];
	int cur_b = 0;
	int cur_e = 0;
	int max = curVal;
	int b = 0;
	int e = 0;

	for(int i = 1; i < n; ++i)
	{
		if(curVal < 0)
		{
			curVal = a[i];
			cur_b = i;
		}
		else
		{
			curVal += a[i];
			cur_e = i;
		}

		if(max < curVal)
		{
			max = curVal;
			b = cur_b;
			e = cur_e;
		}
	}

	printf("max sum = %d, from %d to %d\n", max, b, e);
}

/////////////////////////////////////
/////////////unit test///////////////
/////////////////////////////////////
#define MAXSUBSUMTEST

#ifdef MAXSUBSUMTEST
int main(int argc, char **argv)
{
	int a[3][8] = {
		{-1,3,2,-5,7,3,-6,4},
		{-1,-2,-3,-4,-5,-6,-7,-8},
		{1,2,3,4,5,6,7,8}
	};

	for(int i = 0; i < 3; ++i)
		maxSubSum(a[i], 8);

	getchar();
	return 0;
}
#endif