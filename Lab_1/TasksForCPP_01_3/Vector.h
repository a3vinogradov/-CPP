#pragma once
// ����� ���������, ����� �� ��������� ����� ������

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
private:
	int* data;
	size_t size;
	size_t capacity;


};