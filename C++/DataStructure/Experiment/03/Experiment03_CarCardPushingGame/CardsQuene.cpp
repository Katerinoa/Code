#include "CardsQuene.h"
#include <bits/stdc++.h>
//出牌,如果出队成功返回出队元素数值，否则返回0
char PlayCards(CQuene &Q)
{
    if (Q.front == Q.rear)
        return 0;
    char cardValue = 0;
    QNode *p = Q.front->next;
    cardValue = p->elem;
    Q.front->next = p->next;
    if (p == Q.rear)
        Q.rear = Q.front;
    delete p;
    return cardValue;
}
//拿牌,如果分配空间成功返回true，否则返回false
bool GetCards(CQuene &Q, char cardValue)
{
    QNode *p = new QNode;
    if (!p)
        return false;
    p->elem = cardValue;
    p->next = NULL;

    Q.rear->next = p;
    Q.rear = p;
    return true;
}
//初始化队列,如果分配空间成功返回true，否则返回false
bool initQuene(CQuene &Q)
{
    Q.front = Q.rear = new QNode;
    if (!Q.front)
        return false;
    Q.front->next = NULL;
    return true;
}
//判断队列空
bool QueneEmpty(CQuene& Q)
{
    if(Q.front == Q.rear)
        return true;
    return false;
}
//队列元素计数
int countCards(CQuene & Q)
{
    QNode *p = Q.front;
    int count = -1;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}