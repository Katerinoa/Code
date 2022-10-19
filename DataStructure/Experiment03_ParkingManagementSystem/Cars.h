#pragma once
#include <bits/stdc++.h>
using namespace std;

class Cars
{
public:
    Cars();
    void initCars(char *license, int comeTime);
    void setPosition(int position);
    void setEnterTime(int EnterTime);
    void printCars();
    char* getLicense();
    int getEnterTime();

private:
    char* license; //车辆标识
    int position;   //车辆位置,0表示便道，1表示停车场
    int comeTime;   //到达时间
    int enterTime;  //进入停车场时间
};
