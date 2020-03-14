//#define _CRT_SECURE_NO_WARNINGS
#include "TMyString.h"
#include <utility>
#include <string.h>
#include <iostream>

//#define _CRT_SECURE_NO_WARNINGS

TMyString::TMyString(): data(0), capasity(0){}

TMyString::TMyString(const char* src)
{
	capasity = strlen(src) + 1;
	data = new char[capasity];
	strcpy(data, src);
}

TMyString::TMyString(const TMyString& ref): capasity(ref.capasity)
{
	data = new char[capasity];
	for (int i = 0; i < capasity; i++)
	{
		data[i] = ref.data[i];
	}
}

TMyString::TMyString(TMyString&& ref) noexcept : capasity(ref.capasity), data(std::move(ref.data))
{
	ref.data = nullptr;
	ref.capasity = 0;
}

TMyString::~TMyString()
{
	delete [] data;
}

int TMyString::Length()
{
	return strlen(data);
}

void TMyString::Print() const
{
	std::cout << data;
}

void TMyString::CopyFrom(TMyString src, int pos)
{
	int newCapacity = Length() + src.Length() + 1;
	char* tmp = new char[newCapacity];
	char* p1 = tmp;
	char* p2 = data;
	while (*p1++ = *p2++){}
	p2=src.data;
	while (*p1++ = *p2++) {}
	*p1 = *p2;
	delete[] data;
	data = tmp;
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