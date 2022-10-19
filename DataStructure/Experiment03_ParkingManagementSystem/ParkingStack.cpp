#include "ParkingStack.h"

//构造函数
ParkingStack::ParkingStack(int Size)
{
    base = new Cars *[Size];
    top = base;
    this->stackSize = Size;
}
//析构函数
ParkingStack::~ParkingStack()
{
    if (base)
    {
        delete base;
        top = base = NULL;
        stackSize = 0;
    }
}
//当前停车数
int ParkingStack::countCars() const
{
    return top - base;
}
//当前剩余车位
int ParkingStack::countEmpty() const
{
    return stackSize - countCars();
}
//栈是否为空
bool ParkingStack::StackEmpty() const
{
    return base == top;
}
//栈是否为满
bool ParkingStack::StackFull() const
{
    return (top - base) == stackSize;
}
//清空栈
void ParkingStack::clearStack()
{
    if (base)
        delete base;
}
//车辆进入停车场
void ParkingStack::EnterParking(Cars *car)
{
    if (StackFull())
        return;
    *top++ = car;
}
//车辆离开停车场
Cars *ParkingStack::LeaveParking()
{
    Cars *car = *--top;
    return car;
}
//查询车辆信息
void ParkingStack::queryCars(char *targetLicense)
{
    int index = getCarIndex(targetLicense);
    if (index >= 0)
        (*(base + index))->printCars();
}
//输出停车场内车辆列表
void ParkingStack::printStack()
{
    Cars **p = base;
    while (p <= top)
        (*p)->printCars();
}
//获得车辆位置
int ParkingStack::getCarIndex(char *targetLicense)
{
    Cars **p = base;
    while (p < top)
    {
        if (strcmp((*p)->getLicense(), targetLicense))
            return p - base;
        p++;
    }
    cout << "未查询到该车辆信息！" << endl;
    return -1;
}
//获得序号车辆
Cars *ParkingStack::getCar(int index)
{
    return *(base + index);
}
//获得栈顶指针
Cars **ParkingStack::getTopPointer()
{
    return top;
}