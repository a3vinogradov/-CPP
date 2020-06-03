// Ex8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<class T>
T Pow(T val) {
    return val * val;
}

int main()
{
    using namespace std;

    cout << "Pow(4) = " << Pow(4) << endl;
    cout << "Pow(0.5) = " << Pow(0.5) << endl;
    long a = 105L;
    cout << "Pow(10.5) = " << Pow(a) << endl;
  
}

