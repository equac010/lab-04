#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;


//TEST(TriangleTests, testPerimeter) {
//    Triangle *aTriangle = new Triangle(3,3,3);
//    EXPECT_EQ (aTriangle->getPerimeter(),9);
//}

TEST(HailstoneTests, testZero) {
	EXPECT_FALSE(satisfiesHailstone(0));
}

TEST(HailstoneTests, testOne) {
	EXPECT_TRUE(satisfiesHailstone(1));
}

TEST(HailstoneTests, testEven) {
	EXPECT_TRUE(satisfiesHailstone(4));
}

TEST(HailstoneTests, testOdd) {
	EXPECT_TRUE(satisfiesHailstone(3));
}

TEST(HailstoneTests, testNegative) {
	EXPECT_FALSE(satisfiesHailstone(-1));
}
