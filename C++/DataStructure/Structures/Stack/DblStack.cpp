#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;
typedef int SElemType;

//双栈的定义
typedef struct
{
    int top[2], bot[2];
    SElemType *V;
    int stacksize;
} DblStack;

//双栈的初始化
bool initStack(DblStack &S)
{
    S.V = new SElemType[MAXSIZE];
    if (!S.V)
        return false;
    S.stacksize = MAXSIZE;
    S.top[0] = S.bot[0] = -1;
    S.top[1] = S.bot[1] = S.stacksize;
}
//判断栈是否为空
bool IsEmpty(DblStack S, int i)
{
    return S.top[i] == S.bot[i];
}
//判断栈是否为满
bool IsFull(DblStack S)
{
    if (S.top[0] + 1 == S.top[1])
        return true;
    return false;
}
//入栈
bool DblPush(DblStack &S, SElemType e, int i)
{
    if (IsFull(S))
        return false;
    switch (i)
    {
    case 0:
        S.V[++S.top[i]] = e;
        break;
    case 1:
        S.V[--S.top[i]] = e;
        break;
    default:
        return false;
        break;
    }
    return true;
}
//出栈
bool DblPop(DblStack S, SElemType &e, int i)
{
    if (IsEmpty(S, i))
        return false;
    switch (i)
    {
    case 0:
        e = S.V[S.top[i]++];
        break;
    case 1:
        e = S.V[S.top[i]--];
        break;
    default:
        return false;
        break;
    }
    return true;
}