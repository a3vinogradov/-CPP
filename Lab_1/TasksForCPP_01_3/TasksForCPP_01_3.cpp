// TascForCPP_01_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "vector.h"
#include "time.h"

int main()
{
    Vector v1(10,0);
    v1.PushBack(1);
    std::cout << "init value: " << v1.GetElem(10) << std::endl;
    v1.GetElem(10)=2;
    std::cout << "new value: " << v1.GetElem(10) << std::endl;

    v1.Init();
    std::cout << "Init vector: " << std::endl;
    for (int i = 0; i < v1.Size(); i++)
    {
        std::cout << v1.GetElem(i) << " ";
    }
    std::cout << std::endl << "End\n";

}
//todo: добавить уникальность.
