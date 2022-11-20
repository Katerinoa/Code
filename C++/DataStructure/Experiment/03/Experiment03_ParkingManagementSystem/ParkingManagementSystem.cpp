#include <bits/stdc++.h>
#include "ParkingStack.h"
#include "Cars.h"
#include "ShortCut.h"
using namespace std;

//���ͣ�����ڳ����б�
void ShowCars(ParkingStack &Parking, ShortCut &Cut)
{
    cout << "ͣ����: " << endl;
    if (Parking.StackEmpty())
        cout << "ͣ������û�г�����" << endl;
    else
        Parking.printStack();
    cout << endl;
    cout << "���: " << endl;
    if (Cut.QueneEmpty())
        cout << "�����û�г�����" << endl;
    else
        Cut.printQuene();
    cout << endl;
}
//��ѯ����״̬
void QueryCars(ParkingStack &Parking, ShortCut &Cut)
{
    cout << "������Ҫ��ѯ�ĳ����ĳ��ƺ�: ";
    char *license = new char[20];
    cin >> license;
    Cars *car_p;
    if (!Parking.getCar(license) && !Cut.getCar(license))
    {
        cout << "δ��ѯ���ó�����" << endl;
        return;
    }
    else if (car_p = Parking.getCar(license)) //ͣ�������и��ƺų���
    {
        car_p->printCars();
        cout << "��ͣ������λ��Ϊ: " << Parking.getCarIndex(license) + 1
             << "����ͣ����ʱ��: " << car_p->getEnterTime().hour << ':' << car_p->getEnterTime().min << endl;
    }
    else if (car_p = Cut.getCar(license))
    {
        car_p->printCars();
        cout << "��ǰ���ڵ�" << Cut.getCarIndex(license) + 1 << "λ�Ⱥ�ͣ��" << endl;
    }
}
//����ʻ��ͣ����
void EnterParking(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    //��ʼ����������
    cout << "�Ǽǳ��ƺ� �� ��������ʱ��(ʱ ��): " << endl;
    char *license = new char[20];
    Time comeTime;
    cin >> license >> comeTime.hour >> comeTime.min;
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
    Time leaveTime;
    cin >> license >> leaveTime.hour >> leaveTime.min;
    Cars *car_p;
    if (car_p = Parking.getCar(license))
    {
        Time parkTime = car_p->getParkTime(leaveTime);
        cout << "�ó�ͣ����ʱ��Ϊ: " << parkTime.hour << "Сʱ" << parkTime.min << "����,Ӧ�ɷ���Ϊ: " << (parkTime.hour + 1) * 1.5 << "Ԫ" << endl;
        Cars *temp = NULL;
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
            temp->setPosition(1); //λ������Ϊͣ����
            temp->setEnterTime(leaveTime);
            cout << "�ڱ���ϵ�1��λ����,���ƺ�Ϊ: " << temp->getLicense() << " �ĳ�ʻ��ͣ����"
                 << "ʻ��ʱ��Ϊ: " << temp->getEnterTime().hour << ':' << temp->getEnterTime().min << endl;
        }
    }
    else
    {
        cout << "ͣ������δ��ѯ���ó�����Ϣ��" << endl;
        return;
    }
}
void manageSystem(ParkingStack &Parking, ParkingStack &TemParking, ShortCut &Cut)
{
    cout << "�г�������ͣ����(A);�г�����ͣ����(D);��ѯ��ǰ���г���״̬(S);��ѯָ���ƺų���״̬(Q);����ֹͣ(#):" << endl;
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
        case 'S':
            ShowCars(Parking, Cut);
            break;
        case 'Q':
            QueryCars(Parking, Cut);
            break;
        default:
            cout << "��������ȷ�Ĳ�����ʶ! " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //�������뻺�����е�����
            break;
        }
        cout << endl;
        cout << "�г�������ͣ����(A);�г�����ͣ����(D);��ѯ��ǰ���г���״̬(S);��ѯָ���ƺų���״̬(Q);����ֹͣ(#):" << endl;
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