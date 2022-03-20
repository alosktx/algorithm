#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include"dijkstra.h"

int adj[VERTEXNUMBERS][VERTEXNUMBERS] = { 
        0,      13,     11,     16,     M,      M,
        13,     0,      14,     M,      13,     M,
        11,     14,     0,      21,     20,     M,
        16,     M,      21,     0,      16,     12,
        M,      13,     20,     16,     0,      16,
        M,      M,      M,      12,     16,     0
    };
Path dist[VERTEXNUMBERS]; 

//源点在顶点集中的序号为k
void DIJ(int k){
    //A B两组初始化
    for(int i = 0;i<VERTEXNUMBERS;i++){
        dist[i].length = adj[k][i];
        if(dist[i].length!=32767)
            dist[i].pre = k;
        else
            dist[i].pre = -1;
    }
    adj[k][k] = 1;

    printf("initial:\n");
    for(int i =0; i<VERTEXNUMBERS; i++){
        printf("dist[%d]:%d %d\n", i,dist[i].length, dist[i].pre);
    }
    printf("\n");

    //按最短路径递增的顺序依次将B组中的顶点加入A组
    for(;;){
        int u = -1;
        int min = 32767;
        for(int i  = 0; i<VERTEXNUMBERS; i++){
            if(adj[i][i] == 0 && dist[i].length < min){
                u = i;
                min = dist[i].length;
            }
        }

        printf("最小的dist[i].length序号U: %d\n",u);
        for(int i =0; i<VERTEXNUMBERS; i++){
            printf("dist[%d]:%d %d\n", i,dist[i].length, dist[i].pre);
        }
        printf("\n");

        if(u == -1){
            break;
        }

        adj[u][u] = 1;
        //修改B中顶点的距离值
        for(int i = 0;i<VERTEXNUMBERS;i++){
            if( adj[i][i] == 0 && dist[i].length > (dist[u].length + adj[u][i]) ){
                printf("满足条件的i:%d\n",i);
                dist[i].length = dist[u].length + adj[u][i];
                dist[i].pre = u;
            }
        }
        printf("修改完后：\n");
        for(int i =0; i<VERTEXNUMBERS; i++){
            printf("dist[%d]:%d %d\n", i,dist[i].length, dist[i].pre);
        }
        printf("\n Next*************************************\n");
    }

    printf("last:\n");
    for(int i =0; i<VERTEXNUMBERS; i++){
        printf("dist[%d]:%d %d\n", i+1, dist[i].length, dist[i].pre);
    }
    printf("\n");
}

int path [VERTEXNUMBERS][VERTEXNUMBERS];
int D[VERTEXNUMBERS][VERTEXNUMBERS];
//Floyd算法求网络中任意两顶点间的最短路径

void printPath(){
    printf("path\n");
    for(int i = 0; i<VERTEXNUMBERS; i++){
        for(int j =0; j<VERTEXNUMBERS; j++){
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printD(){
    printf("D\n");
    for(int i = 0; i<VERTEXNUMBERS; i++){
        for(int j =0; j<VERTEXNUMBERS; j++){
            if(D[i][j] != M){
                printf("%d\t",D[i][j]);
            }else{
                printf("M\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void Floyd(){
    int max = 32767;
    //D path初始化
    for(int i = 0; i<VERTEXNUMBERS; i++){
        for(int j = 0; j<VERTEXNUMBERS; j++){
            if(adj[i][j]!=max){
                path[i][j] = i+1;
            }else{
                path[i][j] = 0;
            }
            D[i][j] = adj[i][j];
        }
    }

    printPath();
    printD();

    //VERTEXNUMBERS次 迭代产生矩阵序列
    for(int k = 0; k<VERTEXNUMBERS; k++){
        for(int i = 0; i<VERTEXNUMBERS; i++){
            for(int j = 0; j<VERTEXNUMBERS; j++){
                if( D[i][j] > (D[i][k] + D[k][j]) ){
                    D[i][j] = (D[i][k] + D[k][j]);
                    path[i][j] = path[k][j];
                }
            }
        }
        printPath();
        printD();

    }
}