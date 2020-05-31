#pragma once
#include "TManager.h"
class TSupervisor :	public TManager
{
public:
	TSupervisor();
	TSupervisor(const char* aLastName, const char* aFirstName);
};

