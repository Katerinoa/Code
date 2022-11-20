#include <bits/stdc++.h>
using namespace std;
int letter[26];
typedef struct Node
{
    char ch;
    Node *next;
} Node;

class LinkedList
{
public:
    Node *L;
    string content;
    LinkedList()
    {
        L = (Node *)malloc(sizeof(Node));
        L->next = NULL;
    }
};

void InitList(LinkedList List)
{
    memset(letter, 0, sizeof(letter));
    Node *tail = List.L;
    while (tail->next != NULL)
        tail = tail->next; //������β�ڵ�
    cin >> List.content;
    for (int i = 0; i < List.content.size(); i++)
        letter[List.content[i] - 'A'] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (letter[i])
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            newNode->ch = ('A' + i);
            tail->next = newNode;
            tail = tail->next;
        }
    }
}

Node *Merge(Node *L1, Node *L2)
{
    memset(letter, 0, sizeof(letter));
    Node *L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    Node *tail = L;
    Node *p1 = L1->next, *p2 = L2->next;
    while (p1 != NULL)
    {
        letter[p1->ch - 'A'] = 1;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        letter[p2->ch - 'A'] = 1;
        p2 = p2->next;
    }
    for (int i = 0; i < 26; i++)
    {
        if (letter[i])
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            newNode->ch = ('A' + i);
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return L;
}

Node *Intersection(Node *L1, Node *L2)
{
    memset(letter, 0, sizeof(letter));
    Node *L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    Node *tail = L;
    Node *p1 = L1->next, *p2 = L2->next;
    while (p1 != NULL)
    {
        letter[p1->ch - 'A'] += 1;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        letter[p2->ch - 'A'] += 1;
        p2 = p2->next;
    }
    for (int i = 0; i < 26; i++)
    {
        if (letter[i] == 2)
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            newNode->ch = ('A' + i);
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return L;
}

Node *Minus(Node *L1, Node *L2)
{
    memset(letter, 0, sizeof(letter));
    Node *L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    Node *tail = L;
    Node *p1 = L1->next, *p2 = L2->next;
    while (p1 != NULL)
    {
        letter[p1->ch - 'A'] = 1;
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        letter[p2->ch - 'A'] = 0;
        p2 = p2->next;
    }
    for (int i = 0; i < 26; i++)
    {
        if (letter[i])
        {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->next = NULL;
            newNode->ch = ('A' + i);
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return L;
}

void printList(Node *L)
{
    if (L->next == NULL)
        cout << "�ñ�Ϊ�գ�" << endl;
    else
    {
        Node *p = L->next;
        while (p != NULL)
        {
            cout << p->ch;
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    int index, num = 1;
    LinkedList L1, L2;
    cout << "�������" << num++ << "�����ϵ�����" << endl;
    InitList(L1);
    cout << "�������" << num++ << "�����ϵ�����" << endl;
    InitList(L2);
    cout << "��������Ҫ���еĲ�����" << endl
         << "0. �˳�" << endl
         << "1. ȡ����" << endl
         << "2. ȡ����" << endl
         << "3. ���" << endl;
    while (cin >> index && index != 0)
    {
        switch (index)
        {
        case 1:
            cout << "ȡ�������Ϊ: " << endl;
            printList(Merge(L1.L, L2.L));
            break;
        case 2:
            cout << "ȡ�������Ϊ: " << endl;
            printList(Intersection(L1.L, L2.L));
            break;
        case 3:
            cout << "������Ϊ: " << endl;
            printList(Minus(L1.L, L2.L));
            break;
        default:
            break;
        }
    }
    return 0;
}