#pragma once
#include<stdio.h>
#include<stdlib.h>

enum eventType {arrival, departure};
typedef enum eventType EventType;

/*出纳窗口信息*/
struct tellerStatus
{
    /*空闲时刻预告*/
    int finishService;      
    /*服务过的客户总数*/
    int totalCustomerCount; 
    /*客户总的等待时间*/
    int totalCustomerWait;  
    /*总的服务时间*/
    int totalService;       
};
typedef struct tellerStatus TellerStatus;

//事件，客户数据
struct event{
    //事件发生时间，以分钟为单位，客户到达/离开的时刻，从模拟开始运行起计算
    int time;
    //事件类型(到达/离开)
    EventType etype;
    //客户编号
    int customerID;
    //客户选择服务的窗口编号
    int tellerID;
    //客户必须等待的时间
    int waittime;
    //客户需要服务的时间
    int servicetime;
};
typedef struct event Event;
