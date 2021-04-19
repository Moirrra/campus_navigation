#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <string>
#include "mytime.h"
#include "student.h"

enum NAV_TYPE
{
    shortest,
    fastest,
    shortestPass,
    fastestTool
};

class Strategy
{
public:
    NAV_TYPE navType;
    MyTime beginTime; //开始时间
    MyTime endTime; //结束时间
    MyTime timeCost;//时间开销
    vector<Path> route; //从出发点到终点的路径

    Strategy();
    Strategy(NAV_TYPE t, string src,string dest, MyTime departTime);
    ~Strategy();

    void calEndTime();

    

    /*四种策略*/
    Strategy shortestStrategy(int x, int y, int speed, Graph graph, );
    Strategy fastestStrategy();
    Strategy shortestPassStrategy();
    Strategy fastestToolStrategy();
};

#endif // STRATEGY_H
