#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    Node *next;
} Node, *LinkedList;
// Homework 01
void deleteXNodeWithoutHeadNode(LinkedList &L, ElemType x)
{
    if (L == NULL) //�˳�����: ����������ĩβ
        return;
    if (L->data == x)
    {
        Node *p = L;
        L = L->next; //��ֵΪ�������ͣ������ʹLָ����һ���ڵ㣬��δ�ı������ַ����L��ǰ�ڵ���Ȼָ��L
        delete p;
        deleteXNodeWithoutHeadNode(L, x); // LΪ��һ���ڵ㣬�����һ�α�����L��ʼ
    }
    else
        deleteXNodeWithoutHeadNode(L->next, x);
}
// Homework 02
void deleteXNodeWithHeadNode(LinkedList L, ElemType x)
{
    Node *p = L->next, *q = L;
    while (p)
    {
        if (p->data == x)
        {
            q->next = q->next->next; //ǰ��������Ӻ�̽ڵ�
            delete p;                //ɾ����ǰ�ڵ�
            p = q->next;
        }
        else
        {
            p = p->next; //����������
            q = q->next;
        }
    }
}
// Homework 03
void reversePrint(LinkedList L)
{
    vector<ElemType> temp;
    Node *p = L->next;
    while (p)
    {
        temp.push_back(p->data); //������Ԫ�طŽ�vector
        p = p->next;
    }
    for (auto i = temp.rbegin(); i != temp.rend(); ++i) //˳��洢 �������
        cout << *i << ' ';
    cout << endl;
}
// Homework 04
void deleteMinNode(LinkedList L)
{
    ElemType min = 1e9 + 7;
    Node *minNode = NULL, *minPrevNode = NULL;
    Node *p = L->next, *q = L;
    while (p)
    {
        if (p->data < min)
        {
            min = p->data;   //������Сֵ
            minNode = p;     //��Сֵ�ڵ�
            minPrevNode = q; //��Сֵ�ڵ��ǰ�����
        }
        p = p->next;
        q = q->next;
    }
    minPrevNode->next = minPrevNode->next->next; //ǰ��������Ӻ�̽ڵ�
    delete minNode;                              //ɾ����Сֵ�ڵ�
}
// Homework 05
void Reverse(LinkedList L)
{
    //����ͷ�巨���½�����Ľڵ���ͷ���ʵ������
    Node *p = L->next, *q;
    L->next = NULL; //ͷ����ʼ��
    while (p != NULL)
    {
        q = p->next;
        p->next = L->next; //ͷ�巨
        L->next = p;
        p = q;
    }
}
// Homework 06
void Sort(LinkedList L)
{
    Node *p = L->next, *q;
    while (p)
    {
        q = p->next;
        while (q)
        {
            if (p->data > q->data)
            {
                ElemType t = q->data;
                q->data = p->data;
                p->data = t;
            }
            q = q->next;
        }
        p = p->next;
    }
}
// Homework 07
void deleteBetweenValues(LinkedList L, ElemType v1, ElemType v2)
{
    Sort(L); //������Ԫ�ؽ�������
    Node *p1 = NULL, *p2 = NULL, *q1 = NULL, *q2 = NULL;
    Node *p = L->next;
    while (p)
    {
        //��������߽�ڵ�
        if (p->data <= v1 && p->next->data >= v1 && !p1)
            p1 = p;
        else if (p->data <= v2 && p->next->data >= v2 && p2)
            p2 = p;
        p = p->next;
    }
    if (p1 && p2)
    {
        Node *q = p1->next, *r;
        p1->next = p2;  // p1ֱ����p2����
        while (q != p2) //ɾ���м����нڵ�
        {
            r = q->next;
            delete q;
            q = r;
        }
    }
}
// Homework 08
vector<Node *> findCommonNode(LinkedList L1, LinkedList L2)
{
    Node *p1 = L1->next, *p2 = L2->next;
    vector<Node *> CommonNodes;
    Sort(L1); //�����������С��������
    Sort(L2);
    while (p1 && p2)
    {
        ElemType data1 = p1->data, data2 = p2->data;
        if (data1 == data2)
        {
            CommonNodes.push_back(p1); //��ͬ�ڵ�Ž�vector
            p1 = p1->next;             //��������һ��������
            p2 = p2->next;
        }
        else if (data1 < data2)
            p1 = p1->next; //�����������ֵ
        else
            p2 = p2->next;
    }
    return CommonNodes;
}
// Homework 09
void sortPrint(LinkedList L)
{
    Sort(L);
    Node *p = L->next, *q;
    while (p)
    {
        cout << p->data << ' ';
        q = p;
        p = p->next;
        delete q;
    }
}
// Homework 10
vector<LinkedList> divideList(LinkedList L)
{

    LinkedList A = NULL, B = NULL;
    int flag = 1; // ��־��ż 1ΪA��0ΪB
    Node *p = L->next, *q, *r;
    while (p)
    {
        q = p->next;
        r = (flag == 1) ? A : B;
        while (r->next) //˳�򲻱�ʹ��β�巨��������β�ڵ��ٽ��в���
            r = r->next;
        r->next = p;
        p->next = NULL;
        //����״̬
        p = q;
        flag = (flag == 1) ? 0 : 1;
    }
    return {A, B};
}