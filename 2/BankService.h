#include"BankEvent.h"
#include "Bankqueue.h"
// typedef Event DataType;

//模拟结构数据
struct simulation{
    /*模拟时间长度*/
    int simulationLength;       
    /*出纳窗口数*/
    int numTeller;              
    /*下一个客户编号*/
    int nextCustomer;           
    /*下一个客户达到的时间区间*/
    int arrivalLow;       
    int arrivelHigh;            
    /*客户需要服务的时间区间*/
    int serviceLow; 
    int serviceHigh;    
    /*出纳窗口信息*/        
    TellerStatus tstat[11];    
    /*优先级队列*/
    PQueue pq;                  
};
typedef struct simulation Simulation;

//事件驱动模拟初始化
void InitSimulation(Simulation * ); 
//计算下一客户达到时间
int NextArrivalTime(Simulation * );
//计算客户的服务时间
int GetServiceTime(Simulation * );
//计算下一个可供服务的出纳窗口号
int NextAvailableTeller(Simulation * );
//运行事件驱动模拟
void RunSimulation(Simulation * );
//输出模拟结果
void PrintSimulationResults(Simulation * );