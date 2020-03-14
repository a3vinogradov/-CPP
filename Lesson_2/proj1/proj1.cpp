// proj1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Vector.h"

using namespace std;

int main()
{
    Vector v1(4,2), v2(6,3), v3(10, 4);
    cout << v1 << endl << v2 << endl << v3 << endl ;

    cout << "v3 = v1 + v2" << endl;
    v3 = v1 + v2;
    cout << v3 << endl;

    cout << "v3 = v2 + 5" << endl;
    v3 = v2 + 5;
    cout << v3 << endl;

    cout << "v1 == v2" << endl;
    cout << (v1 == v2) << endl;

    cout << "v1 != v2" << endl;
    cout << (v1 != v2) << endl;
    return 0;
}

