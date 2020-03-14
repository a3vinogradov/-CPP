#include "Vector.h"
#include <iostream>
#include <stdexcept>

Vector::Vector(size_t size) : capacity(size), size(0)
{
	this->data = new int[capacity];
}

Vector::Vector(size_t size, int val) : capacity(size), size(size)

{
	this->data = new int[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = val;
	}
}
Vector::Vector(const Vector& ref) :capacity(ref.capacity), size(ref.size) 
{
	this->data = new int[capacity];
	for (int i = 0; i < size; i++) 
	{
		data[i] = ref.data[i];
	}
}
Vector::~Vector() 
{
	delete [] data;
};
void Vector::Print() const
{
	if (size == 0) {
		std::cout << "Vector empty!" << std::endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
 
};
void Vector::PushBack(int val) {
	if (size == capacity) {
		int* temp = new int[capacity = capacity==0?1:capacity*2];
		for (int i = 0; i < size; i++) {
			temp[i] = data[i];
		}
		delete [] data;
		data = temp;
	}
	data[size++] = val;

};
int Vector::PopBack() 
{
	if (size == 0) {
		throw std::underflow_error("Error! Empty vector!");
	}
	else {
		return data[--size];
	}
};
int Vector::At(size_t index) const {
	if (size <= index) {
		throw std::out_of_range("Error!");
	}
	else {
		return data[index];
	}

};
int& Vector::At(size_t index)
{
	if (size <= index) {
		throw std::out_of_range("Error!");
	}
	else {
		return data[index];
	}	
}