// Ex9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int capacity = 10;

template< class T>
int Pos(T elem, T* arr, int size) {
    int result = -1;
    for (int i = 0; i < size; i++) {
        if (elem == *arr) {
            result = i;
            break;
        }
        arr++;
    }
    return result;
}

int main()
{
    using namespace std;

    int A[capacity];
    for (int i = 0; i < capacity; i++) { A[i] = i; }

    int pos5 = Pos(5, A, 10);

    cout << "Array = {";
    for (int i = 0; i < capacity; i++) { cout << A[i]<<" "; }
    cout << "}" << endl;
    cout << "pos(5) = " << pos5 << endl;
    cout << "pos(7) = " << Pos(7, A, capacity) << endl;

    double B[capacity];
    for (int i = 0; i < capacity; i++) { B[i] = i * 0.7; }
    cout << endl << endl << "Array = {";
    for (int i = 0; i < capacity; i++) { cout <<B[i] << " "; }
    cout << "}" << endl;
    cout << "pos(0) = " << Pos(0.0, B, capacity) << endl;
    cout << "pos(" << B[5] << ") = " << Pos(B[5], B, capacity) << endl;
    cout << "pos(" << B[9] << ") = " << Pos(B[9], B, capacity) << endl;
    cout << "pos(15) = " << Pos(15.0, B, capacity) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
