#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <QString>

#include "path.h"
#include "strategy.h"

using namespace std;




class Graph
{
private:
    int vexnum;          //顶点数

    vector<string> vexsName; //顶点名称表
    vector<string> vexsType; //顶点类型表

    Path **adjMatrix;    //邻接矩阵

public:


    Graph(int num);
    ~Graph();

    int locateVex(string vexName); //返回顶点对应序号
    string getVexName(int id);     //返回序号对应顶点名称
    string getVexType(int id);     //返回序号对应顶点类型

    void loadGraph(const QString vTable,const QString dtable);

    void printMatrix();//打印邻接矩阵

    /* getter */
    int getLength(string v1, string v2); //返回两点间距离


    void shortestPathDJ(string src, string dest, vector<Path> &route); //最短路径算法
    

};



#endif // GRAPH_H
