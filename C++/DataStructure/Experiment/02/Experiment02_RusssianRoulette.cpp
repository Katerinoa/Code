#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int elem; //��ͽ���
    Node *next;
} Node, *CircularList;

void CreatList(CircularList &L)
{
    if (L != NULL)
        return;
    else
    {
        L = (CircularList)malloc(sizeof(Node));
        L->next = L;
        L->elem = 0; //ͷ�����Ϊ0
    }
}

void InitList(CircularList L, int num)
{
    Node *tail = L;
    int i = 1;
    while (num--)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = L;
        newNode->elem = i++;
        tail->next = newNode;
        tail = tail->next;
    }
}
Node *DeleteNode(Node *p)
{
    Node *q = p;
    while (q->next != p)
        q = q->next;
    q->next = q->next->next;
    free(p);
    q = q->next;
    if (q->elem == 0) //�����ͷ�ڵ�������
        q = q->next;
    return q;
}

void PrintList(CircularList L)
{
    Node *p = L->next;
    while (p != L)
    {
        cout << p->elem << ' ';
        p = p->next;
    }
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL)); //���������
    CircularList L = NULL;
    CreatList(L); //����ѭ������
    int num, m;
    cout << "�����ͽ������: ";
    cin >> num;
    InitList(L, num); //��ʼ��ѭ������
    cout << "����ͽ���Ϊ 1-" << num << endl;
    Node *p = L->next; // pָ��ָ���һ����ͽ
    for (int round = 1; round < num; round++)
    {
        m = (rand() % 6 + 1); //����һ��1-6֮��������
        cout << "��" << round << "�ֿ�ʼ���ӱ��Ϊ" << p->elem << "���˿�ʼ��ǹ�ڵ�" << m << "�ο۶����ʱ����" << endl;
        for (int j = 1; j < m; j++)
        {
            p = p->next;
            if (p == L)
                p = p->next;
        }
        cout << "���Ϊ" << p->elem << "�Ķ�ͽ�˳��Ĳ�,ʣ���ͽ�������Ϊ: " << endl;
        p = DeleteNode(p);
        PrintList(L);
    }
    cout << "����ʤ���Ķ�ͽ�����: " << p->elem << endl;
    return 0;
}
