#pragma once
#include "linkedlist.h"
#include "mydefine.h"
// #include "mydefine.h"
//每分钟打印页数
#define PRINTSPEED 50
//更新打印队列的最小时间间隔
#define DELTATIME 10
// #define PRINTJOB
//模拟打印缓冲池
struct spooler{
    //存放打印作业及状态的队列
    LinkedList * jobList;
    //打印作业的状态时间
    time_t lasttime;
};
typedef struct spooler Spooler;
//初始化打印缓冲池
void InitSpooler(Spooler *);
//更新打印缓冲池
void UpdateSpooler(Spooler *, int);
//加入打印作业
void AddJob(Spooler *,ElementType *);
//显示打印缓冲池的打印作业
void ListJob(Spooler *);
//求打印缓冲池的作业数
int NumberOfJobs(Spooler *);

