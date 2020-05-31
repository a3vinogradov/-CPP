#include <iostream>
#include <algorithm>
#include "Polinom.h"

void Polinom::CheckDegree()
{
	while (Degree()>0 && (0.0 == _nomos[Degree()])) {
		_nomos.pop_back();
	}
}

Polinom::Polinom()
{
	_nomos.push_back(0);
}

size_t Polinom::Degree() const
{
	return size_t(_nomos.size() - 1);
}

void Polinom::SetKoef(const size_t index, const double value)
{
	while (Degree() < index) {
		_nomos.push_back(0);
	}
	_nomos.at(index) = value;
	CheckDegree();
}

double Polinom::GetKoef(const size_t index) const
{
	if (index > Degree())
	{
		return 0;
	}
	else
	{
		return _nomos[index];
	}
}
Polinom& Polinom::Add(const Polinom& addend)
{
	for (size_t i = 0; i <= std::max(Degree(), addend.Degree()); i++)
	{
		SetKoef(i, GetKoef(i) + addend.GetKoef(i));
	}
	CheckDegree();
	return *this;
}

Polinom& Polinom::Multiply(const double mul)
{
	for (size_t i = 0; i <= Degree(); i++)
	{
		SetKoef(i, GetKoef(i) * mul);
	}
	CheckDegree();
	return *this;
}

Polinom& Polinom::Multiply(const Polinom& right)
{
	Polinom left(*this);
	Polinom res;
	for (size_t i = 0; i <= right.Degree(); i++)
	{
		Polinom tmp(left);
		tmp.IncPow(i);
		tmp.Multiply(right.GetKoef(i));
		res.Add(tmp);
	}
	*this = res;
	return *this;
}

Polinom& Polinom::Minus(const Polinom& po2)
{
	return Add(-po2);
}

Polinom& Polinom::IncPow(const size_t aPow)
{	
	if (aPow > 0)
	{

		for (size_t i = Degree() + aPow; i >= aPow; i--)
		{
			SetKoef(i, GetKoef(i - aPow));
		}
		for (int i = 0; i < aPow; i++)
		{
			SetKoef(i, 0);
		}
	}
	return *this;	
}



std::ostream& operator <<(std::ostream& os, const Polinom& po)
{
	size_t i = po.Degree();
	do
	{
		if (po.GetKoef(i) != 0)
		{
			if (i == po.Degree())
			{
				os << po.GetKoef(i);
			}
			else {
				os << (po.GetKoef(i) < 0 ? " - " : " + ") << abs(po.GetKoef(i));
			}

			if (i > 0)
			{
				os << "x^" << i;
			}

		}
		else {
			if ((i == 0)&&(po.Degree()==0)) {
				os << po.GetKoef(i);
			}

		}
	} while (i-- > 0);

	return os;
}

Polinom Polinom::operator* (const double mul) const
{
	Polinom res(*this);
	return res.Multiply(mul);
}

Polinom Polinom::operator-(const Polinom& right) const
{
	return *this + (-right);
}
Polinom Polinom::operator-() const
{
	Polinom res(*this);
	res.Multiply(-1);
	return res;
}
Polinom Polinom::operator+(const Polinom& right) const
{
	Polinom res(*this);
	res.Add(right);
	return res;
}
Polinom Polinom::operator*(const Polinom& right) const
{
	Polinom res(*this);
	res.Multiply(right);
	return res;
}
Polinom Polinom::operator+=(const Polinom& right) const
{
	return *this + right;
}
Polinom Polinom::operator-=(const Polinom& right) const
{
	return *this - right;
}
Polinom Polinom::operator*=(const Polinom& right) const
{
	return *this * right;
}
;
