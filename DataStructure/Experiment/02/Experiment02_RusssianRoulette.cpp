#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int elem; //赌徒编号
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
        L->elem = 0; //头结点编号为0
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
    if (q->elem == 0) //如果是头节点则跳过
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
    srand((unsigned)time(NULL)); //随机数种子
    CircularList L = NULL;
    CreatList(L); //创建循环链表
    int num, m;
    cout << "输入赌徒的人数: ";
    cin >> num;
    InitList(L, num); //初始化循环链表
    cout << "将赌徒编号为 1-" << num << endl;
    Node *p = L->next; // p指针指向第一个赌徒
    for (int round = 1; round < num; round++)
    {
        m = (rand() % 6 + 1); //产生一个1-6之间的随机数
        cout << "第" << round << "轮开始，从编号为" << p->elem << "的人开始，枪在第" << m << "次扣动扳机时会响" << endl;
        for (int j = 1; j < m; j++)
        {
            p = p->next;
            if (p == L)
                p = p->next;
        }
        cout << "编号为" << p->elem << "的赌徒退出赌博,剩余赌徒编号依次为: " << endl;
        p = DeleteNode(p);
        PrintList(L);
    }
    cout << "最终胜利的赌徒编号是: " << p->elem << endl;
    return 0;
}
