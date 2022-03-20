#include<stdlib.h>
#include<stdio.h>
#include"graph.h"
#define MAXVERTICES 100
#define MAXNUMEDGES 100
#define VERTEXNUMBERS 10
#define EDGENUMBERS 10

//初始化邻接表 
void InitialAdjacencyList(Vertex * vertexList, int * everyVentexEdges, int * allEdgeVNums, int vertexNumbers);
//打印邻接表
void PrintAdjacencyList(Vertex * vertexList, int vertexNumbers);

int main(int argc, char const *argv[])
{
    Graph * formalGraph  = (Graph*)malloc(sizeof(Graph));
    Vertex * vertexList = (Vertex*)malloc(sizeof(Vertex)*VERTEXNUMBERS);

    // int everyVentexEdges[VERTEXNUMBERS] = {3,3,3,3,2};
    // int allEdgeVNums[EDGENUMBERS*2] = {2,3,4,1,3,4,1,2,5,1,2,5,3,4};

    // int everyVentexEdges[VERTEXNUMBERS] = {2,2,2,1,3,1,1};
    // int allEdgeVNums[EDGENUMBERS*2] = {2,3,1,3,1,2,5,4,6,7,5,5};

    //有向图
    // int everyVentexEdges[VERTEXNUMBERS] = {1,1,2,2,0};
    // int allEdgeVNums[EDGENUMBERS*2] = {2,5,1,5,2,3};

    int everyVentexEdges[VERTEXNUMBERS] = {3,3,3,3,2,2,1,1,1,1};
    int allEdgeVNums[EDGENUMBERS*2] = {2,3,6,1,4,5,1,7,8,2,5,6,2,4,1,4,3,3,10,9};

    InitialAdjacencyList(vertexList,everyVentexEdges,allEdgeVNums,VERTEXNUMBERS);
    PrintAdjacencyList(vertexList,VERTEXNUMBERS);
    InitialGraph(formalGraph,vertexList,VERTEXNUMBERS,EDGENUMBERS,MAXVERTICES,MAXNUMEDGES);
    DFS(formalGraph);

    return 0;
}

/*初始化邻接表 vertexList
everyVentexEdges： 邻接表中每个顶点所拥有的边数 
allEdgeVNums： 邻接表中所有边所拥有的另一个顶点的序号
图的顶点数： vertexNumbers
*/
void InitialAdjacencyList(Vertex * vertexList, int * everyVentexEdges, int * allEdgeVNums, int vertexNumbers){
    Edge * formalEdge = NULL;
    int j = 0;
    for(int i =0; i<vertexNumbers; i++){
        for(int k =0;k<everyVentexEdges[i];k++,j++){
            InsertEdge(&formalEdge,allEdgeVNums[j],everyVentexEdges[i]);
        }
        InitialVertex(vertexList+i,'a'+i,formalEdge);
        formalEdge = NULL;
    }
}
//打印邻接表
void PrintAdjacencyList(Vertex * vertexList, int vertexNumbers){
    for(int i = 0; i<vertexNumbers; i++){
        printf("%c: ", vertexList[i].data);
        for(Edge * p = (vertexList+i)->out; p!=NULL; p=p->next){
            printf("%d|%d   ",p->nextVertexNum+1, p->vertexinfo);
        }
        printf("\n");
    }
    printf("\n");
}