// TasksForCPP_02_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "big_integer.h"

using namespace std;
int main()
{
	big_integer bi("10");
	cout << bi << endl;
	bi = bi + 500;
	cout << "bi+500 == " << bi << endl;
}

