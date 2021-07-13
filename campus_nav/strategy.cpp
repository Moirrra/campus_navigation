#include "strategy.h"
#include <QDebug>
#include <QSqlQuery>
#include "graph.h"
#include "path.h"

#define shahecnt 68
#define benbucnt 93
#define inf 32767
#define SRC1 0
#define SRC2 19
#define crossLength 200000
#define MINUTE 60
#define HOUR 24

/*
 * @brief Strategy::Strategy
 * @author ts
 */
Strategy::Strategy()
{
    footSpeed = 80;
    bikeSpeed = 250;
    graph = new Graph(shahecnt,benbucnt);
    transferTool = 0;
    totalLength = 0;
    timeCost = 0;
    waitTime = 0;
}

/*
 * @usage 自定义步行速度的构造函数
 * @brief Strategy::Strategy
 * @param fspeed 自定义的步行速度
 * @author ts
 */
Strategy::Strategy(int fspeed)
{
    footSpeed = fspeed;
    bikeSpeed = 250;
    graph = new Graph(shahecnt,benbucnt);
    transferTool = 0;
    totalLength = 0;
    timeCost = 0;
    waitTime = 0;
}

/*
 * @usage 计算总用时
 * @brief void Strategy::calTimeCost
 * @author ts
 */
int Strategy::calTimeCost(int type,int ifCon,int ifbike)
{

    double totalTime = 0;
    troute[type-1].clear();
    for(int i = 0; i < lroute[type-1].size(); i++)
    {
        if(ifCon)
        {
            if(ifbike)
            {
                troute[type-1].append(lroute[type-1][i] / (bikeSpeed * conList[type-1][i]));
            }
            else troute[type-1].append(lroute[type-1][i] / (footSpeed * conList[type-1][i]));
        }
        else
            troute[type-1].append(lroute[type-1][i] / footSpeed);
        totalTime += troute[type-1][i];
    }
    qDebug()<<totalTime;
    totalTime = ceil(totalTime);
    return totalTime;
}

/*
 * @usage 计算到达时间
 * @brief void Strategy::calEndTime
 * @param tCost 时间花销（分钟）
 * @author ts
 */
void Strategy::calEndTime(int tCost)
{
    qint64 second = tCost * 60;
    qDebug()<<second;
    endTime = beginTime.addSecs(second);

}

/*
 * @usage 规格化时间(min ——> day + hour + min)
 * @brief QString Strategy::standardTime
 * @param m 总时间(min)
 * @return 规格化的时间字符串
 * @author ts
 */
QString Strategy::standardTime(int m)
{
    int h=0,d=0;
    int hcarry = 0, dcarry = 0;
    if (m >= MINUTE)
    {
        hcarry = m / MINUTE;
        m %= MINUTE;
        h += hcarry;
    }

    if (h >= HOUR)
    {
        dcarry = h / HOUR;
        h %= HOUR;
        d += dcarry;
    }
    QString sTime = QString("%1 day %2 hour %3 min").arg(d).arg(h).arg(m);
    return sTime;
}

/*
 * @usage 最短路径算法
 * @brief int Strategy::calTotalLength
 * @param type 校区类型
 * @param src 出发地序号
 * @param reversePath 最短路径算法得到的逆序路径
 * @param num 逆序路径数组的最大序号
 * @param ifCon 是否计算拥挤度
 * @param ifbike 是否考虑自行车
 * @return 路线总长度
 * @author ts
 */
int Strategy::calTotalLength(int type, int src, int reversePath[], int num, int ifCon, int ifbike)
{
    int sum = 0;//距离
    lroute[type-1].clear();
    for(int i = num; i>0; i--)
    {
        int fromVex = reversePath[i];
        int toVex = reversePath[i-1];
        if(type %2 ==1)//校区1
        {
            //各段路径长
            qDebug()<<toVex<<graph->adjMatrix1[fromVex][toVex].length;
            lroute[type-1].append(graph->adjMatrix1[fromVex][toVex].length);
            if(ifCon) conList[type-1].append(graph->adjMatrix1[fromVex][toVex].congestion);
            if(ifbike)ifBikeList[type-1].append(graph->adjMatrix1[fromVex][toVex].ifBike);
            //途径各点名称
            route[type-1].append(toVex);
        }
        else
        {
            //各段路径长
            qDebug()<<toVex<<graph->adjMatrix2[fromVex][toVex].length;
            lroute[type-1].append(graph->adjMatrix2[fromVex][toVex].length);
            if(ifCon) conList[type-1].append(graph->adjMatrix2[fromVex][toVex].congestion);
            if(ifbike)ifBikeList[type-1].append(graph->adjMatrix2[fromVex][toVex].ifBike);
            //途径各点名称
            route[type-1].append(toVex);
        }

    }
    route[type-1].insert(0,src);//添加起点序号
    qDebug()<<"route[type-1].size="<<route[type-1].size();
    for(int i = 0; i<lroute[type-1].size();i++)
    {
        sum+=lroute[type-1][i];
    }
    return sum;
}

/*
 * @usage 最短路径算法
 * @brief int Strategy::Dijkstra
 * @param type 校区类型
 * @param src 出发地序号
 * @param dest 目的地序号
 * @param ifCon 是否计算拥挤度
 * @param ifbike 是否考虑自行车
 * @return 路线总长度
 * @author wys zzs ts
 */
int Strategy::Dijkstra(int type, int src, int dest, int ifCon, int ifbike)
{
    Path **matrix;
    int MAX;
    if(type%2==1)
    {
        MAX = graph->vexnum1;
        matrix = graph->adjMatrix1;
    }
    else
    {
        MAX = graph->vexnum2;
        matrix = graph->adjMatrix2;
    }
    if(src==dest) return 0;
    int reversePath[MAX]; //记录包括起点终点在内的逆向最短路径
    int ifVisited[MAX]; //节点是否被访问
    double srcToCurLen[MAX];  //从起点到当前节点的长度
    int preVex[MAX]; //起点到当前节点最短路径的前驱
    for(int i = 0;i < MAX;i++)
    {
        ifVisited[i] = 0;
        if(ifCon)
            srcToCurLen[i] = matrix[src][i].length / matrix[src][i].congestion;
        else
            srcToCurLen[i] = matrix[src][i].length;
        //初始化prev[]数组，与起点无路径则置为-1，有路径则初始化为src
        if(matrix[src][i].length==inf)
            preVex[i] = -1;
        else preVex[i] = src;
    }
    ifVisited[src] = 1;
    preVex[src] = 0;
    for(int i = 0;i < MAX;i++)
    {
        double min = inf; //min用于记录最小dest[i]
        int temp = src;  //temp当前起始点
        for(int j = 0;j < MAX;j++)
        {
            if(ifVisited[j]==0 && srcToCurLen[j]<min)
            {
                min = srcToCurLen[j];
                temp = j;
            }
        }
        if(temp!=i) ifVisited[temp] = 1;   //选用点temp

        for(int j = 0;j < MAX;j++)
        {
            if(ifCon)
            {
                if((ifVisited[j]==0) && (srcToCurLen[j] >
                                         matrix[temp][j].length / matrix[temp][j].congestion + srcToCurLen[temp]))
                {
                    preVex[j] = temp;
                    srcToCurLen[j] = matrix[temp][j].length / matrix[temp][j].congestion + srcToCurLen[temp];
                }
            }
            else
            {
                if((ifVisited[j]==0) && (srcToCurLen[j] >
                                         matrix[temp][j].length + srcToCurLen[temp]))
                {
                    preVex[j] = temp;
                    srcToCurLen[j] = matrix[temp][j].length + srcToCurLen[temp];
                }
            }
        }
    }
    reversePath[0] = dest;
    int num=1, j=dest;
    while(j!=src)
    {
        reversePath[num] = preVex[j];
        j = preVex[j]; //j为前驱结点编号
        num++;
    }
    num = num -1;
    for(int i = num; i >=0; i--)
    {
        qDebug()<<reversePath[i];
    }
    return calTotalLength(type,src,reversePath,num,ifCon,ifbike);
}

/*
 * @usage 最短距离策略 （步行+不计算拥挤度）
 * @brief void Strategy::shortestStrategy
 * @param type1 出发地校区类型
 * @param src 出发地序号
 * @param type2 目的地校区类型
 * @param dest 目的地序号
 * @author ts zzs
 */
void Strategy::shortestStrategy(int type1, int src, int type2, int dest)
{
    if(type1==type2)
    {
        totalLength = Dijkstra(type1,src,dest,0,0);
        timeCost = calTimeCost(type1,0,0);
    }
    else
    {
        if(type1==1)
            totalLength = Dijkstra(type1,src,SRC1,0,0);
        else totalLength = Dijkstra(type1,src,SRC2,0,0);
        timeCost = calTimeCost(type1,0,0);

        QDateTime curTime = beginTime.addSecs(timeCost*60);
        waitTime = 0;
        transferTool = shortestTransfer(type1,curTime, waitTime);
        qDebug()<<"transfer time = "<<transferTool;
        qDebug()<<"wait time = "<<waitTime;
        timeCost += transferTool;
        timeCost += waitTime;
        totalLength += crossLength;
        if(type1==1)
            totalLength += Dijkstra(type2,SRC2,dest,0,0);
        else totalLength += Dijkstra(type2,SRC1,dest,0,0);
        timeCost += calTimeCost(type2,0,0);
     }

    calEndTime(timeCost);
    qDebug()<<endTime;
    qDebug()<<"totalLength:"<<totalLength;
    qDebug()<<"totalTime:"<<timeCost;
}

/*
 * @usage 最短时间策略（步行+计算拥挤度）
 * @brief void Strategy::fastestStrategy
 * @param type1 出发地校区类型
 * @param src 出发地序号
 * @param type2 目的地校区类型
 * @param dest 目的地序号
 * @author ts zzs
 */
void Strategy::fastestStrategy(int type1, int src, int type2, int dest)
{
    if(type1==type2)
    {
        totalLength = Dijkstra(type1,src,dest,1,0);
        timeCost = calTimeCost(type1,1,0);
    }
    else
    {
        if(type1==1)
            totalLength = Dijkstra(type1,src,SRC1,1,0);
        else totalLength = Dijkstra(type1,src,SRC2,1,0);
        timeCost = calTimeCost(type1,1,0);

        QDateTime curTime = beginTime.addSecs(timeCost*60);
        waitTime = 0;
        transferTool = shortestTransfer(type1,curTime, waitTime);
        qDebug()<<"transfer time = "<<transferTool;
        qDebug()<<"wait time = "<<waitTime;
        timeCost += transferTool;
        timeCost += waitTime;
        totalLength += crossLength;
        if(type1==1)
            totalLength += Dijkstra(type2,SRC2,dest,1,0);
        else totalLength += Dijkstra(type2,SRC1,dest,1,0);
        timeCost += calTimeCost(type2,1,0);
     }

    calEndTime(timeCost);
    qDebug()<<endTime;
    qDebug()<<"totalLength:"<<totalLength;
    qDebug()<<"totalTime:"<<timeCost;
}

/*
 * @usage 途径某地最短距离策略 （步行+不计算拥挤度）
 * @brief void Strategy::shortestPassStrategy
 * @param type1 出发地校区类型
 * @param src 出发地序号
 * @param type2 目的地校区类型
 * @param dest 目的地序号
 * @param passType 途径地校区类型
 * @param pass 途径地序号
 * @author ts zzs
 */
void Strategy::shortestPassStrategy(int type1, int src, int type2, int dest, int passType, int pass)
{
    if(type1==type2)
    {
        if(type1==passType)//都在同一校区
        {
            totalLength = Dijkstra(type1,src,pass,0,0);
            timeCost = calTimeCost(type1,0,0);
            totalLength += Dijkstra(type1+2,pass,dest,0,0);
            timeCost += calTimeCost(type1+2,0,0);
        }
        //else 归为特殊情况
    }

    else
    {
        if(type1==passType)
        {
            totalLength = Dijkstra(type1,src,pass,0,0);
            timeCost = calTimeCost(type1,0,0);

            if(type1==1)
                totalLength += Dijkstra(type1+2,pass,SRC1,0,0);
            else totalLength += Dijkstra(type1+2,pass,SRC2,0,0);
            timeCost += calTimeCost(type1+2,0,0);

            QDateTime curTime = beginTime.addSecs(timeCost*60);
            waitTime = 0;
            transferTool = shortestTransfer(type1,curTime, waitTime);
            timeCost += transferTool;
            timeCost += waitTime;
            totalLength += crossLength;

            if(type1==1)
                totalLength += Dijkstra(type2,SRC2,dest,0,0);
            else totalLength += Dijkstra(type2,SRC1,dest,0,0);
                timeCost += calTimeCost(type2,0,0);
        }
        else
        {//type2==passType
            if(type1==1)
                totalLength = Dijkstra(type1,src,SRC1,0,0);
            else totalLength = Dijkstra(type1,src,SRC2,0,0);
            timeCost += calTimeCost(type1,0,0);

            QDateTime curTime = beginTime.addSecs(timeCost*60);
            waitTime = 0;
            transferTool = shortestTransfer(type1,curTime, waitTime);
            timeCost += transferTool;
            timeCost += waitTime;
            totalLength += crossLength;

            if(type1==1)
                totalLength += Dijkstra(type2,SRC2,pass,0,0);
            else totalLength += Dijkstra(type2,SRC1,pass,0,0);
                timeCost += calTimeCost(type2,0,0);

            totalLength += Dijkstra(type2+2,pass,dest,0,0);
            timeCost += calTimeCost(type2+2,0,0);
        }

    }
    calEndTime(timeCost);
    qDebug()<<endTime;
    qDebug()<<"totalLength:"<<totalLength;
    qDebug()<<"totalTime:"<<timeCost;

}

/*
 * @usage 使用交通工具最短时间策略（优先自行车+计算拥挤度）
 * @brief void Strategy::fastestToolStrategy
 * @param type1 出发地校区类型
 * @param src 出发地序号
 * @param type2 目的地校区类型
 * @param dest 目的地序号
 * @author ts
 */
void Strategy::fastestToolStrategy(int type1, int src, int type2, int dest)
{
    if(type1==type2)
    {
        totalLength = Dijkstra(type1,src,dest,1,1);
        timeCost = calTimeCost(type1,1,1);
    }
    else
    {
        if(type1==1)
            totalLength = Dijkstra(type1,src,SRC1,1,1);
        else totalLength = Dijkstra(type1,src,SRC2,1,1);
        timeCost = calTimeCost(type1,1,1);

        QDateTime curTime = beginTime.addSecs(timeCost*60);
        waitTime = 0;
        transferTool = shortestTransfer(type1,curTime, waitTime);
        qDebug()<<"transfer time = "<<transferTool;
        qDebug()<<"wait time = "<<waitTime;
        timeCost += transferTool;
        timeCost += waitTime;
        totalLength += crossLength;
        if(type1==1)
            totalLength += Dijkstra(type2,SRC2,dest,1,1);
        else totalLength += Dijkstra(type2,SRC1,dest,1,1);
        timeCost += calTimeCost(type2,1,1);
     }

    calEndTime(timeCost);
    qDebug()<<endTime;
    qDebug()<<"totalLength:"<<totalLength;
    qDebug()<<"totalTime:"<<timeCost;
}

/*
 * @usage 计算跨校区最短用时及等车时间
 * @brief int Strategy::shortestTransfer
 * @param type1 出发地校区类型
 * @param curTime 当前时刻
 * @param waitTime 等车时间
 * @return 跨校区最短用时 60班车 90公交车
 * @author zzs ts
 */
int Strategy::shortestTransfer(int type1,QDateTime curTime, int &waitTime)
{
    int flag = 0;//flag为1 选择公交车
    QTime busTime;//最近公交车时刻
    QTime upBusTime;//最近公交车时刻
    QString busTimeStr;
    QString upBusTimeStr;
    QSqlQuery query;
    QString nowTime = curTime.toString("hh:mm");
    qDebug()<<"nowTime="<<nowTime;
    QString str1 = QString("select * from busTimeTable where startTime >= '%1'").arg(nowTime);
    query.exec(str1);
    if(query.first())
    {
        busTimeStr = query.value(1).toString();
        busTime = QTime::fromString(busTimeStr,"hh:mm");
        qDebug()<<"latest bus:"<<busTime.toString("hh:mm");
    }
    else
    {
        qDebug()<<"not found bus startTime";
        return 0;
    }

    QString src;
    if(type1==1) src = "沙河";
    else src = "本部";
    QString str2 = QString("select * from timeTable where src='%1' and startTime >= '%2'").arg(src).arg(nowTime);
    query.exec(str2);
    if(query.first())
    {
        upBusTimeStr = query.value(3).toString();
        upBusTime = QTime::fromString(upBusTimeStr,"hh:mm");
        qDebug()<<"latest upbus:"<<upBusTime.toString("hh:mm");
    }
    else
    {
        qDebug()<<"not found upbus startTime";
        flag=1;
    }
    QTime curtime = QTime::fromString(curTime.toString("hh:mm"),"hh:mm");
    //等待时间
    int busDif = ceil(curtime.secsTo(busTime)/60);
    int upBusDif = ceil(curtime.secsTo(upBusTime)/60);
    if(busDif+90<upBusDif+60 || flag)
    {
        waitTime = busDif;
        return 90;
    }
    else
    {
        waitTime = upBusDif;
        return 60;
    }
}












