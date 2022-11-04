#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;
typedef int QElemType;

//˳��ջ�Ķ���
typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQuene;

//˳��ջ�ĳ�ʼ��
bool InitQuene(SqQuene &Q)
{
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        return false;
    Q.front = Q.rear = 0;
    return true;
}

//��ѭ�����еĳ���
int QueneLength(SqQuene Q)
{
    return (Q.front - Q.rear + MAXSIZE) % MAXSIZE;
}

//���
bool EnQuene(SqQuene &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return false;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

//����
bool DeQuene(SqQuene &Q, QElemType &e)
{
    if (Q.rear == Q.front)
        return false;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}

//��ն���
void clearQuene(SqQuene &Q)
{
    Q.front = Q.rear = 0;
}

//���ٶ���
void destroyQuene(SqQuene &Q)
{
    delete Q.base;
    Q.front = Q.rear = 0;
}