#include <bits/stdc++.h>
using namespace std;
typedef int QElemType;
//链节点定义
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QuenePtr;
//链队列定义
typedef struct
{
    QuenePtr front; //队头指针
    QuenePtr rear;  //队尾指针
} LinkQuene;
//链队列初始化
bool InitQuene(LinkQuene &Q)
{
    Q.front = Q.rear = (QuenePtr)malloc(sizeof(QNode));
    if (!Q.front)
        return false;
    Q.front->next = NULL;
    return true;
}
//销毁队列
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
//判断队列是否为空
bool IsEmpty(LinkQuene Q)
{
    return Q.rear == Q.front;
}
//求队列的队头元素
QElemType GetHead(LinkQuene Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return false;
    e = Q.front->data;
    return true;
}
//入队
bool EnQuene(LinkQuene &Q, QElemType e)
{
    QNode *p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}
//出队
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