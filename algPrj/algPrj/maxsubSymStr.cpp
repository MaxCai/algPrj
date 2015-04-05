/************************************************************************
**ye.cai
**2015.4.5
����һ���ַ���,������ַ����жԳƵ����ַ�������󳤶�
************************************************************************/

#include <stdio.h>

static int findSym(const char *str, const char* &left, const char* &right)
{
	while(left >= str && *right != '\n' && *left == *right)
	{
		--left;
		++right;
	}

	return right - left - 1;
}

int maxsubSymStr(const char *str)
{
	if(str == NULL)
		return 0;
	int maxLen = 1;

	const char *ptStr = str;
	const char *left;
	const char *right;

	const char *b = NULL;
	const char *e = NULL;
	int temp;
	while(*ptStr != '\0')
	{
		//�Ӵ�����Ϊ����
		left = ptStr - 1;
		right = ptStr + 1;
		temp = findSym(str, left, right);
		if(maxLen < temp)
		{
			maxLen = temp;
			b = left + 1;
			e = right;
		}

		//�Ӵ�����Ϊż��ʱ
		left = ptStr;
		right = ptStr + 1;
		temp = findSym(str, left, right);
		if(maxLen < temp)
		{
			maxLen = temp;
			b = left + 1;
			e = right;
		}

		++ptStr;
	}

	if(b != NULL)
	{
		const char *it = b;
		while(it != e)
		{
			printf("%c", *it);
			++it;
		}
		printf(" %d \n", maxLen);
	}

	return maxLen;
}

/*****************************
**********test case***********
char *a = "google";
maxsubSymStr(a);
char *b = "baiduuud";
maxsubSymStr(b);
char c[] = "bgoogcleduddd";
maxsubSymStr(c);
*****************************/