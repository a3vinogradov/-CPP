// Ex10.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Задача 10
// Написать шаблон функции поиска суммы всех элементов, лежащих на главной диагонали квадратной матрицы.
// Написать пример использования этой функции для любого встроенного типа данных.
//

#include <iostream>
const int DIM = 6;

template<class T>
T SumDiag(T arr[DIM][DIM]) {
    T res = 0;
    for (int i = 0; i < DIM; i++) {
        res += arr[i][i];
    }
    return res;
}

int main()
{
    using namespace std;

    int arr[DIM][DIM]; 
    int val = 0;
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            arr[i][j] = ++val;
        }
    }
    cout << "arr = [" ;
    for (int j = 0; j < DIM; j++) {
        cout << "[";
        for (int i = 0; i < DIM; i++) {
            cout << arr[i][j] << "  ";
        }
        cout << "]"<< endl << "       ";
    }
    cout << "]" << endl;

    cout << endl << endl;
    cout << "summ = " << SumDiag(arr) << endl;



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
