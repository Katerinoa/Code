#include <bits/stdc++.h>
using namespace std;

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
} SqList;

typedef struct LNode
{
	Student data;
	struct LNode *next;
} LNode, *Linklist;

LNode *head, *tail;
int sum = 0;

void CreatList()
{
	sum = 0;
	if (head == NULL)
	{
		head = (LNode *)malloc(sizeof(LNode));
		head->next = NULL;
	}
	else
		cout << "链表已创建,无需重新创建链表" << endl;
}

void PutIn()
{
	int num;
	cout << "请输入要添加的学生信息的数量: " << endl;
	cin >> num;
	sum += num;
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
		LNode *p = (LNode *)malloc(sizeof(LNode));
		strcpy(p->data.no, _no);
		strcpy(p->data.name, _name);
		p->data.price = _price;
		//判断头指针是否有指向
		if (head->next == NULL)
		{
			head->next = p;
			tail = p;
			tail->next = NULL;
		}
		else
		{
			tail->next = p;
			tail = p;
			tail->next = NULL;
		}
	}
}

void Print()
{
	LNode *p = head;
	if (head->next == NULL)
	{
		cout << "链表中未存储学生信息!" << endl;
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
		cout << "学号: " << p->data.no << "  姓名: " << p->data.name << "  成绩: " << p->data.price << endl;
	}
}

void nameFind()
{
	char str[30];
	cout << "请输入要查询的学生姓名: " << endl;
	cin >> str;
	LNode *p = head;
	if (head->next == NULL)
	{
		cout << "链表中未存储学生信息!" << endl;
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(str, p->data.name) == 0)
		{
			cout << "学号: " << p->data.no << "  成绩: " << p->data.price << endl;
			return;
		}
	}
	cout << "未查询到该生信息!" << endl;
}

void indexFind()
{
	if (head->next == NULL)
	{
		cout << "链表中未存储学生信息!" << endl;
		return;
	}
	int index;
	cout << "请输入要查询的位置: " << endl;
	cin >> index;

	LNode *p = head->next;
	while (p->next != NULL && index)
	{
		p = p->next;
		index--;
	}
	if (index)
		cout << "链表中没有存储这么多学生的信息" << endl;
	else
		cout << "学号: " << p->data.no << "  姓名: " << p->data.name << "  成绩: " << p->data.price << endl;
}

void Insert()
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

	LNode *p = (LNode *)malloc(sizeof(LNode));
	LNode *q, *p1 = head;
	strcpy(p->data.no, _no);
	strcpy(p->data.name, _name);
	p->data.price = _price;

	while (p1->next != NULL && index) //在指定位置前一节点停下
	{
		p1 = p1->next;
		index--;
		if (index == 0) //链表长度不够时终止函数
		{
			cout << "链表长度不足" << endl;
			return;
		}
	}
	if (index) //链表长度不够时终止函数
	{
		cout << "链表中没有存储这么多学生的信息" << endl;
		return;
	}
	sum++;
	if (p1->next == NULL) //需要移动尾指针
	{
		p1->next = p;
		tail = p;
		tail->next = NULL;
	}
	else //不需要移动尾指针
	{
		q = p1->next;
		p1->next = p;
		p->next = q;
	}
}
void Delete()
{
	if (head->next == NULL)
	{
		cout << "链表中未存储学生信息!" << endl;
		return;
	}
	int index;
	cout << "请输入要删除的位置: " << endl;
	cin >> index;
	LNode *p = head;
	while (p->next != NULL && index)
	{
		p = p->next;
		index--;
		if (index == 0)
		{
			cout << "链表中没有存储这么多学生的信息" << endl;
			return;
		}
	}
	if (index)
	{
		cout << "链表中没有存储这么多学生的信息" << endl;
		return;
	}
	LNode *q = p->next;
	if (q->next == NULL)
		p = tail;
	else
		p->next = p->next->next;
	free(q);
	sum--;
}
void showSum()
{
	cout << "链表中共有" << sum << "位学生的信息" << endl;
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
	CreatList();
	char mode[10];
	showMenu();
	while (cin >> mode && mode[0] != 'e' && mode[0] != 'E')
	{
		switch (mode[0])
		{
		case 'm':
			showMenu();
			break;
		case 'p':
			PutIn();
			break;
		case 's':
			Print();
			break;
		case 'n':
			nameFind();
			break;
		case 'f':
			indexFind();
			break;
		case 'i':
			Insert();
			break;
		case 'd':
			Delete();
			break;
		case 'q':
			showSum();
			break;
		default:
			break;
		}
		cout << endl;
		cout << "请继续输入,输入menu查看菜单栏" << endl;
	}
	return 0;
}
