#include<stdbool.h>
#include"mydefine.h"
//基于邻接表表示的Graph结构
//边表
struct edge{
    //边的另一个顶点的序号
    int nextVertexNum;
    //边表结点对象
    EdgeType vertexinfo;
    //指向下一条边的指针
    struct edge * next;
};
typedef struct edge Edge;

//顶点表
struct vertex{
    //顶点数据
    VertexType data;
    //指向边表的指针
    Edge * out;
};
typedef struct vertex Vertex;


//图
struct graph{
    //顶点表
    Vertex * VertexList;
    //图中顶点个数
    int NumVertices;
    //图中边的数目
    int NumEdges;
    //图中允许的最大的顶点，边的个数
    int MaxVertices;
    int MaxNumEdges;
};
typedef struct graph Graph;

//初始化边表
Edge * CreateEdge(int nextVertexNum, EdgeType vertexInfo);
//将新的边表结点插入表
void InsertEdge(Edge ** formalEdge, int nextVertexNum, EdgeType vertexInfo);
//初始化顶点表
void InitialVertex(Vertex * formalVertex, VertexType data, Edge * vertexEdge);
//初始化图
void InitialGraph(Graph * formalGraph, Vertex * VertexList, int Numvertice, int NumEdges, int MaxVertices, int MaxNumEdges);


//对图进行深度优先遍历
void DFS(Graph * g);
//对图中由顶点v出发进行深度优先遍历
void dfs(Graph * g, int v, bool visited[]);
//返回图中顶点i的数据信息
VertexType ReturnValue(Graph * g, int i);
//返回图中与顶点v相关联的下一个顶点的编号
int ReturnFirstNeighbor(Graph * g, int v);
//返回图中与顶点vi相关联的一条边(vi,vj)的下一条边的另一个顶点的编号
int ReturnNextNeighbor(Graph * g, int vi, int vj);
