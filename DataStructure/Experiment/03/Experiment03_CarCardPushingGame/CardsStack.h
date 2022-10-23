#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef struct StackNode
{
    char elem;
    StackNode *next;
} SNode, *LinkStack;

bool Push(LinkStack &, char);    //放进牌堆
char Pop(LinkStack &);           //拿出牌堆
bool initStack(LinkStack &);     //初始化栈
int searchCard(LinkStack, char); //查找指定牌
