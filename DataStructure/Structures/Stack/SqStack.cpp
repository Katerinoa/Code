#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef int SElemType;
//顺序栈的定义
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

//顺序栈的初始化
bool initStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        return false;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return true;
}
//判断栈是否为空
bool StackEmpty(SqStack S)
{
    return S.base == S.top;
}
//求栈的长度
int StackLength(SqStack S)
{
    return S.top - S.base;
}
//清空栈
bool clearStack(SqStack S)
{
    if (S.base)
    {
        S.top = S.base;
        return true;
    }
    return false;
}
//销毁栈
bool destroyStack(SqStack S)
{
    if (S.base)
    {
        delete S.base;
        S.stacksize = 0;
        S.top = S.base = NULL;
        return true;
    }
    return false;
}
//入栈
bool Push(SqStack S, SElemType e)
{
    if (S.top - S.base == S.stacksize)
        return false;
    *S.top++ = e;
    return true;
}
//出栈
bool Pop(SqStack S, SElemType &e)
{
    if (S.top == S.base)
        return false;
    e = *--S.top;
    return true;
}
//取栈顶元素
bool getTop(SqStack S, SElemType &e)
{
    if (S.top == S.base)
        return false;
    e = *(S.top - 1);
    return true;
}