// TasksForCPP_01_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TMyString.h"
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "Rus");
  
    using namespace std;
    //TMyString str;
    TMyString str2("");
    cout << "Проверка конструктора пустой строки: " << str2 << endl;
    cout << "  str2.Length() == " << str2.Length() << endl;
    
    TMyString str3("Hello world!");
    cout << "Проверка конструктора не пустой строки: " << str3 << endl;
    cout << "  str3.Length() == " << str3.Length() << endl;

    //str2.CopyFrom(str3, 0);
    //cout << "  str2.CopyFrom(str3, 0) == " << str2 << endl;

    TMyString str4("Hello world!");
    str4.CopyFrom(str3, 6);
    cout << "  str4.CopyFrom(str3, 6) == " << str4 << endl;

    TMyString str5("Hello world!");
    str5.Insert(str3, 6);
    cout << "  str5.Insert(str3, 6) == " << str5 << endl;

    cout << "Проверка Pos " << endl;
    cout << "str5.Pos(str3) == " << str5.Pos(str3) << endl;

    char* sub;
    sub = str5.SubString(2, 8);
    cout << "str5.SubString(2,8) == " << sub << endl;
    delete[] sub;
//    str2.Insert(str3, 7);
//    cout << "  str2.Insert(str3, 7) == " << str2 << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

