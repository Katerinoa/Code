#include <bits/stdc++.h>
using namespace std;
//传引用
void swap(int &a, int &b)
{
    int t = a;
    a = b, b = t;
}
//传值
vector<int> _swap(int a, int b)
{
    int t = a;
    a = b, b = t;
    return {a, b};//返回交换后的a,b
}
int main()
{
    int a = 3, b = 5;
    swap(a, b);
    cout << a << b << endl;//输出5,3
    _swap(a, b);
    cout << a << b << endl;//输出5,3
    return 0;
}