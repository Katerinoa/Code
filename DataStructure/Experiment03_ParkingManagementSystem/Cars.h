#pragma once
#include <bits/stdc++.h>
using namespace std;
struct Time
{
    int hour;
    int min;
};
class Cars
{
public:
    Cars();
    void initCars(char *license, Time comeTime);
    void setPosition(int position);
    void setEnterTime(Time EnterTime);
    void printCars();
    char* getLicense();
    Time getEnterTime();
    Time getParkTime(Time leaveTime);

private:
    char* license; //车辆标识
    int position;   //车辆位置,0表示便道，1表示停车场
    Time comeTime;   //到达时间
    Time enterTime;  //进入停车场时间
};
