#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <QString>
#include "strategy.h"
#include "graph.h"

class Student
{
private:
    /* ui页面获取 */
    string src;
    string dest;
    NAV_TYPE chooseType;
    int speed;
    int currentX; //当前x坐标
    int currentY; //当前y坐标
    vector<string> passVex; //途径点

    Strategy result;
    QString log;

public:
    Student();
    Student(string begin, string end, int x, int y);
    Student(string begin, string end, NAV_TYPE type, int s, int x, int y);
    Student(string begin, string end, NAV_TYPE type, int s, int x, int y, vector<string> pass);
    ~Student();

    string getSrc();
    string getDest();
    NAV_TYPE getChooseType();
    int getSpeed();
    int getX();
    int getY();
    Strategy getStrategy();
    QString getLog();

    /* 查询模块 */
    void search();
};

#endif // STUDENT_H
