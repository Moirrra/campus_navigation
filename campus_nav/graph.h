#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>

#include "path.h"
#include "strategy.h"

using namespace std;

class Graph
{
private:
    int vexnum;          //顶点数
    vector<string> vexs; //顶点表
    Path **adjMatrix;    //邻接矩阵

    int locateVex(string vex); //返回顶点对应序号
    string getVex(int id);     //返回序号对应顶点

public:
    Graph(int num);
    ~Graph();

    int getLength(string v1, string v2); //返回两点间距离

    void setLength(string v1, string v2, int length); //设置两点间距离

    void setVexList(vector<string> list); //设置顶点表

    void shortestPathDJ(string src, string dest, vector<Path> &route); //最短路径算法
    
    void printMatrix();//打印领接矩阵
};

#endif // GRAPH_H
