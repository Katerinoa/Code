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
//动态数组初始化
void initList(SqList &L)
{
    L.elem = (Student *)malloc(INITIAL_CAPACITY * sizeof(Student));
    L.length = 0;
    L.Listsize = 100;
}
//动态数组扩容检查
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
    cout << "请输入要添加的学生信息的数量: " << endl;
    cin >> num;
    checkList(L, num); //检查是否需要扩容
    char _no[100];
    char _name[100];
    int _price;
    cout << "输入学生信息, 格式: 学号 姓名 成绩" << endl;
    cout << "  学号  姓名 成绩" << endl;
    while (num--)
    {
        cin >> _no;
        cin >> _name;
        cin >> _price;
        while (strlen(_no) != 8)
        {
            cout << "请输入正确的8位学号: " << endl;
            cin >> _no;
        }
        while (strlen(_name) > 20)
        {
            cout << "名字长度过长, 请重新输入" << endl;
            cin >> _name;
        }
        while (_price > 100 || _price < 0)
        {
            cout << "请输入0-100范围的成绩" << endl;
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
        cout << "表中未存放信息!" << endl;
        return;
    }
    for (int i = 0; i < L.length; i++)
    {
        cout << "学号: " << L.elem[i].no << "  姓名: " << L.elem[i].name << "  成绩: " << L.elem[i].price << endl;
    }
}

void nameFind(SqList &L)
{
    char str[30];
    cout << "请输入要查询的学生姓名: " << endl;
    cin >> str;
    if (L.length == 0)
    {
        cout << "表中未存放信息!" << endl;
        return;
    }
    for (int i = 0; i < L.length; i++)
    {
        if (strcmp(L.elem[i].name, str) == 0)
        {
            cout << "学号: " << L.elem[i].no << "  成绩: " << L.elem[i].price << endl;
            return;
        }
    }
    cout << "未查询到该生信息!" << endl;
}

void indexFind(SqList &L)
{
    int index;
    cout << "请输入要查询的位置: " << endl;
    cin >> index;
    if (index > L.length - 1)
    {
        cout << "数组中没有存储这么多学生的信息!" << endl;
        return;
    }
    cout << "学号: " << L.elem[index].no << "  姓名: " << L.elem[index].name << "  成绩: " << L.elem[index].price << endl;
}

void Insert(SqList &L)
{
    char _no[100];
    char _name[100];
    int _price;
    int index;
    cout << "输入学生信息, 格式: 学号 姓名 成绩" << endl;
    cin >> _no;
    cin >> _name;
    cin >> _price;
    while (strlen(_no) != 8)
    {
        cout << "请输入正确的8位学号: " << endl;
        cin >> _no;
    }
    while (strlen(_name) > 20)
    {
        cout << "名字长度过长, 请重新输入" << endl;
        cin >> _name;
    }
    while (_price > 100 || _price < 0)
    {
        cout << "请输入0-100范围的成绩" << endl;
        cin >> _price;
    }
    cout << "请输入要插入的位置: " << endl;
    cin >> index;
    if (index > L.length - 1)
    {
        cout << "数组中没有存储这么多学生的信息" << endl;
        return;
    }
    checkList(L, 1); //检查是否需要扩容
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
    cout << "请输入要删除的位置: " << endl;
    cin >> index;
    if (index > L.length - 1)
    {
        cout << "数组中没有存储这么多学生的信息" << endl;
        return;
    }
    for (int i = index; i < L.length; i++)
        L.elem[i] = L.elem[i + 1];
    L.length--;
}

void showSum(SqList &L)
{
    cout << "数组中共有" << L.length << "位学生的信息" << endl;
}

void showMenu()
{
    cout << "请输入选择功能: \n"
         << "putin: 逐个输入学生信息\n"
         << "show: 显示表中所有学生信息\n"
         << "namefind: 根据姓名查找学生信息\n"
         << "find: 指定位置查找学生信息\n"
         << "insert: 将学生信息插入指定位置\n"
         << "delete: 删除指定位置的学生信息\n"
         << "quantity: 显示表中学生信息个数\n"
         << "输入end结束\n"
         << "请输入: " << endl;
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
        cout << "请继续输入,输入menu查看菜单栏" << endl;
    }
    return 0;
}
