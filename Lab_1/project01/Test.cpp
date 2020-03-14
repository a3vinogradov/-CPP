#include <iostream>
#include "Vector.h"
#include "time.h"

void main() {
	Vector v1, v2(10), v3(10, 4);
	v1.Print();
	v2.Print();
	v3.Print();
	srand((unsigned int)time(0));	
	const int size = 3;
	int n[size] = { 0 };
	Vector* vs[size] = { &v1, &v2, &v3 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			vs[i]->PushBack(rand() % n[i] - n[i] / 2);
		}
	}
	try
	{
		v1.At(10) = 100;
		v1.Print();
	}
	catch (std::out_of_range & out){
		std::cerr << "wrong index 10" << std::endl;
	}
	int nn = rand() % 2;
	Vector v4;
	try {
		for (int i = 0; i < nn; ++i) {
			v4.PushBack(5);
		}
		std::cout << v4.PopBack() << std::endl;
	}
	catch (std::underflow_error & und) {
		std::cerr << "Underflow_error" << std::endl;
	}
	return;
}