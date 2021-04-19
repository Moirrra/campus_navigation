#include "mytime.h"

using namespace std;

#define MINUTE 60
#define HOUR 24

void standardTime(unsigned &d, unsigned &h, unsigned &m)
{
    unsigned hcarry = 0;
    unsigned dcarry = 0;
    if (m >= MINUTE)
    {
        hcarry = m / MINUTE;
        m %= MINUTE;
        hcarry += hcarry;
    }
    if (h >= HOUR)
    {
        dcarry = h / HOUR;
        h %= HOUR;
        dcarry += dcarry;
    }
}

MyTime::MyTime()
{
    this->day = 0;
    this->hour = 0;
    this->minute = 0;
}

MyTime::MyTime(unsigned d, unsigned h, unsigned m)
{
    this->day = d;
    this->hour = h;
    this->minute = m;
    standardTime(this->day, this->hour, this->minute);
}

MyTime::MyTime(QString timeStr)
{
    this->day = 0;
    this->hour = timeStr.section(':', 0, 0).toUInt();
    this->minute = timeStr.section(':', 1, 1).toUInt();
    standardTime(this->day, this->hour, this->minute);
}

MyTime::MyTime(const MyTime &obj)
{
    this->day = obj.day;
    this->hour = obj.hour;
    this->minute = obj.minute;
    standardTime(this->day, this->hour, this->minute);
}

MyTime MyTime::operator+(const MyTime &t)
{
    MyTime newTime(this->day + t.day, this->hour + t.hour, this->minute + t.minute);
    return newTime;
}

MyTime MyTime::operator-(const MyTime &t)
{
    unsigned minuteSum = this->day * HOUR * MINUTE + this->hour * MINUTE + this->minute;
    unsigned tminuteSum = t.day * HOUR * MINUTE + t.hour * MINUTE + t.minute;
    if(minuteSum < tminuteSum)
        cerr << "Illegal Time" << endl;
    MyTime newTime(0, 0, minuteSum - tminuteSum);
}
bool MyTime::operator==(const MyTime &t)
{
    unsigned minuteSum = this->day * HOUR * MINUTE + this->hour * MINUTE + this->minute;
    unsigned tminuteSum = t.day * HOUR * MINUTE + t.hour * MINUTE + t.minute;
    return (minuteSum == tminuteSum);
}
bool MyTime::operator>(const MyTime &t)
{
    unsigned minuteSum = this->day * HOUR * MINUTE + this->hour * MINUTE + this->minute;
    unsigned tminuteSum = t.day * HOUR * MINUTE + t.hour * MINUTE + t.minute;
    return (minuteSum == tminuteSum);
}
bool MyTime::operator<(const MyTime &t)
{
    unsigned minuteSum = this->day * HOUR * MINUTE + this->hour * MINUTE + this->minute;
    unsigned tminuteSum = t.day * HOUR * MINUTE + t.hour * MINUTE + t.minute;
    return (minuteSum == tminuteSum);
}
