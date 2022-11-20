#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;
typedef int QElemType;

//顺序栈的定义
typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQuene;

//顺序栈的初始化
bool InitQuene(SqQuene &Q)
{
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        return false;
    Q.front = Q.rear = 0;
    return true;
}

//求循环队列的长度
int QueneLength(SqQuene Q)
{
    return (Q.front - Q.rear + MAXSIZE) % MAXSIZE;
}

//入队
bool EnQuene(SqQuene &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return false;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

//出队
bool DeQuene(SqQuene &Q, QElemType &e)
{
    if (Q.rear == Q.front)
        return false;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}

//清空队列
void clearQuene(SqQuene &Q)
{
    Q.front = Q.rear = 0;
}

//销毁队列
void destroyQuene(SqQuene &Q)
{
    delete Q.base;
    Q.front = Q.rear = 0;
}