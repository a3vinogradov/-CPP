#include "TTask.h"
#include "TTask.h"

TTask::TTask(const char* aName) {
	_name = aName;
}

TTask::TTask(const char* aName, const TMyDate dtDeadLine, TEmployee* emp)
{
	_name = aName;
	SetDeadLine(dtDeadLine);
	SetEmployee(emp);
}

string TTask::GetName()
{
	return _name;
}

void TTask::SetDeadLine(const TMyDate dt)
{
	_deadline = dt;
}

void TTask::SetDateComplation(const TMyDate dt)
{
	_datecomplition = dt;
}

void TTask::SetEmployee(TEmployee* emp)
{
	_employee = emp;
}

TMyDate TTask::GetDeadLine() const
{
	return _deadline;
}

TMyDate TTask::GetComplitionDate() const
{
	return _datecomplition;
}

TEmployee* TTask::GetEmployee() const
{
	return _employee;
}
xss
bool TTask::IsInTime() const
{
	return GetDeadLine() >= GetComplitionDate() ;
}
