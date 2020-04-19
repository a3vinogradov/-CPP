#include "pch.h"
#include "..\TasksForCPP_04\TEmployee.h"


TEST(TestConstructors, TestDefaultConstructor) {
	TEmployee e1("Bob", "Smith");
	EXPECT_EQ(e1.GetFirstName(), "Smith");
	EXPECT_EQ(e1.GetLastName(), "Bob");
	EXPECT_EQ(e1.GetPosition(), cnstPosProgrammer);
	EXPECT_EQ(e1.GetSalary(), 1000);
	EXPECT_EQ(e1.GetTabNumber(), 1);
	TMyDate d1;
	TMyDate d2;
	EXPECT_EQ(e1.GetDateEmployment(), d1);
	EXPECT_EQ(e1.GetDateTermination(), d2);

}
TEST(TestLogic, TestAutoincrementTabNumber){
	TEmployee e1("Bob", "Smith");
	TEmployee e2("John", "Johnson");
	TEmployee e3("Bob", "Martin");
	EXPECT_EQ(e2.GetTabNumber(), e1.GetTabNumber() + 1);
	EXPECT_EQ(e3.GetTabNumber(), e1.GetTabNumber() + 2);
}

TEST(TestLogic, TestSetPosition) {
	TEmployee e1("Bob", "Smith");
	e1.SetPosition(cnstPosExpert);
	EXPECT_EQ(e1.GetPosition(), cnstPosExpert);
	EXPECT_EQ(e1.GetSalary(), 1500);
}
TEST(TestLogic, TestSetSalary) {
	TEmployee e1("Bob", "Smith");
	e1.SetSalary(1234);
	EXPECT_EQ(e1.GetSalary(), 1234);

	TEmployee e2("John", "Johnson");
	e2.SetPosition(cnstPosExpert);
	e2.SetSalary(1567);
	EXPECT_EQ(e2.GetSalary(), 1567);
}
TEST(TestLogic, TestSetNames) {
	TEmployee e1("Bob", "Smith");
	e1.SetFirstName("John");
	e1.SetLastName("Johnson");
	EXPECT_EQ(e1.GetFirstName(), "John");
	EXPECT_EQ(e1.GetLastName(), "Johnson");
}
TEST(TestLogic, TestFaildSetNames) {
	TEmployee e1("Smith", "Bob");
	e1.SetFirstName("");
	e1.SetLastName("");
	EXPECT_EQ(e1.GetFirstName(), "Bob");
	EXPECT_EQ(e1.GetLastName(), "Smith");
}
TEST(TestLogic, TestSetDates) {
	TEmployee e1("Smith","Bob");
	TMyDate dt1(1, 1, 2020);
	TMyDate dt2(1, 3, 2020);
	e1.SetDateEmployment(dt1);
	e1.SetDateTermination(dt2);
	EXPECT_EQ(e1.GetDateEmployment(), dt1);
	EXPECT_EQ(e1.GetDateTermination(), dt2);

}