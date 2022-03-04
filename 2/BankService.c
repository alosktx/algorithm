//不加这个头文件 time() 会报错
#include<time.h>
#include "BankService.h"

//事件初始化
void InitEvent(Event *E,int time, EventType etype, int customerID, int tellerID, int waittime, int servicetime){
    E->time = time;
    E->etype = etype;
    E->customerID = customerID;
    E->tellerID = tellerID;
    E->waittime = waittime;
    E->servicetime = servicetime;
}

void InitSimulation(Simulation * S){
    Event *firstevent = (Event*)malloc(sizeof(Event));
    S->nextCustomer = 1;

    for(int i = 1; i<=10; i++){
        S->tstat[i].finishService = 0;
        S->tstat[i].totalCustomerCount = 0;
        S->tstat[i].totalCustomerWait = 0;
        S->tstat[i].totalService = 0;
    }
    //输入事件模拟相关数据
    printf("Enter the simulation time in minutes: ");
    scanf("%d",&S->simulationLength);
    printf("Enter the number of bank teller: ");
    scanf("%d",&S->numTeller);
    printf("Enter the range of arrival times in minutes(low->high): ");
    scanf("%d%d",&S->arrivalLow,&S->arrivelHigh);
    printf("Enter the range of service times in minutes(low->high): ");
    scanf("%d%d",&S->serviceLow,&S->serviceHigh);

    //生成第一个到达事件并加入事件优先级队列
    InitEvent(firstevent,0,arrival,1,0,0,0);
    InitPQueue(&(S->pq));
    PQInsert(&(S->pq),*firstevent);

    // for(int k = 0;k<5;k++){
    //     InitEvent(firstevent,k+1,arrival,k+2,0,0,0);
    //     PQInsert(&(S->pq),*firstevent);
    //     InitEvent(firstevent,10-k,arrival,10-k,0,0,0);
    //     PQInsert(&(S->pq),*firstevent);
    // }
    // PrintPQueue(&(S->pq));
    
    // if(PQFull(&(S->pq))){
    //     printf("[InitSimulation] The Simlation queue is full\n");
    // }
    // if(!PQEmpty(&(S->pq))){
    //     printf("[InitSimulation] The Simlation queue is not empty！！！\n");
    // }else{
    //     printf("[InitSimulation] The Simlation queue is empty\n");
    // }

    // Event *currentevent = (Event*)malloc(sizeof(Event));

    // for(int k = 0; k<11 ; k++){
    //     *currentevent = PQDelete(&(S->pq));
    //     printf(">>>>>>>>>The delete event time is:%d cusID: %d\n",currentevent->time,currentevent->customerID);
    //     PrintPQueue(&(S->pq));
    // }

    // if(!PQEmpty(&(S->pq))){
    //     printf("[InitSimulation] The Simlation queue is not empty！！！\n");
    // }else{
    //     printf("[InitSimulation] The Simlation queue is empty\n");
    // }
}

int NextArrivalTime(Simulation * S){
    return S->arrivalLow + rand()%(S->arrivelHigh - S->arrivalLow + 1); 
}

int GetServiceTime(Simulation * S){
    return S->serviceLow + rand()%(S->serviceHigh - S->serviceLow + 1);
}

int NextAvailableTeller(Simulation * S){
    //找最小的空闲时刻预告，如果有一样小的，则随机从其中选取一个
    int minFinishService = S->tstat[1].finishService;
    int minIndex = 1;
    int minNum[1000];
    int minNumCount = 1;
    minNum[0] = 1;

    for(int i = 2;i<=S->numTeller;i++){
        if(minFinishService > S->tstat[i].finishService){
            minFinishService = S->tstat[i].finishService;
            minNum[0] = i;
            minNumCount = 1;//
        }else{
            if(minFinishService == S->tstat[i].finishService){
                minNum[minNumCount++] = i;//将最小的空闲时刻的柜员编号加入数组里面
            }
        }
    }
    //从最小空闲时刻的柜员编号的数组里面，随机选取一个柜员编号
    minIndex = minNum[rand()%minNumCount];
    return minIndex;  
}

void RunSimulation(Simulation * S){
    Event *currentevent = (Event*)malloc(sizeof(Event));
    Event *newevent = (Event*)malloc(sizeof(Event));
    int nexttime, tellerID, servicetime, waittime;
    printf("\n*******************RunSimulation***********************\n");

    //事件队列非空，则弹出事件(循环)
    while( !PQEmpty( &(S->pq) ) ){
        // PrintPQueue(&(S->pq));//************************
        *currentevent = PQDelete(&(S->pq));
        if(currentevent->etype == arrival){
        //处理到达事件
            nexttime = currentevent->time + NextArrivalTime(S);
            if(nexttime > S->simulationLength){
            //如果所生成的下一个客户到达时刻在下班时刻之后，则不处理到达事件
                continue;
            }else{
            //否则生成下一客户到达事件并加入事件优先级队列
                S->nextCustomer++;
                InitEvent(newevent, nexttime, arrival, S->nextCustomer, 0, 0, 0);
                PQInsert(&(S->pq), *newevent);
            }

            printf("Time: %2d\tarrival of customer %d\n", currentevent->time, currentevent->customerID);


            //生成到达事件的离开事件
            servicetime = GetServiceTime(S);
            tellerID = NextAvailableTeller(S);
            if(S->tstat[tellerID].finishService == 0){
                S->tstat[tellerID].finishService = currentevent->time;
            }
            //计算等待时间
            waittime = S->tstat[tellerID].finishService - currentevent->time;
            //修改出纳窗口相关信息
            S->tstat[tellerID].totalCustomerWait+=waittime;
            S->tstat[tellerID].totalCustomerCount++;
            S->tstat[tellerID].totalService+=servicetime;
            S->tstat[tellerID].finishService+=servicetime;

            //生成离开事件并加入优先级队列    
            InitEvent(newevent, S->tstat[tellerID].finishService, departure, currentevent->customerID, tellerID, waittime, servicetime);
            PQInsert(&(S->pq),*newevent);

        }else{
            //处理离开事件  
            printf("Time: %2d\tdepart  of customer %d \t waittime: %d \t servicetime: %d \t Teller: %d\n", currentevent->time, currentevent->customerID, currentevent->waittime, currentevent->servicetime, currentevent->tellerID);
            // printf("*****Teller %d\tWait %d\tService %d\n",currentevent->tellerID, currentevent->waittime, currentevent->servicetime);//打印这个GetServiceTime(S)有什么用
            tellerID = currentevent->tellerID;

            //如果窗口在处理离开事件后空闲，则修改该出纳窗口的空闲时刻预告
            if(currentevent->time == S->tstat[tellerID].finishService){
                S->tstat[tellerID].finishService = 0;
            }
        }
    }
    //修改总的服务时间
    S->simulationLength = (currentevent->time <= S->simulationLength)?S->simulationLength:currentevent->time;
}

void PrintSimulationResults(Simulation * S){
    int cumCustomers = 0;
    int cumWait = 0;
    int avgCustWait;
    int tellerWorkPercent;
    float tellerWork;

    for(int i = 0;i<=S->numTeller;i++){
        cumCustomers += S->tstat[i].totalCustomerCount;
        cumWait += S->tstat[i].totalCustomerWait;
    }

    printf("\n*****************Simulation Summary*************************\n");
    printf("Simulation of %d minutes\n",S->simulationLength);
    printf("\tNo. of Customers: %d\n",cumCustomers);
    printf("\tAverage Cutomer Wait:");

    avgCustWait = (int)((float)cumWait/cumCustomers + 0.5);
    printf("%d minutes \n", avgCustWait);

    for(int i = 1;i<=S->numTeller;i++){
        printf("\tTeller %d \tWorking ",i);
        tellerWork = (float)(S->tstat[i].totalService)/S->simulationLength;
        tellerWorkPercent = (int)(tellerWork*100.0 + 0.5);
        printf("%d\n",tellerWorkPercent);
    }
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
    Simulation * S = (Simulation*)malloc(sizeof(Simulation));
    srand(time(NULL));  
    InitSimulation(S);
    RunSimulation(S);
    PrintSimulationResults(S);

    return 0;
}