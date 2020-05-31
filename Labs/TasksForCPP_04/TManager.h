#pragma once
#include "TEmployee.h"
#include "TEmployeeList.h"
#include "TTask.h"

class TManager : public TEmployee
{
protected:
	TEmployeeList _employeelist;
	vector<TTask*> _tasklist;
public:
	TManager();
	TManager(const char* aLastName, const char* aFirstName);

	TEmployeeList* GetEmloyeeList();
	vector<TTask*>* GetTaskList();

	bool IsBonusAvailable(size_t tabNum) const;
};

