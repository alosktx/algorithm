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
long long Factorial(int n){
    if(n<0){
        printf("[Factorial] error: %d<0\n",n);
        return -1;
    }
    if(n == 1 || n==0){
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
//排列
long long Anm(int n,int m){    
    long long result = 1;
    if(n<m || n<0 || m<0){
        printf("[Anm] error: n < m or n<0 or m<0\n");
        return 0;
    }
    while(m--){
        result*=n--;
    }
    return result;
}

//组合
long long Cnm(int n, int m){
    return Anm(n,m)/Factorial(m);
}

int main(int argc, char const *argv[])
{
    // printf("Sum(100): %d\n",Sum(100));
    {
        int n,m;
        printf("enter n m:");
        scanf("%d %d",&n,&m);
        printf("Factorial(%d): %lld \t Factorial(%d): %lld\n",n,Factorial(n),m,Factorial(m));
        printf("C(%d,%d): %lld\n",n,m,Cnm(n,m));
        printf("A(%d,%d): %lld\n",n,m,Anm(n,m));
    }
    
    // Hanoi(3,'A','B','C');
    // printf("%d\n",rabbit(5));

    // {
    //     int m, n, temp, i;
    //     printf("Input m & n:");
    //     scanf("%d%d", &m, &n);
    //     if(m<n)  /*比较大小，使得m中存储大数，n中存储小数*/
    //     { /*交换m和n的值*/
    //         temp=m;
    //         m=n;
    //         n=temp;
    //     }
    //     for(i=n; i>0; i--)  /*按照从大到小的顺序寻找满足条件的自然数*/
    //         if(m%i==0 && n%i==0)
    //         {/*输出满足条件的自然数并结束循环*/
    //             printf("The GCD of %d and %d is: %d\n", m, n, i);
    //             break;
    //         }
    // }
    
    return 0;
}
