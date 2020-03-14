// TascsForCPP_01_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

/*
int* GetArray(int N, int& len)
{

    if (N >= 2) {
        len = N - 1;
        int* Arr = new int[len];
        for (int i = 0; i < len; i++)
        {
            Arr[i] = i + 2;
        }
        return Arr;
    }
    else if (N < 2) { // -3, -2, -1, 0, 1, 2
        len = 2-N+1;
        int* Arr = new int[len];
        for (int i = 0; i < len; i++)
        {
            Arr[i] = i + N;
        }
        return Arr;
    }
}
*/
bool IsSimple(int val) 
{
    bool res = true;
    for (int i=2; i<=(val/2); i++)
    {
        if (val % i == 0) 
        {
            res = false;
            break;
        } 
    }
    return res;
}
int* GetSimpleArr(int N, int& len)
{
    std::vector<int> v;
    for (int i = 2; i <= N; i++)
    {
        if (IsSimple(i)) {
            v.push_back(i);
        }
    }
    len = v.size();
    int* Arr = new int[len];
    for (int i = 0; i < len; i++) {
        Arr[i] = v.at(i);
    }
    return Arr;
}
int main()
{
    int* Arr;
    int len = 0;
    /*
    Arr = GetArray(6, len);
    for (int i = 0; i < len; i++)
    {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl << "End\n";

    Arr = GetArray(-8, len);
    for (int i = 0; i < len; i++)
    {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl << "End\n";
    */
    Arr = GetSimpleArr(30, len);
    for (int i = 0; i < len; i++)
    {
        std::cout << Arr[i] << " ";
    }
    std::cout << std::endl << "End\n";
}


