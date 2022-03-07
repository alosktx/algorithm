#include <stdio.h> 
#include <termios.h> 
#include <unistd.h> 
#include <fcntl.h> 

// #include<time.h>
// #include<ctype.h>
// #define WAITTIME 20
 
int kbhit(void) 
{ 
    struct termios oldt, newt; 
    int ch; 
    int oldf; 
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt; 
    newt.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0); 
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); 
    ch = getchar(); 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 
    fcntl(STDIN_FILENO, F_SETFL, oldf); 
    if(ch != EOF) { 
        ungetc(ch, stdin); 
        return 1; 
    } 
    return 0; 
} 
 
// int main(void) 
// { 
//     // while(!kbhit()) puts("Press a key!"); 
//     // printf("You pressed '%c'!/n", getchar()); 
//     char response='L';
//     time_t ctime;
//     time_t btime;
//     time(&btime);
//     printf("\nPlease Enter letter: Add(A) List(L) Number(N) Quit(Q): \n");
//     do{
//         time(&ctime);
//         // printf("%f",difftime(ctime,btime));       
//         if(difftime(ctime,btime)>=WAITTIME)
//             break;
//     }while(!kbhit());
//     response = (kbhit())? toupper(getchar()) : 'L';
//     printf("%c\n",response);
//     return 0; 
// } 