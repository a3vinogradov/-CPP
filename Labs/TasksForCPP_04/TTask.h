#pragma once
#include <string>
#include "..\TasksForCPP_01_6\TMyDate.h"
#include "TEmployee.h"

using namespace std;

class TTask
{
private:
	string _name;
	TMyDate _deadline;
	TMyDate _datecomplition;
	TEmployee* _employee;
public:
	TTask(const char* aName);
	TTask(const char* aName, const TMyDate dtDeadLine, TEmployee* emp);


	string GetName();
	void SetDeadLine(const TMyDate dt);
	void SetDateComplation(const TMyDate dt);
	void SetEmployee(TEmployee* emp);
	TMyDate GetDeadLine() const;
	TMyDate GetComplitionDate() const;
	TEmployee* GetEmployee() const;
	bool IsInTime() const;
};

