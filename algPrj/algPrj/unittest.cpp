
#include "gtest/gtest.h"
#include "mstack.cpp"

TEST(STACKTEST, pushOpt)
{
	sStack<int> st;
	st.push(2);
	EXPECT_EQ(2, st.getMin());
	st.push(-1);
	EXPECT_EQ(-1, st.getMin());
	EXPECT_EQ(2, st.getMax());
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();

	return 0;
}