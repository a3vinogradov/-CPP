#pragma once
#include <string>
#include "..\TasksForCPP_01_6\TMyDate.h"


using namespace std; 
const string cnstPosJunior = "������� �����������";
const string cnstPosProgrammer = "�����������";
const string cnstPosExpert = "������� �����������";
const string cnstPosTeamLead = "������";

class TEmployee
{
	//_�������, ���, ���������, ��������, ���� ������ �� ������, ���� ����������, ��������� �����.
	string _lastName;
	string _firstName;
	string _position;
	double _salary;
	TMyDate _dateEmployment = { 0,0,0 };
	TMyDate _dateTermination = { 0,0,0 };
	static size_t _tabNumerator;
	size_t _tabNumber;

	void SetDefaultSalary();
public:
	TEmployee(const char* aLastName, const char* aFirstName);

	size_t GetTabNumber() const { return _tabNumber; }
	string GetFirstName() const { return _firstName; }
	string GetLastName() const { return _lastName; }
	string GetPosition() const { return _position; }
	void SetPosition(const string aPos);
	double GetSalary() const { return _salary; }
	void SetSalary(const double aVal);
	TMyDate GetDateEmployment() const;
	TMyDate GetDateTermination() const;
	void SetDateEmployment(TMyDate date);
	void SetDateTermination(TMyDate& date);

};
std::ostream& operator <<(std::ostream& os, const TEmployee& obj);



