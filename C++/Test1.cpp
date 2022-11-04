#include <bits/stdc++.h>
using namespace std;
typedef char SElemType;
//��ջ�Ķ���
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

//��ջ�ĳ�ʼ��
void initStack(LinkStack &S)
{
    S = NULL;
}

//�ж��Ƿ�Ϊ��
bool IsEmpty(LinkStack S)
{
    return S == NULL;
}

//��ջ
bool Push(LinkStack &S, SElemType e)
{
    StackNode *p = new StackNode;
    if (!p)
        return false;
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

//��ջ
bool Pop(LinkStack &S, SElemType &e)
{
    if (!S)
        return false;
    e = S->data;
    StackNode *p = S;
    S = S->next;
    delete p;
    return true;
}

//���ջ
void clearStack(LinkStack &S)
{
    StackNode *p = NULL;
    while (S)
    {
        p = S;
        S = S->next;
        delete p;
    }
}

//����ջ
void destroyStack(LinkStack &S)
{
    clearStack(S);
    S->next = NULL;
}

//ȡջ��Ԫ��
SElemType GetTop(LinkStack S)
{
    if (S == NULL)
        return false;
    return S->data;
}

bool BracketMatching()
{
    LinkStack S;
    initStack(S);
    char c, e;
    bool flag = true;
    while ((c = getchar()) != EOF && flag)
    {
        switch (c)
        {
        case '[':
            Push(S, c);
            break;
        case ']':
            e = GetTop(S);
            if (e != '[')
                flag = false;
            else
                Pop(S, e);
            break;
        case '(':
            Push(S, c);
            break;
        case ')':
            e = GetTop(S);
            if (e != '(')
                flag = false;
            else
                Pop(S, e);
            break;
        default:
            break;
        }
    }
    if (!flag)
        return false;
    return true;
}

int main()
{
    if (BracketMatching())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}