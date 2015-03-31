/************************************************************************
**ye.cai
**2015.3.31
**�����������
************************************************************************/

#include <stdio.h>

void MaxsubLen(int *a, int n)
{
	if(n < 1)
		return;
	int *LenK = new int[n];//��a[k]Ϊ��β��������г���
	int *PreK = new int[n];//��a[k]Ϊ��β�����������һ��Ԫ�ص�λ��

	//init
	int MaxLen = 1;
	int pos = 0;
	LenK[0] = 1;
	PreK[0] =  -1;

	for(int i = 1; i < n; ++i)
	{
		int iMaxLen = 1;//��a[i]��β����������г���
		int iPrePos = -1;//��a[i]��β����������е���һ��Ԫ��
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
	while (pos >= 0)//��ջ����Ļ����ǰ����
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