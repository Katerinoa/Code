#pragma once
typedef struct QueneNode
{
    char elem;
    QueneNode *next;
} QNode;
typedef struct CardsQuene
{
    QNode *front;
    QNode *rear;
} CQuene;

char PlayCards(CQuene &);      //����
bool GetCards(CQuene &, char); //����
bool initQuene(CQuene &);      //��ʼ������
bool QueneEmpty(CQuene &);     //�ж϶��п�
int countCards(CQuene &);      //����Ԫ�ؼ���
