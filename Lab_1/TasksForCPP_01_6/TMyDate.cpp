#define _CRT_SECURE_NO_WARNINGS

#include "TMyDate.h"
#include <iomanip>


void TMyDate::SetTM(tm time)
{
    day = time.tm_mday;
    month = time.tm_mon + 1;
    year = time.tm_year + 1900;
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

void TMyDate::IncDays(int days)
{
    day = day + days;

}

void TMyDate::IncMonth(int diff)
{
    month = month + diff;
    if (month > 12) {
        
        int tmp = month / 12;
        IncYears(tmp);
        month = month % 12;
    }
}

void TMyDate::IncYears(int diff)
{
    year = year + diff;
}

int TMyDate::DiffInDays(TMyDate& ref)
{
    day = day - ref.day;
    if (day < 0) 
    return 0;
}
