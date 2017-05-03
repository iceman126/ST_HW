#include <gtest/gtest.h>
#include "hw1.h"

// Next Date

// Next Date: weak normal
TEST(next_date_WN, next_date_WN_test) {
	EXPECT_EQ("6/15/2000", next_date(6, 14, 2000));
	EXPECT_EQ("7/30/1996", next_date(7, 29, 1996));
	EXPECT_EQ("Invalid input date", next_date(2, 30, 2002));
	EXPECT_EQ("Invalid input date", next_date(6, 31, 2000));
}

// Next Date: strong normal
TEST(next_date_SN, next_date_SN_test) {
	EXPECT_EQ("6/15/2000", next_date(6, 14, 2000));
	EXPECT_EQ("6/15/1996", next_date(6, 14, 1996));
	EXPECT_EQ("6/15/2002", next_date(6, 14, 2002));
	EXPECT_EQ("Invalid input date", next_date(6, 31, 1996));
	EXPECT_EQ("Invalid input date", next_date(6, 31, 2002));
	EXPECT_EQ("Invalid input date", next_date(2, 30, 2002));
	EXPECT_EQ("3/1/2002", next_date(2, 28, 2002));
	EXPECT_EQ("1/1/2003", next_date(12, 31, 2002));
	EXPECT_EQ("3/1/2000", next_date(2, 29, 2000));
	EXPECT_EQ("Invalid input date", next_date(2, 29, 1999));
	EXPECT_EQ("3/1/1999", next_date(2, 28, 1999));
	EXPECT_EQ("3/1/1999", next_date(2, 28, 1999));
	EXPECT_EQ("2/19/2004", next_date(2, 18, 2004));
	EXPECT_EQ("2/19/2003", next_date(2, 18, 2003));
	EXPECT_EQ("8/1/2003", next_date(7, 31, 2003));
	EXPECT_EQ("7/1/2003", next_date(6, 30, 2003));
}


// Next Date: weak robust
TEST(next_date_WR, next_date_WR_test) {
	EXPECT_EQ("Invalid input date", next_date(0, 31, 1996));
	EXPECT_EQ("Invalid input date", next_date(13, 31, 1996));
	EXPECT_EQ("Invalid input date", next_date(6, 32, 2002));
	EXPECT_EQ("Invalid input date", next_date(6, 0, 2002));
	EXPECT_EQ("Invalid input date", next_date(6, 31, -1));
	EXPECT_EQ("Invalid input date", next_date(2, 30, 2004));
	EXPECT_EQ("Invalid input date", next_date(7, 33, 2003));
}

// Next Date: strong robust
TEST(next_date_SR, next_date_SR_test) {
	EXPECT_EQ("Invalid input date", next_date(0, 31, 1996));
	EXPECT_EQ("Invalid input date", next_date(13, 31, 1996));

	EXPECT_EQ("Invalid input date", next_date(0, 32, 1996));
	EXPECT_EQ("Invalid input date", next_date(13, 32, 1996));
	EXPECT_EQ("Invalid input date", next_date(0, 0, 1996));
	EXPECT_EQ("Invalid input date", next_date(13, 0, 1996));

	EXPECT_EQ("Invalid input date", next_date(6, 32, 2002));
	EXPECT_EQ("Invalid input date", next_date(6, 0, 2002));
	
	EXPECT_EQ("Invalid input date", next_date(6, 32, -1));
	EXPECT_EQ("Invalid input date", next_date(6, 0, -1));
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

	// system("pause");

	return 0;
}