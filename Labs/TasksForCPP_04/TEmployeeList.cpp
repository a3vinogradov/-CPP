#include "TEmployeeList.h"

size_t TEmployeeList::Count()
{
	return _list.size();
}

void TEmployeeList::Insert(TEmployee& emp)
{
	_list.push_back(&emp);
}

TEmployee* TEmployeeList::At(const size_t index) const
{
	return _list.at(index);
}
