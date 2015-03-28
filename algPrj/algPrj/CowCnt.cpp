/*
**ye.cai
**2015.3.28

һֻ�ճ�������ţ��4����1ֻ��ţ���Ժ�ÿһ����1ֻ�����ڸ���һֻ�ճ�������ţ����20����ж�����ţ��
*/

#include <memory.h>
#include <stdio.h>


int calcCowCnt(int years)
{
	int cnt = 1;
	for(int i = 4; i <= years; ++i)
	{
		cnt += calcCowCnt(years - i + 1);
	}
	return cnt;
}


//�ǵݹ�ʵ��
#include <stack>

int CowCntIter(int years)
{
	int cnt = 1;

	std::stack<int> yr;
	yr.push(years);//����һ����Ϣ��ջ

	while(yr.empty() == false)
	{
		int y = yr.top();//����һ��������
		yr.pop();
		cnt += y - 3;

		for(int i = 4; i <= y - 3; ++i)//������һ����Ϣ
			yr.push(i);
	}

	return cnt;
}
