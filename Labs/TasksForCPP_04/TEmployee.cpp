#include "TEmployee.h"
#include <iostream>
#include <sstream>



enum Positions {};

size_t TEmployee::_tabNumerator = 0;

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
TEmployee::TEmployee()
{
	_lastName = "None";
	_firstName = "None";
	_tabNumber = ++_tabNumerator;
	_salary = 0;
	SetPosition(cnstPosProgrammer);
}
TEmployee::TEmployee(const char* aLastName, const char* aFirstName) : _lastName(aLastName), _firstName(aFirstName)
{
	//_lastName = aLastName;
	//_firstName = aFirstName;
	_tabNumber = ++_tabNumerator;
	_salary = 0;
	SetPosition(cnstPosProgrammer);
}

void TEmployee::SetFirstName(const string Value)
{
	if (Value != "") _firstName = Value;
}

void TEmployee::SetLastName(const string Value)
{
	if (Value != "") _lastName = Value;
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

void TEmployee::SetDateTermination(const TMyDate& Value)
{
	_dateTermination = Value;
}

string TEmployee::ToString() const
{
	std::stringstream ss;
	ss << GetLastName() << " " << GetFirstName() << endl;
	ss << "Tab №: " << GetTabNumber() << endl;
	ss << "Должность: " << GetPosition() << endl;
	ss << "Оклад: " << GetSalary() << endl;

	return ss.str();
}

void TEmployee::SetDateEmployment(const TMyDate& date)
{
	_dateEmployment = date;
}

std::ostream& operator<<(std::ostream& os, const TEmployee& obj)
{
	//os << obj.GetLastName() << " " << obj.GetFirstName() << endl;
	//os << "Tab №: " << obj.GetTabNumber() << endl;
	//os << "Должность: " << obj.GetPosition() << endl;
	//os << "Оклад: " << obj.GetSalary() << endl;
	//os << "Стаж работы: " << obj.
	os << obj.ToString();
	return os;
}
