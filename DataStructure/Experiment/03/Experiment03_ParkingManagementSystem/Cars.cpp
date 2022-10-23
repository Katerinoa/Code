#include "Cars.h"

Cars::Cars()
{
    license = new char[20];
}
//��ʼ������
void Cars::initCars(char *license, Time arriveTime)
{
    strcpy(this->license, license);
    comeTime = {arriveTime.hour, arriveTime.min};
    position = 0;         //Ĭ���ڱ���Ⱥ�
    enterTime = {-1, -1}; //��ʾδ����ͣ���������ܳ�ͣ����
}
//���ó���λ��,����1��ʾ��ͣ����,����0��ʾ�ڱ��
void Cars::setPosition(int position)
{
    this->position = position;
}
//���ó�������ͣ������ʱ��
void Cars::setEnterTime(Time enterTime)
{
    this->enterTime = enterTime;
}
//���������Ϣ
void Cars::printCars()
{
    cout << "���ƺ�: " << license
         << "  ����ʱ��:  " << comeTime.hour << ':' << comeTime.min
         << "  ��ǰλ�� " << ((position == 0) ? "���" : "ͣ����") << endl;
}
//��ó��ƺ�
char *Cars::getLicense()
{
    return license;
}
//��ý�ͣ����ʱ��
Time Cars::getEnterTime()
{
    return enterTime;
}
//���ͣ��ʱ��
Time Cars::getParkTime(Time leaveTime)
{
    int minutes = (leaveTime.hour * 60 + leaveTime.min) - (enterTime.hour * 60 + enterTime.min);
    if (minutes < 0)
        minutes += 60 * 24;
    Time parkTime = {minutes / 60, minutes % 60};
    return parkTime;
}
//���λ��
int Cars::getPosition()
{
    return position;
}
