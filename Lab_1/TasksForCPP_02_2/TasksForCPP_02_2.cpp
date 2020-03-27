// TasksForCPP_02_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Polinom.h"

int main()
{
    // 1. Создание и вывод полинома
 /*   Polinom pol1;
    cout << "pol1 == " << pol1 << endl;*/

    // 2. Задание коэффициентов полинома индекс коэффициента равен степени неизвестного.
    Polinom pol2;
    pol2.SetKoef(0, -15);
    cout << "pol2.SetKoef(0, -15) pol2 == " << pol2 << endl;
    pol2.SetKoef(4, 2);
    cout << "pol2.SetKoef(4, 2) pol2 == " << pol2 << endl;
    pol2.SetKoef(8, 123.3);
    cout << "pol2.SetKoef(8, 123.3) pol2 == " << pol2 << endl;
    pol2.SetKoef(7, -23);
    cout << "pol2.SetKoef(7, -23) pol2 == " << pol2 << endl;
    pol2.SetKoef(8, 0);
    cout << "pol2.SetKoef(8, 0) pol2 == " << pol2 << endl;
    pol2.SetKoef(0, 300);
    cout << "pol2.SetKoef(0, 300) pol2 == " << pol2 << endl;

    // 3. Сложение полиномов
    Polinom pol3;
    pol3.SetKoef(3, -5);
    pol3.SetKoef(4, 2);
    pol3.SetKoef(5, -11);
    // pol3 = -11x^5 + 2x^4 - 5x^3
    Polinom pol4;
    pol4.SetKoef(5, 5);
    pol4.SetKoef(0, -3);
    // pol4 = 5x^5 - 3
    Polinom pol5;
    pol5 = pol3 + pol4;
    // pol5 = -6x^5 + 2x^4 - 5x^3 + 3
    cout << "           " << pol3 << endl;
    cout << "         + " << pol4 << endl;
    cout << "         = " << pol5 << endl;
    cout << " expected: -6x^5 + 2x^4 - 5x^3 + 3"<< endl;
    
    // 4. Умножение на скаляр
    cout << "============ * (-2) =========================" << endl;
    Polinom pol6;
    pol6.SetKoef(3, -5);
    pol6.SetKoef(4, 2);
    pol6.SetKoef(5, -11);
    Polinom pol7;
    pol7 = pol6 * -2;

    cout << "           " << pol6 << endl;
    cout << "     * (-2)" << endl;
    cout << "         = " << pol7 << endl;
    cout << " expected: 22x^5 - 4x^4 + 10x^3" << endl;
    cout << "============ * 0x - 2 =========================" << endl;

    // 4.1 Умножение на скаляр в форме полинома
    Polinom pol8;
    pol8.SetKoef(0, -2);
    Polinom pol9;
    pol9 = pol6 * pol8;
    cout << "           " << pol6 << endl;
    cout << "         * " << pol8 << endl;
    cout << "         = " << pol9 << endl;
    cout << " expected: 22x^5 - 4x^4 + 10x^3" << endl;

    cout << "============ * x =========================" << endl;
    // 4.2 Умножение на x
    Polinom pol10;
    pol10.SetKoef(1, 1);
    Polinom pol11;
    pol11 = pol6 * pol10;
    cout << "           " << pol6 << endl;
    cout << "         * " << pol10 << endl;
    cout << "         = " << pol11 << endl;
    cout << " expected: -11x^6 + 2x^5 - 5x^4" << endl;

    cout << "============ * (x - 2) =========================" << endl;
    // 5 Умножение полиномов
    Polinom pol12;
    // pol12 = pol8 + pol10;
    pol12.SetKoef(0, -2);
    pol12.SetKoef(1, 1);
    Polinom pol13;
    pol13 = pol6 * pol12;
    cout << "           " << pol6 << endl;
    cout << "         * " << pol12 << endl;
    cout << "         = " << pol13 << endl;
    cout << " expected: -11x^6 + 24x^5 - 9x^4 + 10x^3" << endl;


    //cout << "============ Умножение полиномов ===============" << endl;
    //cout << "pol1 == " << pol1 << endl;
    //cout << "pol2 == " << pol2 << endl;
    //cout << " pol1*pol2 == " << pol1.Multiply(pol2) << endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

