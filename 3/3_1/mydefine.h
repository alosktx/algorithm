#pragma once
//打印作业结构
struct printJob{
    //待打印作业名
    char filename[31];
    //总打印页数
    int totalpages;
    //已打印页数
    int printedpages;
};
typedef struct printJob PrintJob;

#ifndef PRINTJOB
    typedef int ElementType;
#else
    typedef PrintJob ElementType;
#endif