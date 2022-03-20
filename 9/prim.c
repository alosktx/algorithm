#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include"prim.h"
#define M 32767

int adj[VERTEXNUMBERS][VERTEXNUMBERS] = { 
        M,      13,     11,     16,     M,      M,
        13,     M,      14,     M,      13,     M,
        11,     14,     M,      21,     20,     M,
        16,     M,      21,     M,      16,     12,
        M,      13,     20,     16,     M,      16,
        M,      M,      M,      12,     16,     M
    };

void PrimForMST(int vertexNumbers){
    Edge MST[VERTEXNUMBERS-1];
    //初始化最小生成树，顶点编号1,2,3，....，n
    for(int n=1; n<vertexNumbers; n++){
        //vi设成1,表示从1号结点开始访问
        MST[n-1].vi = 1;
        MST[n-1].vj = n+1;
        MST[n-1].weight = adj[0][n];
    }
    //此时MST表示从1结点分别访问2,3,4,...n 结点所需要的全值
    for(int k =0; k<vertexNumbers-1;k++){
        printf("[%d] [%d] = %d\n",MST[k].vi, MST[k].vj, MST[k].weight);
    }
    printf("\n");

    int minN;
    //求 vertexNumbers-1 条最小代价生成树的边
    for(int k =0; k<vertexNumbers-1; k++){
        int minWeight = 32767;
        //从已确定的集合中，访问暂未访问的结点，选最近的一条路
        //即从备选边集中选择权值最小的一条边
        for(int j = k; j<vertexNumbers-1; j++){
            if(MST[j].weight < minWeight){
                minWeight = MST[j].weight;
                minN = j;
            }
        }
        //选到权值最小的边后，移到前面，表示接下来要访问这条边
        Edge tempE = MST[minN];
        MST[minN] = MST[k];
        MST[k] = tempE;

        //newN为新加入最小生成树的顶点号
        printf("\nThe Next Access!****************************\n");
        int newN = MST[k].vj;
        //修改备选边集
        for(int j = k+1; j<vertexNumbers-1; j++){
            //取新加入的顶点号（newN） 与 未访问到的顶点（MST[j].vj） 的权值(tempW)， 与被选集已有的 访问到对应未访问结点（MST[j].vj）的权值( MST[j].weight )作对比，
            //再决定是否修改此时备选集访问到未访问结点的边，其为具有最小权值的边
            int tempW = adj[ newN - 1 ][ MST[j].vj - 1 ];
            printf("newNum     [%d] [%d] = %d\n", newN, MST[j].vj, tempW);

            if(tempW < MST[j].weight ){
                MST[j].weight = tempW;
                MST[j].vi = newN;
            }
            
            for(int i =0; i<vertexNumbers-1;i++){
                if(i>=k+1){
                    printf("Not Access ");
                }else{
                    printf("           ");
                }
                printf("[%d] [%d] = %d\n",MST[i].vi, MST[i].vj, MST[i].weight);
            }
            printf("\n");
        }
    }

    for(int k =0; k<vertexNumbers-1;k++){
        printf("[%d] [%d] = %d\n",MST[k].vi, MST[k].vj, MST[k].weight);
    }

}