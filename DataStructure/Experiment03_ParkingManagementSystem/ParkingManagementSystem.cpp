#include <bits/stdc++.h>
#include "ParkingStack.h"
#include "Cars.h"
#include "ShortCut.h"
using namespace std;

//����ʻ��ͣ����
void EnterParking(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    //��ʼ����������
    cout << "�Ǽǳ��ƺ� �� ��������ʱ��: " << endl;
    char *license = new char[20];
    int comeTime;
    cin >> license >> comeTime;
    Cars *newCar = new Cars();
    newCar->initCars(license, comeTime); //Ĭ��λ�� 0:���,Ĭ��״̬ 1:���ڽ���ͣ����
    //���ͣ����δ��
    if (!Parking.StackFull())
    {
        Parking.EnterParking(newCar);   //��������ͣ����
        newCar->setPosition(1);         //λ���л�Ϊ 1:ͣ����
        newCar->setEnterTime(comeTime); //���ý���ͣ����ʱ��Ϊ����ʱ��
        cout << "�ó���ͣ��ͣ������" << Parking.countCars() << "��λ��   "
             << "ʣ�೵λ: " << Parking.countEmpty() << endl
             << endl;
    }
    //���ͣ��������
    else
    {
        Cut.EnterCut(newCar); //����������ʱ����Ⱥ�ͣ��
        cout << "ͣ��������,�������Ⱥ�ͣ��,��ǰ�Ŷ�λ��: ��" << Cut.countCars() << "λ" << endl
             << endl;
    }
}
//����ʻ��ͣ����
void LeaveParking(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    cout << "ʻ��ͣ���������ĳ��ƺ� �� �뿪��ʱ��:" << endl;
    char* license;
    int leaveTime;
    cin >> license >> leaveTime;
    int index = Parking.getCarIndex(license);
    Cars *car_p;
    if (index >= 0)                    //ͣ�������и��ƺų���
        car_p = Parking.getCar(index); //��ȡҪʻ��ͣ�����ĳ���
    else
    {
        cout << "ͣ������û��ͣ�Ÿó�����" << endl;
        return;
    }
    //���ͣ�������ǿ�
    if (!Parking.StackEmpty())
    {
        Cars *temp = NULL;
        int parkTime = leaveTime - car_p->getEnterTime();
        cout << "�ó�ͣ����ʱ��Ϊ: " << parkTime << " Сʱ,Ӧ�ɷ���Ϊ: " << parkTime * 1.5 << "Ԫ" << endl;
        //��ǰ��ĳ���������ʱ���
        while (*(Parking.getTopPointer()) != car_p)
        {
            temp = Parking.LeaveParking();
            TemParking.EnterParking(temp);
        }
        Parking.LeaveParking();
        //����ʱ����ĳ��ƻ�ͣ����
        while (!TemParking.StackEmpty())
        {
            temp = TemParking.LeaveParking();
            Parking.EnterParking(temp);
        }
        if (!Cut.QueneEmpty())
        {
            temp = Cut.LeaveCut();
            Parking.EnterParking(temp);
            cout << "�ڱ���ϵ�1��λ����,���ƺ�Ϊ:" << temp->getLicense() << " �ĳ���ͣ������ʱ��Ϊ:" << leaveTime << endl;
        }
    }
}
int main()
{
    //��ʼ��
    int maxSize;
    cout << "������ͣ��������: ";
    cin >> maxSize;
    ParkingStack Parking(maxSize);
    ParkingStack TemParking(maxSize);
    ShortCut Cut;
    EnterParking(Parking, TemParking, Cut);
    LeaveParking(Parking, TemParking, Cut);
    LeaveParking(Parking, TemParking, Cut);
}