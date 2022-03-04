#include <stdio.h>
#include <stdlib.h>
//求前n个整数的和
int Sum(int n){
    if(n == 1){
        return 1;
    }else{
        return n+Sum(n-1);
    }
}
//阶层
int Factorial(int n){
    if(n == 1){
        return 1;
    }else{
        return n*Factorial(n-1);
    }
}

//汉诺塔问题，将n个盘子从a移到c
void Hanoi(int n,char a,char b,char c){
    if(n == 1){
        //只有一个盘子的情况
        printf("%c to %c\n",a,c);
    }else{
        Hanoi(n-1,a,c,b);
        printf("%c to %c\n",a,c);
        Hanoi(n-1,b,a,c);
    }
}

//n个月后有多少只兔子
int rabbit(int n){
    if(n == 1 || n == 2){
        return 1;
    }else{
        return rabbit(n-1)+rabbit(n-2);
    }
}
int main(int argc, char const *argv[])
{
    printf("Sum(100): %d\n",Sum(100));
    printf("Factorial(10): %d\n",Factorial(10));
    Hanoi(3,'A','B','C');
    printf("%d\n",rabbit(5));
    return 0;
}
