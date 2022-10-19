#pragma once
#include <bits/stdc++.h>
#include "Cars.h"
using namespace std;

typedef struct QNode
{
    Cars* elem;
    QNode *next;
} QNode;

class ShortCut
{
public:
    ShortCut();
    ~ShortCut();
    bool QueneEmpty();
    void EnterCut(Cars* car);
    Cars* LeaveCut();
    int countCars();

private:
    QNode *front;
    QNode *rear;
};
