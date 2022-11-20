#include "CardsQuene.h"
#include <bits/stdc++.h>
//����,������ӳɹ����س���Ԫ����ֵ�����򷵻�0
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
//����,�������ռ�ɹ�����true�����򷵻�false
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
//��ʼ������,�������ռ�ɹ�����true�����򷵻�false
bool initQuene(CQuene &Q)
{
    Q.front = Q.rear = new QNode;
    if (!Q.front)
        return false;
    Q.front->next = NULL;
    return true;
}
//�ж϶��п�
bool QueneEmpty(CQuene& Q)
{
    if(Q.front == Q.rear)
        return true;
    return false;
}
//����Ԫ�ؼ���
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