#include "ShortCut.h"

//���캯��
ShortCut::ShortCut()
{
    front = rear = new QNode;
    front->next = NULL;
}
//��������
ShortCut::~ShortCut()
{
    while (front)
    {
        rear = front->next;
        delete front;
        front = rear;
    }
}
//�ж϶����Ƿ�Ϊ��
bool ShortCut::QueneEmpty()
{
    return front == rear;
}
//ʻ����
void ShortCut::EnterCut(Cars* car)
{
    QNode *p = new QNode;
    p->elem = car;
    p->next = NULL;
    rear->next = p;
    rear = p;
}
//ʻ�����
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
//�������г�����
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