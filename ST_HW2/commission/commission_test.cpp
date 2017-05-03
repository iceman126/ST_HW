#include <gtest/gtest.h>
#include "hw1.h"

/*
Commission Problem
Locks: $45
Stocks:$30
Barrels: $25
10% on the first $1000 of total sales
15% on sales from $1001 to $1800
20% on sales over $1800
*/

// commission: strong normal
TEST(commission_SN, commission_SN_test) {
	EXPECT_EQ("$10.00", commission(1, 1, 1));
	EXPECT_EQ("$80.00", commission(8, 8, 8));
	EXPECT_EQ("$115.00", commission(11, 11, 11));
	EXPECT_EQ("$220.00", commission(18, 18, 18));
}

// commission: weak robust
TEST(commission_WR, commission_WR_test) {
	EXPECT_EQ("$100.00", commission(10, 10, 10));
	EXPECT_EQ("$860.00", commission(50, 50, 50));
	EXPECT_EQ("", commission(-1, 40, 45));
	EXPECT_EQ("locks should be in range of 1~70", commission(-2, 40, 45));
	EXPECT_EQ("locks should be in range of 1~70", commission(71, 40, 45));
	EXPECT_EQ("stocks should be in range of 1~80", commission(35, -1, 45));
	EXPECT_EQ("stocks should be in range of 1~80", commission(35, 81, 45));
	EXPECT_EQ("barrels should be in range of 1~90", commission(35, 40, -1));
	EXPECT_EQ("barrels should be in range of 1~90", commission(35, 40, 91));
}

// commission: strong robust
TEST(commission_SR, commission_SR_test) {

	EXPECT_EQ("locks should be in range of 1~70", commission(-2, 40, 45));
	EXPECT_EQ("locks should be in range of 1~70", commission(71, 40, 45));

	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80", commission(-2, -1, 45));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80", commission(71, -1, 45));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80", commission(-2, 81, 45));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80", commission(71, 81, 45));

	EXPECT_EQ("stocks should be in range of 1~80", commission(35, -1, 45));
	EXPECT_EQ("stocks should be in range of 1~80", commission(35, 81, 45));

	EXPECT_EQ("stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(35, -1, -1));
	EXPECT_EQ("stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(35, 81, -1));
	EXPECT_EQ("stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(35, -1, 91));
	EXPECT_EQ("stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(35, 81, 91));

	EXPECT_EQ("barrels should be in range of 1~90", commission(35, 40, -1));
	EXPECT_EQ("barrels should be in range of 1~90", commission(35, 40, 91));

	EXPECT_EQ("locks should be in range of 1~70 & barrels should be in range of 1~90", commission(-2, 40, -1));
	EXPECT_EQ("locks should be in range of 1~70 & barrels should be in range of 1~90", commission(-2, 40, 91));
	EXPECT_EQ("locks should be in range of 1~70 & barrels should be in range of 1~90", commission(71, 40, -1));
	EXPECT_EQ("locks should be in range of 1~70 & barrels should be in range of 1~90", commission(71, 40, 91));

	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(-2, 81, 91));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(71, -1, 91));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(71, 81, -1));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(-2, -1, 91));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(71, -1, -1));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(-2, 81, -1));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(-2, -1, -1));
	EXPECT_EQ("locks should be in range of 1~70 & stocks should be in range of 1~80 & barrels should be in range of 1~90", commission(71, 81, 91));
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	// system("pause");

	return 0;
}