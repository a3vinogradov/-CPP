// TasksForCPP_01_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "TMyDate.h"
#include <iostream>
#include <ctime>

using namespace std;
int main()
{
    time_t now = time(0);
    TMyDate d1;
    TMyDate d2(11, 8, 2020);
    TMyDate d3(now);
    cout << "d1() == "; d1.Print(); cout << endl;
    cout << "d2(11,8,2020) == "; d2.Print(); cout << endl;
    cout << "d3(now) == "; d3.Print(); cout << endl;
    TMyDate d4 = d3;
    cout << "d4=d3 == "; d4.Print(); cout << endl;

    time_t temp = d2.ToTime_t();
    cout << "d2.ToTime_t() == " << temp << endl;
    d2.IncMonth(5);
    cout << "d2.IncMonth(5) == "; d2.Print(); cout << endl;
    d2.IncMonth(-13);
    cout << "d2.IncMonth(-13) == "; d2.Print(); cout << endl;
    
    TMyDate d5(1, 1, 2020);
    TMyDate d6(d5);
    cout << "d5 == "; d5.Print(); cout << "; " << endl;
    d5.IncDays(30);
    cout << "d5 == "; d5.Print(); cout << "; " << endl;
    d5.IncDays(30);    
    cout << "d5 == "; d5.Print(); cout << "; " << endl;
    
    cout << "d6 == "; d6.Print(); cout << "; " << endl;
    d6.IncDays(60);
    cout << "d6 == "; d6.Print(); cout << "; " << endl;

    cout << "=====================================" << endl;
    cout << "d5==d6 : " << d5.DiffInDays(d6) << endl;
    cout << "d5 ==  "; d5.Print(); cout << "; d6 == "; d6.Print(); cout << "; diff == " << d5.DiffInDays(d6) << endl;
    d6.IncYears(-1);
    cout << "d5 ==  "; d5.Print(); cout << "; d6 == "; d6.Print(); cout << "; diff == " << d5.DiffInDays(d6) << endl;
    d6.IncYears(2);
    cout << "d5 ==  "; d5.Print(); cout << "; d6 == "; d6.Print(); cout << "; diff == " << d5.DiffInDays(d6) << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < 70; i++)
    {
        d6.IncMonth(-1);
        d6.Print(); cout << endl;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"