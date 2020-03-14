#include "Vector.h"
#include "time.h"
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
		this->data[i] = ref.data[i];
	}
}
Vector::~Vector() 
{
	delete [] data;
};

void Vector:: Init()
{
	srand((unsigned int)time(0));
	for (int i = 0; i < Size(); i++)
	{
		GetElem(i) = rand() % (size * 2)+1;
	}
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
int& Vector::GetElem(size_t index)
{
	if (size <= index) {
		throw std::out_of_range("Error!");
	}
	else {
		return data[index];
	}
};

Vector& Vector::operator= (const Vector& right)
{
	if (this != &right)
	{
		delete[] data;
		data = new int[capacity = right.capacity];
		size = right.size;
		for (int i=0; i<size; i++)
		{
			data[i] = right[i];
		}
	}
	return *this;
};

Vector Vector::operator+ (const Vector& right) const
{
	size_t min = size < right.size ? size : right.size;
	size_t max = size > right.size ? size : right.size;

	int j = size < right.size ? 1 : 2;
	Vector res(max);
	res.size = max;
	for (int i = 0; i < min; i++)
	{
		res[i] = data[i]+right[i];
	}
	if (1 == j)
	{
		AddTail(res, right, min, max);
	}
	else
	{
		AddTail(res, *this, min, max);
	}
	return res;
};
void Vector::AddTail(Vector& to, const Vector& from, int min, int max) const
{
	for (int i = min; i < max; i++)
	{
		to[i] = from[i];
	}
}


Vector& Vector::operator+ (int value)
{
	PushBack(value);
	return *this;
}

int& Vector::operator[] (size_t index)
{
	return At(index);
}
int Vector::operator[] (size_t index) const
{
	return At(index);
}
Vector& Vector::operator++ ()
{
	for (int i = 0; i < size; i++)
	{
		data[i]++;
	}
	return *this;
}
Vector Vector::operator++(int)
{
	Vector temp(*this);
	++*this;
	return temp;
}
bool Vector::operator==(const Vector& right)
{
	
	bool result = true;
	result = (size == right.size);
	if (result)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] != right[i]) 
			{
				result = false;
				break;
			}
		}
	}
	return result;
}
bool Vector::operator!=(const Vector& right)
{
	return !(*this == right);
}
std::ostream& operator<<(std::ostream& out, const Vector& ref)
{
	ref.Print();
	return out;
}
std::istream& operator>>(std::istream& in,  Vector& ref)
{
	int count = 0;
	std::cout << "inpit quantity of elements: ";
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		int el;
		std::cout << "input element " << i << ": ";
		std::cin >> el;
		ref.PushBack(el);
	}
	return in;
}