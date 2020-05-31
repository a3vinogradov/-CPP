#include "pch.h"
#include "..\TasksForCPP_04\TEmployee.h"
#include "..\TasksForCPP_04\TEmployeeList.h"
#include "..\TasksForCPP_04\TTask.h"
#include "..\TasksForCPP_04\TManager.h"

TEST(TestTManager, TestConstructors) {
	TManager mng("Johnson", "Pol");
	EXPECT_EQ(mng.GetFirstName(), "Pol");
	EXPECT_EQ(mng.GetLastName(), "Johnson");
	EXPECT_EQ(mng.GetPosition(), cnstPosProgrammer);
	EXPECT_EQ(mng.GetSalary(), 1000);
	EXPECT_EQ(mng.GetTabNumber(), 1);
	TMyDate d1;
	TMyDate d2;
	EXPECT_EQ(mng.GetDateEmployment(), d1);
	EXPECT_EQ(mng.GetDateTermination(), d2);

	EXPECT_EQ(0, mng.GetEmloyeeList()->Count());
	EXPECT_EQ(0, mng.GetTaskList()->size());
}
TEST(TestTManager, TestTabIncrement) {
	TEmployee e1("Bob", "Smith");
	TManager mng("Johnson", "Pol");
	TEmployee e2("Bob2", "Smith2");
	EXPECT_EQ(e1.GetTabNumber()+1, mng.GetTabNumber());
	EXPECT_EQ(e1.GetTabNumber()+2, e2.GetTabNumber());
}
TEST(TestTManager, TestIsBonusAvailableOneTask) 
{
	TMyDate d1(1, 1, 2019);
	TMyDate d2(2, 1, 2019);

	TEmployee e1("Masck", "Bob");
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
TEST(TestTManager, TestIsBonusAvailableManyTask)
{
	TMyDate d1(1, 1, 2019);
	TMyDate d2(2, 1, 2019);
	TMyDate d3(2, 2, 2019);

	TEmployee e1("Masck", "Bob");
	
	TTask task1("Job-001");
	task1.SetDeadLine(d2);
	task1.SetEmployee(&e1);
	task1.SetDateComplation(d1);

	TTask task2("Job-002");
	task2.SetDeadLine(d2);
	task2.SetEmployee(&e1);
	task2.SetDateComplation(d2);

	TTask task3("Job-003");
	task3.SetDeadLine(d2);
	task3.SetEmployee(&e1);
	task3.SetDateComplation(d3);
	
	TManager mng("Johnson", "Pol");
	mng.GetEmloyeeList()->Insert(e1);
	mng.GetTaskList()->push_back(&task1);
	mng.GetTaskList()->push_back(&task2);
	EXPECT_TRUE(mng.IsBonusAvailable(e1.GetTabNumber()));
	mng.GetTaskList()->push_back(&task3);
	EXPECT_FALSE(mng.IsBonusAvailable(e1.GetTabNumber()));
}


TEST(TestEmlployeeList, TestConstructors) {
	TEmployeeList lst;
	int expect = lst.Count();
	EXPECT_EQ(lst.Count(), 0);
}
TEST(TestEmlployeeList, TestInsert) {
	TEmployee e1("Smith", "Bob"); 
	TEmployeeList lst;
	lst.Insert(e1);
	int expect = lst.Count();
	EXPECT_EQ(1, lst.Count());
	TEmployee* pe1 = lst.At(0);
	EXPECT_EQ("Smith", pe1->GetLastName());
}
TEST(TestTask, TestConstructors) {
	TTask task1("Task name 1");
	EXPECT_EQ(task1.GetName(), "Task name 1");

	TMyDate dt(1, 1, 2019);
	TEmployee emp("Smith", "Bob");
	TTask task2("Task name 2", dt, &emp);
	EXPECT_EQ(task1.GetName(), "Task name 2");
	EXPECT_EQ(task1.GetDeadLine(), dt);
	EXPECT_EQ(task1.GetEmployee()->GetLastName(), "Smith");
	TMyDate dt2();
	EXPECT_EQ(task1.GetComplitionDate(), dt2);

}
TEST(TestTask, TestSetters) {
	TTask task1("Task name 1");
	TMyDate dt1(1, 1, 2019);
	task1.SetDeadLine(dt1);
	TMyDate dt2(2, 1, 2019);
	TEmployee emp1("Smith", "Bob");
	task1.SetEmployee(&emp1);
	task1.SetDateComplation(dt2);
	EXPECT_EQ(task1.GetName(), "Task name 1");
	EXPECT_EQ(task1.GetDeadLine(), dt1);
	EXPECT_EQ(task1.GetComplitionDate(), dt2);
	EXPECT_EQ(task1.GetEmployee()->GetLastName(), "Smith");
}
TEST(TestTask, TestIsInTime) {
	TMyDate dt1(1, 1, 2019);
	TMyDate dt2(2, 1, 2019);
	TMyDate dt3(3, 1, 2019);

	TEmployee emp("Smith", "Bob");
	TTask task1("Task name 1");
	task1.SetDeadLine(dt1);
	task1.SetEmployee(&emp);
	task1.SetDateComplation(dt2);
	EXPECT_FALSE(task1.IsInTime());
	TTask task2("Task name 2");
	task1.SetDeadLine(dt3);
	task1.SetEmployee(&emp);
	task1.SetDateComplation(dt2);
	EXPECT_TRUE(task1.IsInTime());
	TTask task3("Task name 3");
	task1.SetDeadLine(dt2);
	task1.SetEmployee(&emp);
	task1.SetDateComplation(dt2);
	EXPECT_TRUE(task1.IsInTime());
}