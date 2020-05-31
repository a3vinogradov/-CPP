#include "pch.h"
#include "TSupervisor.h"
#include "TMyDate.h"


TEST(TestTSupervisor, TestConstructors) {
	TSupervisor sv("Johnson", "Pol");
	EXPECT_EQ(sv.GetFirstName(), "Pol");
	EXPECT_EQ(sv.GetLastName(), "Johnson");
	EXPECT_EQ(sv.GetPosition(), cnstPosProgrammer);
	EXPECT_EQ(sv.GetSalary(), 1000);
	EXPECT_EQ(sv.GetTabNumber(), 1);
	TMyDate d1;
	TMyDate d2;
	EXPECT_EQ(sv.GetDateEmployment(), d1);
	EXPECT_EQ(sv.GetDateTermination(), d2);

	EXPECT_EQ(0, sv.GetEmloyeeList()->Count());
	EXPECT_EQ(0, sv.GetTaskList()->size());
}
TEST(TestTSupervisor, TestIsBonusAvailable)
{
	TMyDate d1(1, 1, 2019);
	TMyDate d2(2, 1, 2019);

	TEmployee e1("LastName1", "FirstName1");
	TEmployee e2("LastName2", "FirstName2");
	TEmployee e3("LastName3", "FirstName3");
	TEmployee e4("LastName4", "FirstName4");
	TManager mng1("LastName5", "FirstName5");
	mng1.GetEmloyeeList()->Insert(e1);
	mng1.GetEmloyeeList()->Insert(e2);
	mng1.GetEmloyeeList()->Insert(e3);

	TManager mng2("LastName6", "FirstName6");
	mng2.GetEmloyeeList()->Insert(e4);

	TSupervisor sv1("LastName7", "FirstName7");
	sv1.GetEmloyeeList()->Insert(mng1);
	sv1.GetEmloyeeList()->Insert(mng2);

	TTask task1("Job-001");
	task1.SetDeadLine(d1);
	task1.SetEmployee(&e1);
	task1.SetDateComplation(d2);

	TManager mng("Johnson", "Pol");
	mng.GetEmloyeeList()->Insert(e1);
	mng.GetTaskList()->push_back(&task1);

	EXPECT_FALSE(mng.IsBonusAvailable(e1.GetTabNumber()));
	task1.SetDateComplation(d1);
	EXPECT_TRUE(mng.IsBonusAvailable(e1.GetTabNumber()));
}

