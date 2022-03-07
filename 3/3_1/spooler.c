#include<stdlib.h>
#include<stdio.h>
#include<time.h>
// #include<math.h>
#include "spooler.h"
#define WAITTINE 60

//初始化打印缓冲池
void InitSpooler(Spooler * SP){
    SP->jobList=(LinkedList*)malloc(sizeof(LinkedList));
    InitLinkedList(SP->jobList);
    time(&(SP->lasttime));
}
//更新打印缓冲池
void UpdateSpooler(Spooler * SP, int timedelay){
    ElementType job;
    int canpages;
    int willpages;
    canpages = timedelay*PRINTSPEED/60;
    SetPosition(SP->jobList,0);
    while(!IsEmpty(SP->jobList) && canpages > 0){
        job = GetData(SP->jobList);
        // willpages = min(job.totalpages-job.printedpages,canpages);
        willpages = (job.totalpages-job.printedpages)<canpages? (job.totalpages-job.printedpages) : canpages;
        canpages = canpages - willpages;
        if((job.printedpages+=willpages)>=job.totalpages){
            DeleteAt(SP->jobList);
        }else{
            SetData(SP->jobList,job);
        }
    }

}
//加入打印作业
void AddJob(Spooler * SP,ElementType * job){
    if(IsEmpty(SP->jobList))
        time(&(SP->lasttime));
    job->printedpages = 0;
    if(!IsEmpty(SP->jobList)){
        SetPosition(SP->jobList,(SP->jobList)->size-1);
    }
    //*job
    InsertIAfter(SP->jobList,*job);
}
//显示打印缓冲池的打印作业
void ListJob(Spooler * SP){
    ElementType job;
    time_t currenttime;
    //距离已过去的的时间（秒）
    int timedelay;
    if(difftime(time(&currenttime),SP->lasttime) >= DELTATIME){
        timedelay =(int)difftime(currenttime,SP->lasttime);
        UpdateSpooler(SP,timedelay);
        //重置当前打印池更新的时间点
        SP->lasttime = currenttime;
    }

    if(IsEmpty(SP->jobList)){
        printf("[ListJob] The spooler is empty!\n");
    }else{
        printf("[ListJob] The spooler is working!\n");
        for(SetPosition(SP->jobList,0); SP->jobList->position<=SP->jobList->size-1; NextINode(SP->jobList)){
            job = GetData(SP->jobList);
            printf("Job=%s\t",job.filename);
            printf("Totalpages=%d\t",job.totalpages);
            printf("Printedpages=%d\n",job.printedpages);
        }
    }
}
//求打印缓冲池的作业数
int NumberOfJobs(Spooler * SP){
    printf("[NumberOfJobs] Current spooler size = %d\n",(SP->jobList)->size);
    return (SP->jobList)->size;
}