#pragma once
#include <vector>
#include "TEmployee.h"
using namespace std;

class TEmployeeList
{
private:
	vector<TEmployee*> _list;
public:
	size_t Count();
	void Insert(TEmployee& emp);
	TEmployee* At(const size_t index) const;
};

