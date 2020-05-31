#pragma once
#include <iostream>
// Задание
// Разработать класс для работы со строками. Нужно поддерживать функции 
// + создания строки, 
// + создания экземпляра класса из типа char*, 
// + добавления подстроки в существующую строку на нужное место, 
// + функцию поиска подстроки в строке, 
// + возвращения подстроки.
//
// мои: 
// - функция определения длинны строки.
// 
// Предусмотреть контроль над памятью.

class TMyString
{
public:
	TMyString();
	TMyString(const char* src);
	TMyString(const TMyString& ref);
	TMyString(TMyString&& ref) noexcept;
	~TMyString();
	int Length() const;
	void Print() const;
	void CopyFrom(TMyString& src, int pos);
	void Insert(TMyString& subStr, const int pos);
	int Pos(TMyString& subStr) const;
	char* SubString(const int from, const int count);
	char At(const size_t index) const;
private:
	char* data;
};
std::ostream& operator<< (std::ostream& out,
	const TMyString& ref);
std::istream& operator>> (std::ostream& in,
	TMyString& ref);

