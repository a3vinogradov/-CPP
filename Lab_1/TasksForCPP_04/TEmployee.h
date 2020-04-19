#pragma once
#include <string>
#include "..\TasksForCPP_01_6\TMyDate.h"


using namespace std; 
const string cnstPosJunior = "Младший программист";
const string cnstPosProgrammer = "Программист";
const string cnstPosExpert = "Старший программист";
const string cnstPosTeamLead = "Тимлид";

class TEmployee
{
	//_фамилия, имя, должность, зарплата, дата приема на работу, дата увольнения, табельный номер.
	string _lastName;
	string _firstName;
	string _position;
	double _salary;
	TMyDate _dateEmployment ;
	TMyDate _dateTermination;
	static size_t _tabNumerator;
	size_t _tabNumber;

	void SetDefaultSalary();
public:
	TEmployee(const char* aLastName, const char* aFirstName);

	size_t GetTabNumber() const { return _tabNumber; }
	string GetFirstName() const { return _firstName; }
	void SetFirstName(const string Value);
	string GetLastName() const { return _lastName; }
	void SetLastName(const string Value);
	string GetPosition() const { return _position; }
	void SetPosition(const string aPos);
	double GetSalary() const { return _salary; }
	void SetSalary(const double aVal);
	TMyDate GetDateEmployment() const;
	void SetDateEmployment(const TMyDate& date);
	TMyDate GetDateTermination() const;
	void SetDateTermination(const TMyDate& Value);

	string ToString() const;

};
std::ostream& operator <<(std::ostream& os, const TEmployee& obj);



