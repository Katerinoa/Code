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
void ShortCut::EnterCut(Cars *car)
{
    QNode *p = new QNode;
    p->elem = car;
    p->next = NULL;
    rear->next = p;
    rear = p;
}
//驶出便道
Cars *ShortCut::LeaveCut()
{
    Cars *car;
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
//获得牌号车辆的位置,如果未查找到返回-1
int ShortCut::getCarIndex(char *targetLicense)
{
    if (QueneEmpty())
        return -1;
    int index = 0;
    QNode *p = front->next;
    while (p != NULL)
    {
        if (strcmp(p->elem->getLicense(), targetLicense) == 0)
            return index;
        p = p->next;
        index++;
    }
    return -1;
}
//获得序号车辆
Cars *ShortCut::getCar(char *targetLicense)
{
    if (QueneEmpty())
        return NULL;
    QNode *p = front->next;
    while (p != NULL)
    {
        if (strcmp(p->elem->getLicense(), targetLicense) == 0)
            return p->elem;
        p = p->next;
    }
    return NULL;
}
//输出队列所有元素
void ShortCut::printQuene()
{
    int index = 1;
    QNode *p = front->next;
    while (p != NULL)
    {
        cout << index << "号位: " << endl;
        p->elem->printCars();
        p = p->next;
        index++;
    }
}