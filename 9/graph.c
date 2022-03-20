#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include"mydefine.h"
#include"graph.h"

//初始化边表
Edge * CreateEdge(int nextVertexNum, EdgeType vertexInfo){
    Edge * formalEdge = (Edge*)malloc(sizeof(Edge));
    formalEdge->nextVertexNum = nextVertexNum-1;
    formalEdge->vertexinfo = vertexInfo; 
    formalEdge->next=NULL;
    return formalEdge;
}
//将新的边表结点插入表
void InsertEdge(Edge ** formalEdge, int nextVertexNum, EdgeType vertexInfo){
    //初始化
    if(*formalEdge == NULL){
        // printf("[InsertEdge] start initial!\n");
        *formalEdge = CreateEdge(nextVertexNum,vertexInfo);
    }
    else{        
        Edge * tempEdge = *formalEdge;
        for(; tempEdge->next!=NULL; tempEdge= tempEdge->next);
        tempEdge->next = CreateEdge(nextVertexNum,vertexInfo);
    }
}
//初始化顶点表
void InitialVertex(Vertex * formalVertex, VertexType data, Edge * vertexEdge){
    formalVertex->data = data;
    formalVertex->out = vertexEdge;
}
//初始化图
void InitialGraph(Graph * formalGraph, Vertex * VertexList, int Numvertice, int NumEdges, int MaxVertices, int MaxNumEdges){
    formalGraph->VertexList = VertexList;
    formalGraph->NumVertices = Numvertice;
    formalGraph->NumEdges = NumEdges;
    formalGraph->MaxNumEdges = MaxNumEdges;
    formalGraph->MaxVertices = MaxVertices;
}

//对图进行深度优先遍历
void DFS(Graph * g){
    bool visited[DefaultVertexNumbers];
    for(int i = 0; i<g->NumVertices; i++){
        visited[i] = false;
    }
    for(int i = 0;i<g->NumVertices; i++){
        printf("fist ——>%d\n",i+1);
        if(!visited[i]){
            dfs(g, i ,visited);
        }
    }
}
//对图中由顶点v出发进行深度优先遍历
void dfs(Graph * g, int v, bool visited[]){
    int u;
    printf("the v is %d\t",v+1);
    printf("visited vertex:%c \n",ReturnValue(g,v));
    visited[v] = true;
    u = ReturnFirstNeighbor(g,v);
    while(u!=-1){
        if(!visited[u]){
            dfs(g,u,visited);
        }
        u = ReturnNextNeighbor(g,v,u);
    }

}

//返回图中顶点i的数据信息
VertexType ReturnValue(Graph * g, int i){
    if(i>=0 && i<g->NumVertices){
        return g->VertexList[i].data;
    }else{
        printf("graph.c [ReturnValue] Error!\n");
        exit(1);
    }
}

//返回图中与顶点v相关联的下一个顶点的编号
int ReturnFirstNeighbor(Graph * g, int v){
    Edge * e;
    if(v!=-1){
        e = g->VertexList[v].out;
        if(e!=NULL){
            return e->nextVertexNum;
        }
    }
}

//返回图中与顶点vi相关联的一条边(vi,vj)的下一条边的另一个顶点的编号
int ReturnNextNeighbor(Graph * g, int vi, int vj){
    Edge * e;
    if(vi!=-1){
        e = g->VertexList[vi].out;
        while(e!=NULL){
            if(e->nextVertexNum  == vj && e->next !=NULL){
                return e->next->nextVertexNum;
            }else{
                e=e->next;
            }
        }
    }
    return -1;
}