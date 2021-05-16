#ifndef MYTIME_H
#define MYTIME_H

#include <QString>
#include <iostream>

class MyTime
{
public:
    unsigned day;
    unsigned hour;
    unsigned minute;

    MyTime();
    MyTime(unsigned d,unsigned h,unsigned m);
    MyTime(QString timeStr);
    MyTime(const MyTime &obj);//拷贝构造函数
    ~MyTime();

    /*操作符重载*/
    MyTime operator+(const MyTime &t);
    MyTime operator-(const MyTime &t);
    bool operator==(const MyTime &t);
    bool operator>(const MyTime &t);
    bool operator<(const MyTime &t);


};

void standardTime(unsigned &d, unsigned &h, unsigned &m);

#endif // MYTIME_H
