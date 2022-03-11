#define MAX_STRING_SIZE 1024
struct cMyString{
    //串的实际长度
    int length;
    //串的存储空间，包括一个附加的结束字符
    char str[MAX_STRING_SIZE+1];
};
typedef struct cMyString CMyString;

//初始化函数，构造一个字符串指针所指的串,串的内容为s
void InitCMyString(CMyString *, char * s);
//将字符串s附加到本字符串之后
void Concatenate(CMyString *, CMyString * s);
//将字符串s插入到本字符串pos所指向的位置
void InsertS(CMyString *, int pos, CMyString * s);
//删除本字符串从pos位置起的连续len个字符
void DeleteS(CMyString *, int pos, int len);
//提取本字符串从pos位置起的len个字符，所组成的子字符串
CMyString SubString(CMyString *, int pos, int len);
//获取本字符串
char * GetString(CMyString *);
//在本字符串中查找s字符串首次出现的位置，如果本字符串不包含s则返回0
int FindInCMyString(CMyString *,CMyString * s);
//KMP next数组计算方法
void GenKMPNext(int * next, CMyString * s);