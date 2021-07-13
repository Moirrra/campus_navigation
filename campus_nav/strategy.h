#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include "graph.h"
#include "path.h"
#include <QDateTime>
#include <QMessageBox>

#define shortest 1
#define fastest 2
#define shortestPass 3
#define fastestTool 4


class Strategy
{
public:
    double footSpeed; //单位：m/min
    double bikeSpeed;
    int navType;
    int totalLength;
    QDateTime beginTime; //开始时间
    QDateTime endTime; //结束时间
    int timeCost;//时间开销
    class Graph *graph;//地图
    int transferTool;//跨校区交通工具 90公交车 60班车
    int waitTime;//等车时间
    QList<int> route[4];
    QList<double> lroute[4];
    QList<double> troute[4];
    QList<double> conList[4];
    QList<int> ifBikeList[4];
    Strategy();
    Strategy(int fspeed);
    ~Strategy();

    void calEndTime(int tCost);
    int calTimeCost(int type, int ifCon, int ifbike);
    QString standardTime(int m);
    int shortestTransfer(int type1, QDateTime curTime, int &waitTime);


    /*路径算法*/
    int Dijkstra(int type, int src, int dest, int ifCon, int ifbike);
    int calTotalLength(int type,int src,int reversePath[],int num,int ifCon, int ifbike);
    //四种策略
    void shortestStrategy(int type1, int src, int type2, int dest);
    void fastestStrategy(int type1, int src, int type2, int dest);
    void shortestPassStrategy(int type1, int src, int type2, int dest, int passType, int pass);
    void fastestToolStrategy(int type1, int src, int type2, int dest);
};

#endif // STRATEGY_H
