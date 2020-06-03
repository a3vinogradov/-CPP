// Задача 7
// Есть класс А, в котором определены закрытые элементы X, Y и Z.
// Конструктор класса принимает три значения a, b и с.
// По умолчанию элемент а равен 10, а элемент b равен 0. Напишите определение класса с описанным конструктором.

#include <iostream>

class A {
private:
    int X;
    int Y;
    int Z;
public:
    A(const int c, const int a = 10, const int b = 0 ) : X(a), Y(b), Z(c){}
    void Print() 
    {
        std::cout << "A = {" << "X = " << X << ", Y = " << Y << ", Z = " << Z;
    };
};
int main()
{
    A a1(2);
    std::cout << "a1(2) => "; a1.Print(); std::cout<< "}" << std::endl;
    A a2(3, 2, 1);
    std::cout << "a2(3,2,1) => "; a2.Print(); std::cout << "}" << std::endl;
    A a3(3, 2);
    std::cout << "a3(3, 2) => "; a3.Print(); std::cout << "}" << std::endl;
 
}
