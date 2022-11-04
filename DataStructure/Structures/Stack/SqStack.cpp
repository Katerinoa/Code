#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef int SElemType;
//˳��ջ�Ķ���
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

//˳��ջ�ĳ�ʼ��
bool initStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        return false;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return true;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
    return S.base == S.top;
}
//��ջ�ĳ���
int StackLength(SqStack S)
{
    return S.top - S.base;
}
//���ջ
bool clearStack(SqStack S)
{
    if (S.base)
    {
        S.top = S.base;
        return true;
    }
    return false;
}
//����ջ
bool destroyStack(SqStack S)
{
    if (S.base)
    {
        delete S.base;
        S.stacksize = 0;
        S.top = S.base = NULL;
        return true;
    }
    return false;
}
//��ջ
bool Push(SqStack S, SElemType e)
{
    if (S.top - S.base == S.stacksize)
        return false;
    *S.top++ = e;
    return true;
}
//��ջ
bool Pop(SqStack S, SElemType &e)
{
    if (S.top == S.base)
        return false;
    e = *--S.top;
    return true;
}
//ȡջ��Ԫ��
bool getTop(SqStack S, SElemType &e)
{
    if (S.top == S.base)
        return false;
    e = *(S.top - 1);
    return true;
}