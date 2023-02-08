#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;


TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

//Tests that should fail
TEST(TriangleTests, testArea1) {
	Triangle *aTriangle = new Triangle(5,4,3);
	EXPECT_EQ (aTriangle->getArea(),5);
}

TEST(TriangleTests, testPerimeter1) {
	Triangle *aTriangle = new Triangle(6,5,4);
	EXPECT_EQ (aTriangle->getPerimeter(),15);
}

TEST(TriangleTests, testArea2) {
	Triangle *aTriangle = new Triangle(50,40,30);
	EXPECT_EQ (aTriangle->getArea(),60);
}

//Tests that should pass
TEST(TriangleTests, testPerimeter3) {
	Triangle *aTriangle = new Triangle(3,3,3);
	EXPECT_EQ(aTriangle->getPerimeter(), 9);
}
TEST(TriangleTests, testPerimeter4) {
	Triangle *aTriangle = new Triangle(4,4,4);
	EXPECT_EQ(aTriangle->getPerimeter(), 12);
}
TEST(TriangleTests, testPerimeter5) {
	Triangle *aTriangle = new Triangle(7,7,7);
	EXPECT_EQ(aTriangle->getPerimeter(), 21);
}
TEST(TriangleTests, testPerimeter6) {
	Triangle *aTriangle = new Triangle(5,5,5);
	EXPECT_EQ(aTriangle->getPerimeter(), 15);
}

//Expect Death
TEST(TriangleTests, testDeath) {
	Triangle *aTriangle = new Triangle(1,1,-1);
	EXPECT_DEATH(aTriangle->getArea(), "Null Area");
}
