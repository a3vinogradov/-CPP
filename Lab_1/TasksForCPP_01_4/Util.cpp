#include "Util.h"
#include <iostream>

int& f1() {
	static int k;
	k *= k;
	return k;
};
void f2()
{
	using namespace std;
	int val;
	cout << "Input value: ";
	cin >> val;
	f1() = val;
};