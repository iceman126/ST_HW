#include "gtest/gtest.h"
#include "hw1.h"


// triangle: weak normal & strong normal
TEST(triangle_WN, traingle_WN_test) {
	EXPECT_EQ("Equilateral", triangle(5, 5, 5));
	EXPECT_EQ("Isosceles", triangle(2, 2, 3));
	EXPECT_EQ("Scalene", triangle(3, 4, 5));
	EXPECT_EQ("Not a triangle", triangle(4, 1, 2));
}

// triangle: weak robust
TEST(triangle_WR, traingle_WR_test) {
	EXPECT_EQ("Value of a is not in the range of permitted values", triangle(-1, 5, 5));
	EXPECT_EQ("Value of b is not in the range of permitted values", triangle(5, -1, 5));
	EXPECT_EQ("Value of c is not in the range of permitted values", triangle(5, 5, -1));
	EXPECT_EQ("Value of a is not in the range of permitted values", triangle(201, 5, 5));
	EXPECT_EQ("Value of b is not in the range of permitted values", triangle(5, 201, 5));
	EXPECT_EQ("Value of c is not in the range of permitted values", triangle(5, 5, 201));
}

// triangle: strong robust
TEST(triangle_SR, traingle_SR_test) {
	EXPECT_EQ("Value of a is not in the range of permitted values", triangle(-1, 5, 5));
	EXPECT_EQ("Value of b is not in the range of permitted values", triangle(5, -1, 5));
	EXPECT_EQ("Value of c is not in the range of permitted values", triangle(5, 5, -1));

	EXPECT_EQ("Value of a,b is not in the range of permitted values", triangle(-1, -1, 5));
	EXPECT_EQ("Value of b,c is not in the range of permitted values", triangle(5, -1, -1));
	EXPECT_EQ("Value of a,c is not in the range of permitted values", triangle(-1, 5, -1));

	EXPECT_EQ("Value of a is not in the range of permitted values", triangle(201, 5, 5));
	EXPECT_EQ("Value of b is not in the range of permitted values", triangle(5, 201, 5));
	EXPECT_EQ("Value of c is not in the range of permitted values", triangle(5, 5, 201));

	EXPECT_EQ("Value of a,b is not in the range of permitted values", triangle(201, 201, 5));
	EXPECT_EQ("Value of b,c is not in the range of permitted values", triangle(5, 201, 201));
	EXPECT_EQ("Value of a,c is not in the range of permitted values", triangle(201, 5, 201));

	EXPECT_EQ("Value of a,b,c is not in the range of permitted values", triangle(-1, -1, -1));
	EXPECT_EQ("Value of a,b,c is not in the range of permitted values", triangle(201, 201, 201));
}


//====================================================================

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

	system("pause");

	return 0;
}