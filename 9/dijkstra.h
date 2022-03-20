#pragma once
typedef struct{
    int length;
    int pre;
}Path;
#define VERTEXNUMBERS 6
#define M 32767

//dijkstra算法求源点k到其他顶点的最短距离
void DIJ(int k);

//Floyd算法求网络中任意两顶点间的最短路径
void Floyd();