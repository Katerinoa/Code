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
    if (L == NULL) //退出条件: 遍历至链表末尾
        return;
    if (L->data == x)
    {
        Node *p = L;
        L = L->next; //传值为引用类型，该语句使L指向下一个节点，但未改变自身地址，即L的前节点依然指向L
        delete p;
        deleteXNodeWithoutHeadNode(L, x); // L为下一个节点，因此下一次遍历从L开始
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
            q->next = q->next->next; //前驱结点连接后继节点
            delete p;                //删除当前节点
            p = q->next;
        }
        else
        {
            p = p->next; //继续向后遍历
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
        temp.push_back(p->data); //将所有元素放进vector
        p = p->next;
    }
    for (auto i = temp.rbegin(); i != temp.rend(); ++i) //顺序存储 逆序输出
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
            min = p->data;   //更新最小值
            minNode = p;     //最小值节点
            minPrevNode = q; //最小值节点的前驱结点
        }
        p = p->next;
        q = q->next;
    }
    minPrevNode->next = minPrevNode->next->next; //前驱结点连接后继节点
    delete minNode;                              //删除最小值节点
}
// Homework 05
void Reverse(LinkedList L)
{
    //利用头插法重新将链表的节点插回头结点实现逆序
    Node *p = L->next, *q;
    L->next = NULL; //头结点初始化
    while (p != NULL)
    {
        q = p->next;
        p->next = L->next; //头插法
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
    Sort(L); //对链表元素进行排序
    Node *p1 = NULL, *p2 = NULL, *q1 = NULL, *q2 = NULL;
    Node *p = L->next;
    while (p)
    {
        //标记两个边界节点
        if (p->data <= v1 && p->next->data >= v1 && !p1)
            p1 = p;
        else if (p->data <= v2 && p->next->data >= v2 && p2)
            p2 = p;
        p = p->next;
    }
    if (p1 && p2)
    {
        Node *q = p1->next, *r;
        p1->next = p2;  // p1直接与p2连接
        while (q != p2) //删除中间所有节点
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
    Sort(L1); //将两个链表从小到大排序
    Sort(L2);
    while (p1 && p2)
    {
        ElemType data1 = p1->data, data2 = p2->data;
        if (data1 == data2)
        {
            CommonNodes.push_back(p1); //相同节点放进vector
            p1 = p1->next;             //两条链表一起向后遍历
            p2 = p2->next;
        }
        else if (data1 < data2)
            p1 = p1->next; //向后遍历更大的值
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
    int flag = 1; // 标志奇偶 1为A，0为B
    Node *p = L->next, *q, *r;
    while (p)
    {
        q = p->next;
        r = (flag == 1) ? A : B;
        while (r->next) //顺序不变使用尾插法，遍历至尾节点再进行插入
            r = r->next;
        r->next = p;
        p->next = NULL;
        //更新状态
        p = q;
        flag = (flag == 1) ? 0 : 1;
    }
    return {A, B};
}