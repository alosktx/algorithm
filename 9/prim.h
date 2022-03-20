#pragma once
#define VERTEXNUMBERS 6

//Prim算法构造最小生成树
struct edge{
    int vi,vj;
    int weight;
};
typedef struct edge Edge;

//记录最小生成树
void PrimForMST(int vertexNumbers);