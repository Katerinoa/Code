#include <bits/stdc++.h>
using namespace std;
#define INITIAL_CAPACITY 100
#define INCREASE_CAPACITY 10
typedef struct
{
    char no[9];
    char name[21];
    int price;
} Student;

typedef struct
{
    Student *elem;
    int length;
    int Listsize;
} SqList;
//��̬�����ʼ��
void initList(SqList &L)
{
    L.elem = (Student *)malloc(INITIAL_CAPACITY * sizeof(Student));
    L.length = 0;
    L.Listsize = 100;
}
//��̬�������ݼ��
void checkList(SqList &L, int num)
{
    while (L.length + num > L.Listsize)
    {
        L.elem = (Student *)realloc(L.elem, INCREASE_CAPACITY * sizeof(Student));
        L.Listsize += INCREASE_CAPACITY;
    }
}
void PutIn(SqList &L)
{
    int num;
    cout << "������Ҫ��ӵ�ѧ����Ϣ������: " << endl;
    cin >> num;
    checkList(L, num); //����Ƿ���Ҫ����
    char _no[100];
    char _name[100];
    int _price;
    cout << "����ѧ����Ϣ, ��ʽ: ѧ�� ���� �ɼ�" << endl;
    cout << "  ѧ��  ���� �ɼ�" << endl;
    while (num--)
    {
        cin >> _no;
        cin >> _name;
        cin >> _price;
        while (strlen(_no) != 8)
        {
            cout << "��������ȷ��8λѧ��: " << endl;
            cin >> _no;
        }
        while (strlen(_name) > 20)
        {
            cout << "���ֳ��ȹ���, ����������" << endl;
            cin >> _name;
        }
        while (_price > 100 || _price < 0)
        {
            cout << "������0-100��Χ�ĳɼ�" << endl;
            cin >> _price;
        }
        strcpy(L.elem[L.length].no, _no);
        strcpy(L.elem[L.length].name, _name);
        L.elem[L.length].price = _price;
        L.length++;
    }
}

void Print(SqList &L)
{
    if (L.length == 0)
    {
        cout << "����δ�����Ϣ!" << endl;
        return;
    }
    for (int i = 0; i < L.length; i++)
    {
        cout << "ѧ��: " << L.elem[i].no << "  ����: " << L.elem[i].name << "  �ɼ�: " << L.elem[i].price << endl;
    }
}

void nameFind(SqList &L)
{
    char str[30];
    cout << "������Ҫ��ѯ��ѧ������: " << endl;
    cin >> str;
    if (L.length == 0)
    {
        cout << "����δ�����Ϣ!" << endl;
        return;
    }
    for (int i = 0; i < L.length; i++)
    {
        if (strcmp(L.elem[i].name, str) == 0)
        {
            cout << "ѧ��: " << L.elem[i].no << "  �ɼ�: " << L.elem[i].price << endl;
            return;
        }
    }
    cout << "δ��ѯ��������Ϣ!" << endl;
}

void indexFind(SqList &L)
{
    int index;
    cout << "������Ҫ��ѯ��λ��: " << endl;
    cin >> index;
    if (index > L.length - 1)
    {
        cout << "������û�д洢��ô��ѧ������Ϣ!" << endl;
        return;
    }
    cout << "ѧ��: " << L.elem[index].no << "  ����: " << L.elem[index].name << "  �ɼ�: " << L.elem[index].price << endl;
}

void Insert(SqList &L)
{
    char _no[100];
    char _name[100];
    int _price;
    int index;
    cout << "����ѧ����Ϣ, ��ʽ: ѧ�� ���� �ɼ�" << endl;
    cin >> _no;
    cin >> _name;
    cin >> _price;
    while (strlen(_no) != 8)
    {
        cout << "��������ȷ��8λѧ��: " << endl;
        cin >> _no;
    }
    while (strlen(_name) > 20)
    {
        cout << "���ֳ��ȹ���, ����������" << endl;
        cin >> _name;
    }
    while (_price > 100 || _price < 0)
    {
        cout << "������0-100��Χ�ĳɼ�" << endl;
        cin >> _price;
    }
    cout << "������Ҫ�����λ��: " << endl;
    cin >> index;
    if (index > L.length - 1)
    {
        cout << "������û�д洢��ô��ѧ������Ϣ" << endl;
        return;
    }
    checkList(L, 1); //����Ƿ���Ҫ����
    for (int i = L.length - 1; i >= index; i--)
        L.elem[i + 1] = L.elem[i];
    strcpy(L.elem[index].no, _no);
    strcpy(L.elem[index].name, _name);
    L.elem[index].price = _price;
    L.length++;
}

void Delete(SqList &L)
{
    int index;
    cout << "������Ҫɾ����λ��: " << endl;
    cin >> index;
    if (index > L.length - 1)
    {
        cout << "������û�д洢��ô��ѧ������Ϣ" << endl;
        return;
    }
    for (int i = index; i < L.length; i++)
        L.elem[i] = L.elem[i + 1];
    L.length--;
}

void showSum(SqList &L)
{
    cout << "�����й���" << L.length << "λѧ������Ϣ" << endl;
}

void showMenu()
{
    cout << "������ѡ����: \n"
         << "putin: �������ѧ����Ϣ\n"
         << "show: ��ʾ��������ѧ����Ϣ\n"
         << "namefind: ������������ѧ����Ϣ\n"
         << "find: ָ��λ�ò���ѧ����Ϣ\n"
         << "insert: ��ѧ����Ϣ����ָ��λ��\n"
         << "delete: ɾ��ָ��λ�õ�ѧ����Ϣ\n"
         << "quantity: ��ʾ����ѧ����Ϣ����\n"
         << "����end����\n"
         << "������: " << endl;
}

int main()
{
    SqList mylist;
    char mode[10];
    initList(mylist);
    showMenu();
    while (cin >> mode && mode[0] != 'e' && mode[0] != 'E')
    {
        switch (mode[0])
        {
        case 'm':
            showMenu();
            break;
        case 'p':
            PutIn(mylist);
            break;
        case 's':
            Print(mylist);
            break;
        case 'n':
            nameFind(mylist);
            break;
        case 'f':
            indexFind(mylist);
            break;
        case 'i':
            Insert(mylist);
            break;
        case 'd':
            Delete(mylist);
            break;
        case 'q':
            showSum(mylist);
            break;
        default:
            break;
        }
        cout << endl;
        cout << "���������,����menu�鿴�˵���" << endl;
    }
    return 0;
}
