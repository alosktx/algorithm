#include<stdio.h>
#include<stdlib.h>

struct rectangle
{
    float length;
    float width;
};
typedef struct rectangle Rectangle;

Rectangle* initialRect(float l,float w){
    Rectangle*temp = (Rectangle*)malloc(sizeof(Rectangle));
    temp->length = l;
    temp->width = w;
    return temp;
}

float calArea(struct rectangle rect[]){ //用引用作参数 & or 用指针作参数Rectangle *rect
    return rect->length*(rect->width);
}

float calPerimeter(Rectangle rect[]){
    return (rect->length+rect->width)*2;
}

int main(){
    float length,width;
    Rectangle *Pool;
    Rectangle *Pooldim;
    printf("please enter the length of pool:");
    scanf("%f", &length);// 加&
    printf("please enter the width of pool:");
    scanf("%f", &width);
    Pool = initialRect(length,width);
    Pooldim = initialRect(length+6,width+6);

    printf("1: %f\n",calPerimeter(Pooldim)*50);
    printf("2: %f\n",(calArea(Pooldim)-calArea(Pool))*30 );
    printf("3: %f\n",calPerimeter(Pooldim)*50 + (calArea(Pooldim)-calArea(Pool))*30 );
    return 0;
}
