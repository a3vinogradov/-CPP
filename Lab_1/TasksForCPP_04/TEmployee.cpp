#include "TEmployee.h"


enum Positions {};


void TEmployee::SetDefaultSalary()
{
	if (GetPosition() == cnstPosProgrammer) {
		SetSalary(1000);
	}
	else if (GetPosition() == cnstPosJunior) {
		SetSalary(800);
	}
	else if (GetPosition() == cnstPosExpert) {
		SetSalary(1500);
	}
	else if (GetPosition() == cnstPosTeamLead) {
		SetSalary(2000);
	}
	else {
		throw exception("Неизвестная должность!");
	}
}
//size_t TEmployee::_tabNumerator = 0;
TEmployee::TEmployee(const char* aLastName, const char* aFirstName)
{
	_lastName = aLastName;
	_firstName = aFirstName;
	_tabNumber = ++_tabNumerator;
	_salary = 0;
	SetPosition(cnstPosProgrammer);
}

void TEmployee::SetPosition(const string aPos)
{
	_position = aPos;
	SetDefaultSalary();
}

void TEmployee::SetSalary(const double aVal)
{
	_salary = aVal;
}

TMyDate TEmployee::GetDateEmployment() const
{
	return _dateEmployment;
}

TMyDate TEmployee::GetDateTermination() const
{
	return _dateTermination;
}

void TEmployee::SetDateEmployment(TMyDate date)
{
	_dateEmployment = date;
}

std::ostream& operator<<(std::ostream& os, const TEmployee& obj)
{
	os << obj.GetLastName() << " " << obj.GetFirstName() << endl;
	os << "Tab №: " << obj.GetTabNumber() << endl;
	os << "Должность: " << obj.GetPosition() << endl;
	os << "Оклад: " << obj.GetSalary() << endl;
	os << "Стаж работы: " << obj.
	return os;
}
