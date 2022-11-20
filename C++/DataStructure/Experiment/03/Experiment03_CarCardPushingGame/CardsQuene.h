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

char PlayCards(CQuene &);      //出牌
bool GetCards(CQuene &, char); //拿牌
bool initQuene(CQuene &);      //初始化队列
bool QueneEmpty(CQuene &);     //判断队列空
int countCards(CQuene &);      //队列元素计数
