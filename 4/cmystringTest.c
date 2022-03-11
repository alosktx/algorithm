#include <stdio.h>
#include <stdlib.h>
#include "cmystring.h"
#define LENGTH 100
int main(int argc, char const *argv[])
{
    CMyString * CS = (CMyString*)malloc(sizeof(CMyString));
    char s[LENGTH] = "aabaaf";//abcaba 2 abcabca -1 abcabcd 3 abcabcc 3 abaabaa 1 accabacaaccab
    InitCMyString(CS,s);
    int next[LENGTH];
    GenKMPNext(next,CS);
    for(int i =0;i<CS->length;i++){
        printf("%d\t",i);
    }
    printf("\n");
    for(int i =0;i<CS->length;i++){
        printf("%c\t",CS->str[i]);
    }
    printf("\n");
    for(int i =0;i<CS->length;i++){
        printf("%d\t",next[i]);
    }

    CMyString * TCS = (CMyString*)malloc(sizeof(CMyString));
    char tc[LENGTH] = "aabaacshjjfssaabfchjsssaabaaraataabaaf";
    InitCMyString(TCS,tc);
    int pos = FindInCMyString(TCS,CS);
    printf("\npos: %d\n",pos);

    printf("\n");
    return 0;
}
