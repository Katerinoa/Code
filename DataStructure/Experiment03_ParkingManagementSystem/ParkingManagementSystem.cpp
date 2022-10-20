#include <bits/stdc++.h>
#include "ParkingStack.h"
#include "Cars.h"
#include "ShortCut.h"
using namespace std;

//输出停车场内车辆列表
void ShowCars(ParkingStack &Parking, ShortCut &Cut)
{
    cout << "停车场: " << endl;
    if (Parking.StackEmpty())
        cout << "停车场内没有车辆！" << endl;
    else
        Parking.printStack();
    cout << endl;
    cout << "便道: " << endl;
    if (Cut.QueneEmpty())
        cout << "便道内没有车辆！" << endl;
    else
        Cut.printQuene();
    cout << endl;
}
//查询车辆状态
void QueryCars(ParkingStack &Parking, ShortCut &Cut)
{
    cout << "请输入要查询的车辆的车牌号: ";
    char *license = new char[20];
    cin >> license;
    Cars *car_p;
    if (!Parking.getCar(license) && !Cut.getCar(license))
    {
        cout << "未查询到该车辆！" << endl;
        return;
    }
    else if (car_p = Parking.getCar(license)) //停车场中有该牌号车辆
    {
        car_p->printCars();
        cout << "在停车场中位置为: " << Parking.getCarIndex(license) + 1
             << "进入停车场时间: " << car_p->getEnterTime().hour << ':' << car_p->getEnterTime().min << endl;
    }
    else if (car_p = Cut.getCar(license))
    {
        car_p->printCars();
        cout << "当前排在第" << Cut.getCarIndex(license) + 1 << "位等候停车" << endl;
    }
}
//车辆驶入停车场
void EnterParking(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    //初始化新来车辆
    cout << "登记车牌号 及 车辆到达时间(时 分): " << endl;
    char *license = new char[20];
    Time comeTime;
    cin >> license >> comeTime.hour >> comeTime.min;
    Cars *newCar = new Cars();
    newCar->initCars(license, comeTime); //默认位置 0:便道,默认状态 1:正在进入停车场
    //如果停车场未满
    if (!Parking.StackFull())
    {
        Parking.EnterParking(newCar);   //车辆进入停车场
        newCar->setPosition(1);         //位置切换为 1:停车场
        newCar->setEnterTime(comeTime); //设置进入停车场时间为到达时间
        cout << "该车辆停在停车场第" << Parking.countCars() << "个位置   "
             << "剩余车位: " << Parking.countEmpty() << endl;
    }
    //如果停车场已满
    else
    {
        Cut.EnterCut(newCar); //车辆进入临时便道等候停车
        cout << "停车场已满,进入便道等候停车,当前排队位置: 第" << Cut.countCars() << "位" << endl;
    }
}
//车辆驶出停车场
void LeaveParking(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    cout << "驶出停车场车辆的车牌号 及 离开的时间:" << endl;
    char *license = new char[20];
    Time leaveTime;
    cin >> license >> leaveTime.hour >> leaveTime.min;
    Cars *car_p;
    if (car_p = Parking.getCar(license))
    {
        Time parkTime = car_p->getParkTime(leaveTime);
        cout << "该车停留的时间为: " << parkTime.hour << "小时" << parkTime.min << "分钟,应缴费用为: " << (parkTime.hour + 1) * 1.5 << "元" << endl;
        Cars *temp = NULL;
        //将前面的车辆移入临时便道
        while (*(Parking.getTopPointer() - 1) != car_p)
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
            temp->setPosition(1); //位置设置为停车场
            temp->setEnterTime(leaveTime);
            cout << "在便道上第1的位置上,车牌号为: " << temp->getLicense() << " 的车驶入停车场"
                 << "驶入时间为: " << temp->getEnterTime().hour << ':' << temp->getEnterTime().min << endl;
        }
    }
    else
    {
        cout << "停车场中未查询到该车辆信息！" << endl;
        return;
    }
}
void manageSystem(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    cout << "有车辆进入停车场(A);有车辆出停车场(D);查询当前所有车辆状态(S);查询指定牌号车辆状态(Q);程序停止(#):" << endl;
    char input;
    while (cin >> input && input != '#')
    {
        switch (input)
        {
        case 'A':
            EnterParking(Parking, TemParking, Cut);
            break;
        case 'D':
            LeaveParking(Parking, TemParking, Cut);
            break;
        case 'S':
            ShowCars(Parking, Cut);
            break;
        case 'Q':
            QueryCars(Parking, Cut);
            break;
        default:
            cout << "请输入正确的操作标识! " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //丢弃输入缓冲区中的内容
            break;
        }
        cout << endl;
        cout << "有车辆进入停车场(A);有车辆出停车场(D);查询当前所有车辆状态(S);查询指定牌号车辆状态(Q);程序停止(#):" << endl;
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
    //管理函数
    manageSystem(Parking, TemParking, Cut);
}