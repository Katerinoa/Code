#include <bits/stdc++.h>
#include "ParkingStack.h"
#include "Cars.h"
#include "ShortCut.h"
using namespace std;

//车辆驶入停车场
void EnterParking(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    //初始化新来车辆
    cout << "登记车牌号 及 车辆到达时间: " << endl;
    char *license = new char[20];
    int comeTime;
    cin >> license >> comeTime;
    Cars *newCar = new Cars();
    newCar->initCars(license, comeTime); //默认位置 0:便道,默认状态 1:正在进入停车场
    //如果停车场未满
    if (!Parking.StackFull())
    {
        Parking.EnterParking(newCar);   //车辆进入停车场
        newCar->setPosition(1);         //位置切换为 1:停车场
        newCar->setEnterTime(comeTime); //设置进入停车场时间为到达时间
        cout << "该车辆停在停车场第" << Parking.countCars() << "个位置   "
             << "剩余车位: " << Parking.countEmpty() << endl
             << endl;
    }
    //如果停车场已满
    else
    {
        Cut.EnterCut(newCar); //车辆进入临时便道等候停车
        cout << "停车场已满,进入便道等候停车,当前排队位置: 第" << Cut.countCars() << "位" << endl
             << endl;
    }
}
//车辆驶出停车场
void LeaveParking(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    cout << "驶出停车场车辆的车牌号 及 离开的时间:" << endl;
    char* license;
    int leaveTime;
    cin >> license >> leaveTime;
    int index = Parking.getCarIndex(license);
    Cars *car_p;
    if (index >= 0)                    //停车场中有该牌号车辆
        car_p = Parking.getCar(index); //获取要驶出停车场的车辆
    else
    {
        cout << "停车场中没有停放该车辆！" << endl;
        return;
    }
    //如果停车场不是空
    if (!Parking.StackEmpty())
    {
        Cars *temp = NULL;
        int parkTime = leaveTime - car_p->getEnterTime();
        cout << "该车停留的时间为: " << parkTime << " 小时,应缴费用为: " << parkTime * 1.5 << "元" << endl;
        //将前面的车辆移入临时便道
        while (*(Parking.getTopPointer()) != car_p)
        {
            temp = Parking.LeaveParking();
            TemParking.EnterParking(temp);
        }
        Parking.LeaveParking();
        //将临时便道的车移回停车场
        while (!TemParking.StackEmpty())
        {
            temp = TemParking.LeaveParking();
            Parking.EnterParking(temp);
        }
        if (!Cut.QueneEmpty())
        {
            temp = Cut.LeaveCut();
            Parking.EnterParking(temp);
            cout << "在便道上第1的位置上,车牌号为:" << temp->getLicense() << " 的车进停车场的时间为:" << leaveTime << endl;
        }
    }
}
int main()
{
    //初始化
    int maxSize;
    cout << "请输入停车场容量: ";
    cin >> maxSize;
    ParkingStack Parking(maxSize);
    ParkingStack TemParking(maxSize);
    ShortCut Cut;
    EnterParking(Parking, TemParking, Cut);
    LeaveParking(Parking, TemParking, Cut);
    LeaveParking(Parking, TemParking, Cut);
}