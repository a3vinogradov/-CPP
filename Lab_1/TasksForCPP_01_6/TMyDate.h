#pragma once
#include <time.h>
#include <iostream>

class TMyDate
{
private:
    int day;
    int month;
    int year;
	void SetTM(tm time);
	int MaxDays();
	bool IsLeap();

public:
	TMyDate();
	TMyDate(time_t time);
	TMyDate(const int dd, const int mm, const int yyyy);
	TMyDate(const TMyDate& ref);
	TMyDate(TMyDate&& ref) noexcept;
	void Print() const;


	time_t ToTime_t();
	void SetTime_t(time_t time);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	void IncDays(int diff);
	void IncMonth(int diff);
	void IncYears(int diff);

	int DiffInDays(TMyDate& ref);
	int Compare(const TMyDate& ref) const;

	TMyDate operator = (const TMyDate& ref);
	friend bool operator == (const TMyDate& left, const TMyDate& right);
};


