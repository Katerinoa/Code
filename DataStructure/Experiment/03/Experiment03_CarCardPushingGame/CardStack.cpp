#include "CardsStack.h"
#include <bits/stdc++.h>

//�Ž��ƶ�,��ջ�ɹ�����true�����򷵻�false
bool Push(LinkStack &S, char cardValue)
{
    SNode *p = new SNode;
    if (!p)
        return false;
    p->elem = cardValue;
    p->next = S;
    S = p;
    return true;
}
//�ó��ƶ�,��ջ�ɹ����س�ջԪ��ֵ�����򷵻�0
char Pop(LinkStack &S)
{
    if (!S)
        return 0;
    SNode *p = S;
    char cardValue = 0;
    cardValue = p->elem;
    S = S->next;
    delete p;
    return cardValue;
}
//��ʼ��ջ
bool initStack(LinkStack &S)
{
    S = NULL;
    return true;
}
//����ָ���ƣ������ҳɹ������±�+1�����򷵻�0
int searchCard(LinkStack S, char targetValue)
{
    int index = 1;
    SNode *p = S;
    while (p != NULL)
    {
        if (p->elem == targetValue)
            return index;
        p = p->next;
        index++;
    }
    return 0;
}