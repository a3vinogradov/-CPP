#pragma once
// страж включения, чтобы не включался хедер дважды
#include <iostream>


class Vector 
{
public:
	Vector() : data(nullptr), size(0), capacity(0) {}
	Vector(size_t size);
	Vector(size_t size, int val);
	Vector(const Vector& ref);
	~Vector();
	void Print() const;
	void PushBack(int val);
	void Init();
	int PopBack();
	int At(size_t index) const;
	int& At(size_t index);
	int& GetElem(size_t index);

	size_t Size() const { return size; }
	size_t Capacity() const { return capacity; }

	Vector& operator= (const Vector& right);
	Vector operator+ (const Vector& right) const;
	Vector& operator+ (int value);
	int& operator[] (size_t index);
	int operator[] (size_t index) const;
	Vector& operator++ ();
	Vector operator++(int);
	bool operator== (const Vector& right);
	bool operator!= (const Vector& right);

private:
	int* data;
	size_t size;
	size_t capacity;

	void AddTail(Vector& to, const Vector& from, int min, int max) const;

};
std::ostream& operator<<(std::ostream& out, const Vector& ref);
std::istream& operator>>(std::istream& in,  Vector& ref);

