#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef struct StackNode
{
    char elem;
    StackNode *next;
} SNode, *LinkStack;

bool Push(LinkStack &, char);    //�Ž��ƶ�
char Pop(LinkStack &);           //�ó��ƶ�
bool initStack(LinkStack &);     //��ʼ��ջ
int searchCard(LinkStack, char); //����ָ����
