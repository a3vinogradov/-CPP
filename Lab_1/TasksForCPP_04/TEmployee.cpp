#include "TEmployee.h"

CPP_Lab::TEmployee::TEmployee(const char* aLastName, const char* aFirstName)
{
	_lastName = aLastName;
	_firstName = aFirstName;
	_tabNumber++;
}

std::ostream& CPP_Lab::operator<<(std::ostream& os, const TEmployee& obj)
{
	os << obj.LastName << " " << obj.FirstName << endl;
}
