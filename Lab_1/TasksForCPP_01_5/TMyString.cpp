#define _CRT_SECURE_NO_WARNINGS
#include "TMyString.h"
#include <utility>
#include <string.h>
#include <iostream>

//#define _CRT_SECURE_NO_WARNINGS

TMyString::TMyString(): data(0){
	data = new char[1];
	data[0] = 0;
}

TMyString::TMyString(const char* src)
{
	data = new char[strlen(src) + 1];
	strcpy(data, src);
}

TMyString::TMyString(const TMyString& ref) 
{
	data = new char[ref.Length()+1];
	char* src = ref.data;
	char* dest = data;
	while (*dest++ = *src++) {}
}

TMyString::TMyString(TMyString&& ref) noexcept : data(std::move(ref.data))
{
	ref.data = new char[1];
	ref.data[0] = 0;
}

TMyString::~TMyString()
{
	delete [] data;
}

int TMyString::Length() const
{
	char* p = data;
	int res = 0;
	while (*p++) { ++res; }
	return res;
	//return strlen(data);
}

void TMyString::Print() const
{
	std::cout << data;
}

void TMyString::CopyFrom(TMyString& src, int pos)
{
	if (pos > Length()) {
		throw std::out_of_range("Error! index out of range!");
	}

	int newCapacity = pos + src.Length() + 1;
	char* tmp = new char[newCapacity];
	char* p1 = tmp;
	char* p2 = data;
	for (int i = 0; i < pos; i++) { *p1++ = *p2++; }
	p2=src.data;
	while (*p1++ = *p2++) {}
	
	delete [] data;
	data = tmp;
}

void TMyString::Insert(TMyString& subStr, const int pos)
{
	if (pos > Length()) {
		throw std::out_of_range("Error! index out of range!");
	}

	int newCapacity = Length() + subStr.Length() + 1;
	char* tmp = new char[newCapacity];

	char* dest = tmp;
	char* src1 = data;
	char* src2 = subStr.data;
	int i = 0;
	for (i = 0; i < pos ; i++) { *dest++ = *src1++; }
	while (*dest++ = *src2++) {	}
	dest--;
	while (*dest++ = *src1++) { }
	
	delete[] data;
	data = tmp;
}

int TMyString::Pos(TMyString& subStr) const
{
	for (int i = 0; i < Length(); i++) 
	{
		if (subStr.data[0] == data[i]) {
			bool isFind = true;
			for (int j = 0; j < subStr.Length(); j++) {
				if (data[i + j] != subStr.data[j]) 
				{
					isFind = false;
					break;
				}
			}
			if (isFind)
			{
				return i;
			}
		}

	}
	return -1;
}

char* TMyString::SubString(const int from, const int count)
{
	if (Length() < (from + count - 1)) 
	{
		throw std::out_of_range("Error! index out of range!");
	}
	char* temp = new char[count + 1];
	for (int i = 0; i < count; i++)
	{
		temp[i] = data[i + from];
	}
	temp[count] = 0;
	
	//TMyString res(temp);
	//delete[] temp;

	return temp;
}

std::ostream& operator<< (std::ostream& out,
	const TMyString& ref)
{
	ref.Print();
	return out;

};
std::istream& operator>> (std::istream& in,
	TMyString& ref)
{
	return in;
};