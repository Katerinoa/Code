#include "Cars.h"

Cars::Cars()
{
    license = new char[20];
}
//初始化车辆
void Cars::initCars(char *license, int comeTime)
{
    strcpy(this->license, license);
    comeTime = comeTime;
    position = 0;   //默认在便道等候
    enterTime = -1; //表示未进入停车场，不能出停车场
}
//设置车辆位置,输入1表示在停车场,输入0表示在便道
void Cars::setPosition(int position)
{
    this->position = position;
}
//设置车辆进入停车场的时间
void Cars::setEnterTime(int enterTime)
{
    this->enterTime = enterTime;
}
//输出车辆信息
void Cars::printCars()
{
    cout << "车牌号: " << license << endl
         << "到达时间:  " << comeTime << endl;
    if (position == 1)
        cout << "进入停车场时间:  " << enterTime << endl;
}
//获得车牌号
char *Cars::getLicense()
{
    return license;
}
//获得进停车场时间
int Cars::getEnterTime()
{
    return enterTime;
}