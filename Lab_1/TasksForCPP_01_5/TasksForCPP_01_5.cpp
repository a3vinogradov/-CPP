// TasksForCPP_01_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TMyString.h"

int main()
{
    //TMyString str;
    TMyString str2("Hello");
    std::cout << str2 << std::endl;
    TMyString str3("str11111111111111");
    std::cout << str3 << std::endl;
    str3.CopyFrom(str2, 2);
    std::cout << str3 << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

