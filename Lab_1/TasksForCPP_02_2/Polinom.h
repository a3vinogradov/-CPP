#pragma once
#include <vector>
#include <string>
// Класс для представления многочлена вида C(n)x^n + C(n-1)x^(n-1) + ... Cx + C(0)
using namespace std;

class Polinom
{
	std::vector<double> _nomos;
	void CheckDegree();
public:
	Polinom();
	size_t Degree() const;
	void SetKoef(const size_t index, const double value);
	double GetKoef(const size_t index) const;
	Polinom& Add(const Polinom& addend);
	Polinom& Multiply(const double mul);
	Polinom& Multiply(const Polinom& right);
	Polinom& Minus(const Polinom& po2);
	Polinom& IncPow(const size_t aPow);
	operator std::string() const;
	Polinom operator -() const;
	Polinom operator + (const Polinom& right)const;
	Polinom operator * (const double mul) const;
	Polinom operator * (const Polinom& right) const;
	Polinom operator - (const Polinom& right) const;
	Polinom operator +=(const Polinom& right) const;
	Polinom operator -=(const Polinom& right) const;
	Polinom operator *=(const Polinom& right) const;
};
std::ostream& operator <<(std::ostream& os, const Polinom& po);

