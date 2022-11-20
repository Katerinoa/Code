#include <bits/stdc++.h>
using namespace std;
typedef int QElemType;
//���ڵ㶨��
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QuenePtr;
//�����ж���
typedef struct
{
    QuenePtr front; //��ͷָ��
    QuenePtr rear;  //��βָ��
} LinkQuene;
//�����г�ʼ��
bool InitQuene(LinkQuene &Q)
{
    Q.front = Q.rear = (QuenePtr)malloc(sizeof(QNode));
    if (!Q.front)
        return false;
    Q.front->next = NULL;
    return true;
}
//���ٶ���
bool destroyQuene(LinkQuene &Q)
{
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return true;
}
//�ж϶����Ƿ�Ϊ��
bool IsEmpty(LinkQuene Q)
{
    return Q.rear == Q.front;
}
//����еĶ�ͷԪ��
QElemType GetHead(LinkQuene Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return false;
    e = Q.front->data;
    return true;
}
//���
bool EnQuene(LinkQuene &Q, QElemType e)
{
    QNode *p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}
//����
bool DeQuene(LinkQuene &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return false;
    QNode *p = Q.front->next;
    Q.front->next = Q.front->next->next;
    e = p->data;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    return true;
}