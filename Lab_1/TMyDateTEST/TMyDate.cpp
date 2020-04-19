#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "TMyDate.h"
#include <iomanip>


void TMyDate::SetTM(tm time)
{
    day = time.tm_mday;
    month = time.tm_mon + 1;
    year = time.tm_year + 1900;
}

int TMyDate::MaxDays()
{
    switch (month) {
        case 9:
        case 4:
        case 6:
        case 11: 
            return 30;
            break;
        case 2:
            return (IsLeap()?29:28);
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
    }
    throw std::out_of_range("Error! Out of Range!");
}

bool TMyDate::IsLeap()
{
    return !((year % 4) || ( !(year % 100) && (year % 400)));
}

TMyDate::TMyDate(): day(0), month(0), year(0)
{}

TMyDate::TMyDate(time_t time)
{
    SetTime_t(time);
    return;
}

TMyDate::TMyDate(const int dd, const int mm, const int yyyy)
{
	day = dd;
	month = mm;
	year = yyyy;
}

TMyDate::TMyDate(const TMyDate& ref): day(ref.day), month(ref.month), year(ref.year)
{
}

TMyDate::TMyDate(TMyDate&& ref) noexcept: day(std::move(ref.day)), month(std::move(ref.month)), year(std::move(ref.year))
{
    ref.day = 0;
    ref.month = 0;
    ref.year = 0;
}

void TMyDate::Print() const
{
    using namespace std;
    cout << setw(2) << setfill('0') << day << "." <<
            setw(2) << setfill('0') << month << "." <<
            setw(4) << setfill('0') << year;
}

time_t TMyDate::ToTime_t()
{
    time_t ptr;
    time(&ptr);
    tm* tms;
    tms = localtime(&ptr);
    tms->tm_year = year-1900;
    tms->tm_mon = month-1;
    tms->tm_mday = day;
    
    return mktime(tms);
}

void TMyDate::SetTime_t(time_t time)
{
    tm* ptm = localtime(&time);
    day = ptm->tm_mday;
    month = ptm->tm_mon + 1;
    year = ptm->tm_year + 1900;
    return;
}

int TMyDate::GetDay() const
{
    return day;
}

int TMyDate::GetMonth() const
{
    return month;
}

int TMyDate::GetYear() const
{
    return year;
}

void TMyDate::IncDays(int days)
{
    day += days;
    while (day > MaxDays())
    {
        day -= MaxDays();
        IncMonth(1);
    }
    while (day < 1)
    {
        IncMonth(-1);
        day += MaxDays();
    }
    return;

}

void TMyDate::IncMonth(int diff)
{
    month = month + diff;
    int a = 0;
    int b = 0;
    if (month > 0) {
        a = (month - 1) / 12;
        b = (month - 1) % (12) + 1;        
    }
    else 
    {
        a = month / 12 -1;
        b = month % 12 + 12;
    }
    month = b;
    IncYears(a);
}

void TMyDate::IncYears(int diff)
{
    year = year + diff;
}

int TMyDate::DiffInDays(TMyDate& ref)
{
    int cmp = 0;
    int res = 0;
    TMyDate tmp(GetDay(), GetMonth(), GetYear());

    while (cmp = tmp.Compare(ref))
    {
        tmp.IncDays(-cmp);
        res+=cmp;
    }
    return res;

}

int TMyDate::Compare(TMyDate& ref)
{
    if (year > ref.year) { return 1; }
    if (year < ref.year) { return -1; }
    if (month > ref.month) { return 1; }
    if (month < ref.month) { return -1; }
    if (day > ref.day) { return 1; }
    if (day < ref.day) { return -1; }
    return 0;
}
