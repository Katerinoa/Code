#include "CardsStack.h"
#include <bits/stdc++.h>

//放进牌堆,入栈成功返回true，否则返回false
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
//拿出牌堆,出栈成功返回出栈元素值，否则返回0
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
//初始化栈
bool initStack(LinkStack &S)
{
    S = NULL;
    return true;
}
//查找指定牌，若查找成功返回下标+1，否则返回0
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