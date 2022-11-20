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
		cout << "�����Ѵ���,�������´�������" << endl;
}

void PutIn()
{
	int num;
	cout << "������Ҫ��ӵ�ѧ����Ϣ������: " << endl;
	cin >> num;
	sum += num;
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
		LNode *p = (LNode *)malloc(sizeof(LNode));
		strcpy(p->data.no, _no);
		strcpy(p->data.name, _name);
		p->data.price = _price;
		//�ж�ͷָ���Ƿ���ָ��
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
		cout << "������δ�洢ѧ����Ϣ!" << endl;
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
		cout << "ѧ��: " << p->data.no << "  ����: " << p->data.name << "  �ɼ�: " << p->data.price << endl;
	}
}

void nameFind()
{
	char str[30];
	cout << "������Ҫ��ѯ��ѧ������: " << endl;
	cin >> str;
	LNode *p = head;
	if (head->next == NULL)
	{
		cout << "������δ�洢ѧ����Ϣ!" << endl;
		return;
	}
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(str, p->data.name) == 0)
		{
			cout << "ѧ��: " << p->data.no << "  �ɼ�: " << p->data.price << endl;
			return;
		}
	}
	cout << "δ��ѯ��������Ϣ!" << endl;
}

void indexFind()
{
	if (head->next == NULL)
	{
		cout << "������δ�洢ѧ����Ϣ!" << endl;
		return;
	}
	int index;
	cout << "������Ҫ��ѯ��λ��: " << endl;
	cin >> index;

	LNode *p = head->next;
	while (p->next != NULL && index)
	{
		p = p->next;
		index--;
	}
	if (index)
		cout << "������û�д洢��ô��ѧ������Ϣ" << endl;
	else
		cout << "ѧ��: " << p->data.no << "  ����: " << p->data.name << "  �ɼ�: " << p->data.price << endl;
}

void Insert()
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

	LNode *p = (LNode *)malloc(sizeof(LNode));
	LNode *q, *p1 = head;
	strcpy(p->data.no, _no);
	strcpy(p->data.name, _name);
	p->data.price = _price;

	while (p1->next != NULL && index) //��ָ��λ��ǰһ�ڵ�ͣ��
	{
		p1 = p1->next;
		index--;
		if (index == 0) //�����Ȳ���ʱ��ֹ����
		{
			cout << "�����Ȳ���" << endl;
			return;
		}
	}
	if (index) //�����Ȳ���ʱ��ֹ����
	{
		cout << "������û�д洢��ô��ѧ������Ϣ" << endl;
		return;
	}
	sum++;
	if (p1->next == NULL) //��Ҫ�ƶ�βָ��
	{
		p1->next = p;
		tail = p;
		tail->next = NULL;
	}
	else //����Ҫ�ƶ�βָ��
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
		cout << "������δ�洢ѧ����Ϣ!" << endl;
		return;
	}
	int index;
	cout << "������Ҫɾ����λ��: " << endl;
	cin >> index;
	LNode *p = head;
	while (p->next != NULL && index)
	{
		p = p->next;
		index--;
		if (index == 0)
		{
			cout << "������û�д洢��ô��ѧ������Ϣ" << endl;
			return;
		}
	}
	if (index)
	{
		cout << "������û�д洢��ô��ѧ������Ϣ" << endl;
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
	cout << "�����й���" << sum << "λѧ������Ϣ" << endl;
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
		cout << "���������,����menu�鿴�˵���" << endl;
	}
	return 0;
}
