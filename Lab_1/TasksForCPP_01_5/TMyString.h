#pragma once
#include <iostream>

class TMyString
{
public:
	TMyString();
	TMyString(const char* src);
	TMyString(const TMyString& ref);
	TMyString(TMyString&& ref) noexcept;
	~TMyString();
	int Length();
	void Print() const;
	void CopyFrom(TMyString src, int pos);
private:
	char* data;
	int capasity;
};
std::ostream& operator<< (std::ostream& out,
	const TMyString& ref);
std::istream& operator>> (std::ostream& in,
	TMyString& ref);

