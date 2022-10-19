#include "Cars.h"

Cars::Cars()
{
    license = new char[20];
}
//��ʼ������
void Cars::initCars(char *license, int comeTime)
{
    strcpy(this->license, license);
    comeTime = comeTime;
    position = 0;   //Ĭ���ڱ���Ⱥ�
    enterTime = -1; //��ʾδ����ͣ���������ܳ�ͣ����
}
//���ó���λ��,����1��ʾ��ͣ����,����0��ʾ�ڱ��
void Cars::setPosition(int position)
{
    this->position = position;
}
//���ó�������ͣ������ʱ��
void Cars::setEnterTime(int enterTime)
{
    this->enterTime = enterTime;
}
//���������Ϣ
void Cars::printCars()
{
    cout << "���ƺ�: " << license << endl
         << "����ʱ��:  " << comeTime << endl;
    if (position == 1)
        cout << "����ͣ����ʱ��:  " << enterTime << endl;
}
//��ó��ƺ�
char *Cars::getLicense()
{
    return license;
}
//��ý�ͣ����ʱ��
int Cars::getEnterTime()
{
    return enterTime;
}