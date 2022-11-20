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
    void printQuene();
    int countCars();
    int getCarIndex(char *targetLicense);
    Cars *LeaveCut();
    Cars *getCar(char *targetLicense);

private:
    QNode *front;
    QNode *rear;
};
