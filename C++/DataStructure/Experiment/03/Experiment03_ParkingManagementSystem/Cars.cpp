#include "Cars.h"

Cars::Cars()
{
    license = new char[20];
}
//初始化车辆
void Cars::initCars(char *license, Time arriveTime)
{
    strcpy(this->license, license);
    comeTime = {arriveTime.hour, arriveTime.min};
    position = 0;         //默认在便道等候
    enterTime = {-1, -1}; //表示未进入停车场，不能出停车场
}
//设置车辆位置,输入1表示在停车场,输入0表示在便道
void Cars::setPosition(int position)
{
    this->position = position;
}
//设置车辆进入停车场的时间
void Cars::setEnterTime(Time enterTime)
{
    this->enterTime = enterTime;
}
//输出车辆信息
void Cars::printCars()
{
    cout << "车牌号: " << license
         << "  到达时间:  " << comeTime.hour << ':' << comeTime.min
         << "  当前位于 " << ((position == 0) ? "便道" : "停车场") << endl;
}
//获得车牌号
char *Cars::getLicense()
{
    return license;
}
//获得进停车场时间
Time Cars::getEnterTime()
{
    return enterTime;
}
//获得停车时间
Time Cars::getParkTime(Time leaveTime)
{
    int minutes = (leaveTime.hour * 60 + leaveTime.min) - (enterTime.hour * 60 + enterTime.min);
    if (minutes < 0)
        minutes += 60 * 24;
    Time parkTime = {minutes / 60, minutes % 60};
    return parkTime;
}
//获得位置
int Cars::getPosition()
{
    return position;
}
