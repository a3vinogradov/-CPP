#include "TManager.h"

TManager::TManager()
{
	_lastName = "None";
	_firstName = "None";
	_salary = 0;
	SetPosition(cnstPosProgrammer);
}

TManager::TManager(const char* aLastName, const char* aFirstName)
{
	_lastName = aLastName;
	_firstName = aFirstName;
	_salary = 0;
	SetPosition(cnstPosProgrammer);
}

TEmployeeList*  TManager::GetEmloyeeList() 
{
	return &_employeelist;
}

vector<TTask*>* TManager::GetTaskList()
{
	return &_tasklist;
}

bool TManager::IsBonusAvailable(size_t tabNum) const
{
	for (int i = 0; i < _tasklist.size(); i++)
	{
		if (_tasklist.at(i)->GetEmployee()->GetTabNumber() == tabNum)
		{
			if (!_tasklist.at(i)->IsInTime())
			{
				return false;
			}
		}
	}
	return true;
}
