/*
**ye.cai
**2015.3.28

一只刚出生的奶牛，4年生1只奶牛，以后每一年生1只。现在给你一只刚出生的奶牛，求20年后有多少奶牛。
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


//非递归实现
#include <stack>

int CowCntIter(int years)
{
	int cnt = 1;

	std::stack<int> yr;
	yr.push(years);//祖先一代信息进栈

	while(yr.empty() == false)
	{
		int y = yr.top();//弹出一代的数据
		yr.pop();
		cnt += y - 3;

		for(int i = 4; i <= y - 3; ++i)//保存下一代信息
			yr.push(i);
	}

	return cnt;
}
