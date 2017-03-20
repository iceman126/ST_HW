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
TEST(triangle_WN, traingle_WN_test) {
	EXPECT_EQ("Value of a is not in the range of permitted values", triangle(-1, 5, 5));
	EXPECT_EQ("Value of b is not in the range of permitted values", triangle(5, -1, 5));
	EXPECT_EQ("Value of c is not in the range of permitted values", triangle(5, 5, -1));
	EXPECT_EQ("Value of a is not in the range of permitted values", triangle(201, 5, 5));
	EXPECT_EQ("Value of b is not in the range of permitted values", triangle(5, 201, 5));
	EXPECT_EQ("Value of c is not in the range of permitted values", triangle(5, 5, 201));
}

// triangle: strong robust
TEST(triangle_WN, traingle_WN_test) {
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