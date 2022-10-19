#include "ShortCut.h"

//构造函数
ShortCut::ShortCut()
{
    front = rear = new QNode;
    front->next = NULL;
}
//析构函数
ShortCut::~ShortCut()
{
    while (front)
    {
        rear = front->next;
        delete front;
        front = rear;
    }
}
//判断队列是否为空
bool ShortCut::QueneEmpty()
{
    return front == rear;
}
//驶入便道
void ShortCut::EnterCut(Cars* car)
{
    QNode *p = new QNode;
    p->elem = car;
    p->next = NULL;
    rear->next = p;
    rear = p;
}
//驶出便道
Cars* ShortCut::LeaveCut()
{
    Cars* car;
    QNode *p = front->next;
    car = p->elem;
    front->next = p->next;
    if (rear == p)
        rear = front;
    delete p;
    return car;
}
//计算便道中车辆数
int ShortCut::countCars()
{
    QNode *p = front->next;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}