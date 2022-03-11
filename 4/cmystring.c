#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "cmystring.h"
//初始化函数，构造一个字符串指针所指的串
void InitCMyString(CMyString * CS, char * s){
    //两个指向char类型的数组/指向char类型数组的指针
    char *p1, * p2;
    //数组的复制，指针从字符串首地址开始，逐步取值，结束条件是p2的值为空
    for(CS->length=0,p1=CS->str,p2=(char*)s; *p2; CS->length++){
        //取值 *(p++) 每次增加一个字节的地址
        *p1++=*p2++;
    }
    //字符串结尾用0来填充
    *p1 = 0;
}

//将字符串s附加到本字符串之后
void Concatenate(CMyString * CS, CMyString * s){
    if(CS->length+s->length<=MAX_STRING_SIZE){
        //将从以s->str 地址开始的连续 s->length+1 个存储空间（单个存储空间的大小，下面指的是一个字符所占的存储空间大小，即一个字节），包括了结束字符，
        //复制到以CS->str+CS->length地址开始的一片连续存储空间中，只覆盖结束字符
        memcpy(CS->str+CS->length, s->str, s->length+1);
        //修改原字符串长度
        CS->length+=s->length;
    }else{
        printf("error: cmystring.c [Concatenate] string length overflow!\n");
    }
}

//将字符串s插入到本字符串pos所指向的位置,与Concatenate 的不同在于插入位置的不同
void InsertS(CMyString * CS, int pos, CMyString * s){
    if(CS->length+s->length<=MAX_STRING_SIZE){
        //先将以 CS->str+pos 地址开始的连续 CS->length-pos+1 个存储空间（包括结束字符） 复制到后面去：CS->str+pos+s->length 开始的存储空间
        memcpy(CS->str+pos+s->length, CS->str+pos, CS->length-pos+1);
        //再将以 s->str 地址开始的连续 s->length 个存储空间（不包括结束字符） 复制到上面腾出来的位置： CS->str+pos 开始的存储空间
        memcpy(CS->str+pos, s->str, s->length);
        CS->length+=s->length;
    }else{
        printf("error: cmystring.c [InsertS] string length overflow！\n");
    }
}

//删除本字符串从pos位置起的连续len个字符
void DeleteS(CMyString * CS, int pos, int len){
    int rlen = len;
    //如果pos位置起的len个长度已经超出原字符之外
    if(pos+len > CS->length){
        //修正为 从pos 开始 到 CS->length 的长度
        rlen = CS->length - pos;
    }
    //相对于教材的写法更直观
    memcpy(CS->str+pos, CS->str+pos+rlen, CS->length - (pos + rlen) + 1 );
    CS->length -= rlen; 
}

//提取本字符串从pos位置起的len个字符，所组成的子字符串
CMyString SubString(CMyString * CS, int pos, int len){
    int rlen = len;
    if(pos + len > CS->length){
        rlen = CS->length - pos;
    }
    CMyString * subCSString = (CMyString*)malloc(sizeof(CMyString));
    memcpy(subCSString->str, CS->str+pos, rlen);
    //不要忘记设置length
    subCSString->length = rlen;
    //不要忘记设置结尾字符
    subCSString->str[subCSString->length] = 0;
    return (*subCSString);
}

//获取本字符串
char * GetString(CMyString * CS){
    char * tmpStr = (char*)malloc(sizeof(char)*(CS->length+1));
    memcpy(tmpStr, CS->str, CS->length+1);
    return tmpStr;
}

//在本字符串中查找s字符串首次出现的位置，如果本字符串不包含s则返回0
int FindInCMyString(CMyString * CS, CMyString * s){
    int i,j;
    int * next = (int*)malloc(sizeof(int)*s->length);

    GenKMPNext(next,s);
    for(i=0,j=0;i<s->length && j<CS->length;){
        if(s->str[i] == CS->str[j] ){
            i++;
            j++;
        }else if(next[i]>=0){
            i = next[i];
        }else{
            i=0;
            j++;
        }
    }
    if(i>=s->length){
        //此时j处于匹配的尾字符
        return j-s->length;
    }else{
        return -1;
    }
}

//KMP next数组计算方法
void GenKMPNext(int * next, CMyString * s){
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i < s->length-1){
        while(j>=0 && s->str[i]!=s->str[j]){
            j = next[j];
        }
        i++;
        j++;
        if(s->str[i] == s->str[j]){
            next[i] = next[j];
        }else {
            next[i] = j;
        }
    }
}