#include "..\TasksForCPP_01_6\TMyDate.h"
#include "gtest/gtest.h"

TEST(TestConstructors, TestDefaultConstructor) {
    TMyDate d1;
    EXPECT_EQ(d1.GetDay(), 0);
    EXPECT_EQ(d1.GetMonth(), 0);
    EXPECT_EQ(d1.GetYear(), 0);
}
TEST(TestConstructors, TestInitializeConstructor) {
    TMyDate d1(12,9,1979);
    EXPECT_EQ(d1.GetDay(), 12);
    EXPECT_EQ(d1.GetMonth(), 9);
    EXPECT_EQ(d1.GetYear(), 1979);
}
TEST(TestConstructors, TestCopyConstructor) {
    TMyDate d0(12, 9, 1979);
    TMyDate d1(d0);
    EXPECT_EQ(d1.GetDay(), 12);
    EXPECT_EQ(d1.GetMonth(), 9);
    EXPECT_EQ(d1.GetYear(), 1979);
}

TEST(TestOperators, TestSetOperator) {
    TMyDate d1;
    EXPECT_EQ(d1.GetDay(), 0);
    EXPECT_EQ(d1.GetMonth(), 0);
    EXPECT_EQ(d1.GetYear(), 0);
    TMyDate d0(12, 9, 1979);
    d1 = d0;
    EXPECT_EQ(d1.GetDay(), 12);
    EXPECT_EQ(d1.GetMonth(), 9);
    EXPECT_EQ(d1.GetYear(), 1979);
}
TEST(TestOperators, TestEqualtOperator) {
    TMyDate d1(2,8,2018);
    TMyDate d2(2,8,2018);
    EXPECT_EQ(d1, d2);
}
TEST(TestOperators, TestBoolOperators) {
    TMyDate d1(1, 8, 2018);
    TMyDate d2(2, 8, 2018);
    TMyDate d3(2, 8, 2018);
    TMyDate d4(3, 8, 2018);

    EXPECT_FALSE(d1 == d2);
    EXPECT_TRUE(d1 != d2);
    EXPECT_TRUE(d3 == d2);
    EXPECT_TRUE(d3 <= d2);
    EXPECT_TRUE(d3 >= d2);
    EXPECT_TRUE(d1 < d2);
    EXPECT_TRUE(d4 > d2);

}