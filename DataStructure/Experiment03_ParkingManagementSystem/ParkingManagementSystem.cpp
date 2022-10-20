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
             << "ʣ�೵λ: " << Parking.countEmpty() << endl;
    }
    //���ͣ��������
    else
    {
        Cut.EnterCut(newCar); //����������ʱ����Ⱥ�ͣ��
        cout << "ͣ��������,�������Ⱥ�ͣ��,��ǰ�Ŷ�λ��: ��" << Cut.countCars() << "λ" << endl;
    }
}
//����ʻ��ͣ����
void LeaveParking(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    cout << "ʻ��ͣ���������ĳ��ƺ� �� �뿪��ʱ��:" << endl;
    char *license = new char[20];
    int leaveTime;
    cin >> license >> leaveTime;
    int index = Parking.getCarIndex(license);
    Cars *car_p;
    if (index >= 0)                    //ͣ�������и��ƺų���
        car_p = Parking.getCar(index); //��ȡҪʻ��ͣ�����ĳ���
    else
        return;
    //���ͣ�������ǿ�
    if (!Parking.StackEmpty())
    {
        Cars *temp = NULL;
        int parkTime = leaveTime - car_p->getEnterTime();
        cout << "�ó�ͣ����ʱ��Ϊ: " << parkTime << " Сʱ,Ӧ�ɷ���Ϊ: " << parkTime * 1.5 << "Ԫ" << endl;
        //��ǰ��ĳ���������ʱ���
        while (*(Parking.getTopPointer() - 1) != car_p)
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
            temp->setEnterTime(leaveTime);
            cout << "�ڱ���ϵ�1��λ����,���ƺ�Ϊ: " << temp->getLicense() << " �ĳ�ʻ��ͣ����" << endl
                 << "ʻ��ʱ��Ϊ: " << temp->getEnterTime() << endl;
        }
    }
}
void manageSystem(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    cout << "�г�������ͣ����(A);�г�����ͣ����(D);����ֹͣ(#):" << endl;
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
        default:
            cout << "��������ȷ�Ĳ�����ʶ! " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //�������뻺�����е�����
            break;
        }
        cout << endl;
        cout << "�г�������ͣ����(A);�г�����ͣ����(D);����ֹͣ(#):" << endl;
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
    //������
    manageSystem(Parking, TemParking, Cut);
}