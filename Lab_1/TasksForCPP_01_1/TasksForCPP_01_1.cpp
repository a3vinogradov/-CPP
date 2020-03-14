// TasksForCPP_01_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

void GetDate(int& dd, int& mm, int& yyyy) {
    time_t ptr = time(0);
    tm* ptm = localtime(&ptr);
    dd = ptm->tm_mday;
    mm = ptm->tm_mon+1;
    yyyy = ptm->tm_year+1900;
    return;
}
int main()
{
    int dd, mm, yyyy;
    GetDate(dd, mm, yyyy);
    std::cout << dd << " "
        << mm << " "
        << yyyy << std::endl;
    return 0;
}


