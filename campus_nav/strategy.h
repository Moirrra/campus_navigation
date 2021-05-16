#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <string>
#include <vector>
#include "mytime.h"
#include "graph.h"
#include "path.h"

#define shortest 1
#define fastest 2
#define shortestPass 3
#define fastestTool 4


class Strategy
{
public:
    int navType;
    MyTime beginTime; //开始时间
    MyTime endTime; //结束时间
    MyTime timeCost;//时间开销
    vector<Path> route; //从出发点到终点的路径

    Strategy();
    Strategy(int t, string src,string dest, MyTime departTime);
    ~Strategy();

    void calEndTime();

    

    /*四种策略*/
//    Strategy shortestStrategy(int x, int y, int speed, Graph graph, );
    Strategy fastestStrategy();
    Strategy shortestPassStrategy();
    Strategy fastestToolStrategy();
};

#endif // STRATEGY_H
