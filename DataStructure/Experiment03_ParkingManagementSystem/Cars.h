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
    char* license; //������ʶ
    int position;   //����λ��,0��ʾ�����1��ʾͣ����
    int comeTime;   //����ʱ��
    int enterTime;  //����ͣ����ʱ��
};
