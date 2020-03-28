#pragma once
#include <string>
#include "..\TasksForCPP_01_6\TMyDate.h"

namespace CPP_Lab {
	using namespace std;
	class TEmployee
	{
		//_фамилия, имя, должность, зарплата, дата приема на работу, дата увольнения, табельный номер.
		string _lastName;
		string _firstName;
		double _salary;
		TMyDate _dateEmployment = {0,0,0};
		TMyDate _dateTermination = {0,0,0};
		static size_t _tabNumber;
	public:
		__declspec(property(get = GetTabNumber)) size_t TabNumber;
		__declspec(property(get (){ return _firstName; })) string FirstName;
		__declspec(property(get = (){ return _lastName; })) string LastName;

		TEmployee(const char* aLastName, const char* aFirstName);

		size_t GetTabNumber() { return _tabNumber; }

		//TEmployee operator<< ()
	};
	std::ostream& operator <<(std::ostream& os, const TEmployee& obj);

}

