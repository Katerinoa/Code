#include "ParkingStack.h"

//���캯��
ParkingStack::ParkingStack(int Size)
{
    base = new Cars *[Size];
    top = base;
    this->stackSize = Size;
}
//��������
ParkingStack::~ParkingStack()
{
    if (base)
    {
        delete base;
        top = base = NULL;
        stackSize = 0;
    }
}
//��ǰͣ����
int ParkingStack::countCars() const
{
    return top - base;
}
//��ǰʣ�೵λ
int ParkingStack::countEmpty() const
{
    return stackSize - countCars();
}
//ջ�Ƿ�Ϊ��
bool ParkingStack::StackEmpty() const
{
    return base == top;
}
//ջ�Ƿ�Ϊ��
bool ParkingStack::StackFull() const
{
    return (top - base) == stackSize;
}
//���ջ
void ParkingStack::clearStack()
{
    if (base)
        delete base;
}
//��������ͣ����
void ParkingStack::EnterParking(Cars *car)
{
    if (StackFull())
        return;
    *top++ = car;
}
//�����뿪ͣ����
Cars *ParkingStack::LeaveParking()
{
    Cars *car = *--top;
    return car;
}
//��ѯ������Ϣ
void ParkingStack::queryCars(char *targetLicense)
{
    int index = getCarIndex(targetLicense);
    if (index >= 0)
        (*(base + index))->printCars();
}
//���ͣ�����ڳ����б�
void ParkingStack::printStack()
{
    Cars **p = base;
    while (p <= top)
        (*p)->printCars();
}
//��ó���λ��
int ParkingStack::getCarIndex(char *targetLicense)
{
    Cars **p = base;
    while (p < top)
    {
        if (strcmp((*p)->getLicense(), targetLicense))
            return p - base;
        p++;
    }
    cout << "δ��ѯ���ó�����Ϣ��" << endl;
    return -1;
}
//�����ų���
Cars *ParkingStack::getCar(int index)
{
    return *(base + index);
}
//���ջ��ָ��
Cars **ParkingStack::getTopPointer()
{
    return top;
}