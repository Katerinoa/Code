#pragma once
#include "Cars.h"
#include <bits/stdc++.h>
using namespace std;
class ParkingStack
{
public:
    ParkingStack(int stackSize);
    ~ParkingStack();
    int countCars() const;
    int countEmpty() const;
    int getCarIndex(char *targetLicense);
    bool StackEmpty() const;
    bool StackFull() const;
    void printStack();
    void queryCars(char *license);
    void clearStack();
    void EnterParking(Cars *car);
    Cars *LeaveParking();
    Cars *getCar(int index);
    Cars **getTopPointer();

private:
    Cars **base;
    Cars **top;
    int stackSize;
};
