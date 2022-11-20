#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node, *LinkList;

void creatList(LinkList &L)
{
    if (L != NULL)
    {
        cout << "该链表已创建！" << endl;
        return;
    }
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    cout << "链表创建成功！" << endl;
}
void addElement(LinkList L)
{
    Node *tail = L;
    while (tail->next != NULL)
        tail = tail->next; //遍历至尾节点

    int input, num;
    cout << "请输入要添加的元素个数: ";
    cin >> num;
    cout << "请一次性输入所有要添加的元素:" << endl;
    while (num--)
    {
        //创建新节点并初始化
        cin >> input;
        Node *newNode = (LinkList)malloc(sizeof(Node));
        newNode->data = input;
        newNode->next = NULL;
        //尾节点指向新节点
        tail->next = newNode;
        //新节点成为尾节点
        tail = newNode;
    }
}
void printList(const LinkList L)
{
    if (L->next == NULL)
    {
        cout << "链表为空！" << endl;
        return;
    }
    Node *p = L->next;
    cout << "链表中的元素" << endl;
    while (p != NULL)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
void ReverseList1(LinkList L)
{
    //利用头插法逆转链表
    Node *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}
void ReverseList2(LinkList L)
{
    //使用指针逆转链表
    Node *pre, *p, *r;
    p = L->next;
    r = p->next;
    pre = NULL;

    p->next = NULL;
    while (r != NULL)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
}
void deleteNextNode(Node *p)
{
    Node *DeletedNode = p->next;
    if (p->next->next)
        p->next = p->next->next;
    else
        p->next = NULL;
    free(DeletedNode);
}
Node *FindMaxValueNode(LinkList L)
{
    Node *MaxValueNode = L->next;
    Node *p = L->next;
    int currentMaxValue = -1e7;
    while (p != NULL)
    {
        if (p->data > currentMaxValue)
        {
            MaxValueNode = p;
            currentMaxValue = p->data;
        }
        p = p->next;
    }
    return MaxValueNode;
}
void Intersection(LinkList L1, LinkList L2)
{
    int maxValue = FindMaxValueNode(L2)->data;
    Node *p1, *p2;
    p1 = L1, p2 = L2;
    while (p1->next != NULL)
    {
        while (p2->next != NULL)
        {
            if (p2->next->data == p1->next->data)
                break;
            else if (p2->next->data > p1->next->data)
            {
                deleteNextNode(p1);
                continue;
            }
            p2 = p2->next;
        }
        if (p1->next->data > maxValue)
        {
            deleteNextNode(p1);
            continue;
        }
        p1 = p1->next;
    }
}
void mergeList(LinkList L1, LinkList L2)
{
    Node *p1, *p2, *r1, *r2;
    p1 = L1->next, p2 = L2->next;
    L1->next = NULL; //合并后的链表的头结点
    while (p1 && p2)
    {
        if (p1->data <= p2->data)
        {
            r1 = p1->next;
            p1->next = L1->next;
            L1->next = p1;
            p1 = r1;
        }
        else
        {
            r2 = p2->next;
            p2->next = L1->next;
            L1->next = p2;
            p2 = r2;
        }
    }
    while (p1)
    {
        r1 = p1->next;
        p1->next = L1->next;
        L1->next = p1;
        p1 = r1;
    }
    while (p2)
    {
        r2 = p2->next;
        p2->next = L1->next;
        L1->next = p2;
        p2 = r2;
    }
}
int main()
{
    LinkList A = NULL;
    LinkList B = NULL;
    creatList(A);
    creatList(B);
    addElement(A);
    addElement(B);
    mergeList(A, B);
    printList(A);
}