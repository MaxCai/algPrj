
#include "gtest/gtest.h"
#include "mstack.cpp"
#include "binaryTree.cpp"

extern int calcCowCnt(int years);
extern int CowCntIter(int years);

TEST(STACKTEST, pushOpt)
{
	sStack<int> st;
	st.push(2);
	EXPECT_EQ(2, st.getMin());
	st.push(-1);
	EXPECT_EQ(-1, st.getMin());
	EXPECT_EQ(2, st.getMax());
}

TEST(BINTREE, OUTPUT)
{
	int a[5] = {4,2,1,3,5};
	int b[5] = {1,2,3,4,5};
	bintree<int> bt(a, 5);
	vector<int> lst;
	bt.output(lst);

	for(int i= 0; i < 5; ++i)
	{
		EXPECT_EQ(lst[i], b[i]);
	}
}

TEST(COWCNT, OUTPUT)
{
	EXPECT_EQ(CowCntIter(20), calcCowCnt(20));
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();

	return 0;
}