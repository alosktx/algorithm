#include<curses.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"kbhit.h"
#include "spooler.h"

// #include<conio.h>
#define WAITTIME 1000000
typedef PrintJob ElementType;
int main(int argc, char const *argv[])
{
    Spooler * SP = (Spooler*)malloc(sizeof(Spooler));
    PrintJob * job = (PrintJob*)malloc(sizeof(PrintJob));
    char response='L';
    InitSpooler(SP);
    for(;response!='Q';){
        // time_t ctime;
        // time_t btime;
        // time(&btime);
        printf("\nPlease Enter letter: Add(A) List(L) Number(N) Quit(Q) ===> \n");
        // do{
        //     time(&btime);       
        //     if(difftime(ctime,btime)>=WAITTIME)
        //         break;
        // }while(!kbhit());
        // response = (kbhit())? toupper(getchar()) : 'L';
        // if(kbhit()){
        //     while((response = getchar())!='\n');
        // }else{
        //     response = 'L';
        // }

        // response = toupper(getchar());
        scanf("%c",&response);
        response=toupper(response);
        switch (response)
        {
        // case 'a':
        case 'A':
            printf("Please enter the filename: ");
            //&必要的
            scanf("%s",&(job->filename));
            printf("Please enter the totalpages: ");
            scanf("%d",&(job->totalpages));
            AddJob(SP,job);
            break;
        // case 'l':
        case 'L':
            ListJob(SP);
            break;
        // case 'n':
        case 'N':
            NumberOfJobs(SP);
            break;
        // case 'q':
        case 'Q':
            break;
        default:
            // printf("Please enter invalid letter!\n");
            break;
        }
    }
    return 0;
}
