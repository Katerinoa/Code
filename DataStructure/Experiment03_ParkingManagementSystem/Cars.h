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
    char* license; //������ʶ
    int position;   //����λ��,0��ʾ�����1��ʾͣ����
    Time comeTime;   //����ʱ��
    Time enterTime;  //����ͣ����ʱ��
};
