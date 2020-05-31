// TasksForCPP_04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <locale.h>
#include "TEmployee.h"
//#include "Counter.h"

using namespace std;
//size_t TEmployee::_tabNumerator = 0;
int main()
{
    setlocale(LC_ALL, "Rus");
    
    TEmployee e1("Bob", "Smith");
    cout << e1 << endl;
    TEmployee e2("Иван", "Иванов");
    e2.SetPosition(cnstPosJunior);
    cout << e2 << endl;
    TEmployee e3("Владимир", "Смирнов");
    e3.SetPosition(cnstPosExpert);
    cout << e3 << endl;

}


