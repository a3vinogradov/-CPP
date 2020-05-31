#include "TSupervisor.h"

TSupervisor::TSupervisor()
{
	_lastName = "None";
	_firstName = "None";
	_salary = 0;
	SetPosition(cnstPosProgrammer);
}

TSupervisor::TSupervisor(const char* aLastName, const char* aFirstName)
{
	_lastName = aLastName;
	_firstName = aFirstName;
	_salary = 0;
	SetPosition(cnstPosProgrammer);
}