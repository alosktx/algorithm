#include<curses.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"kbhit.h"
#include "spooler.h"
// #include<conio.h>

//10秒未输入自动输入
#define WAITTIME 10
typedef PrintJob ElementType;
int main(int argc, char const *argv[])
{
    Spooler * SP = (Spooler*)malloc(sizeof(Spooler));
    PrintJob * job = (PrintJob*)malloc(sizeof(PrintJob));
    char response='L';
    InitSpooler(SP);
    for(;response!='Q';){
        time_t ctime;
        time_t btime;
        time(&btime);
        printf("\nPlease Enter letter: Add(A/a) List(L/l) Number(N/n) Quit(Q/q)[ Don't need enter ] ===> \n");
        do{
            time(&ctime);       
            if(difftime(ctime,btime)>=WAITTIME)
                break;
        }while(!kbhit());
        response = (kbhit())? toupper(getchar()) : 'L';

        // response = toupper(getchar());
        // scanf("%c",&response);
        // response=toupper(response);
        switch (response)
        {
        case 'A':
            printf("Please enter the filename: ");
            //&必要的
            scanf("%s",&(job->filename));
            printf("Please enter the totalpages: ");
            scanf("%d",&(job->totalpages));
            getchar();
            AddJob(SP,job);
            break;
        case 'L':
            ListJob(SP);
            break;
        case 'N':
            NumberOfJobs(SP);
            break;
        case 'Q':
            break;
        default:
            printf("Please enter invalid letter!\n");
            break;
        }
    }
    return 0;
}
