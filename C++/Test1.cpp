#include <bits/stdc++.h>
using namespace std;
//������
void swap(int &a, int &b)
{
    int t = a;
    a = b, b = t;
}
//��ֵ
vector<int> _swap(int a, int b)
{
    int t = a;
    a = b, b = t;
    return {a, b};//���ؽ������a,b
}
int main()
{
    int a = 3, b = 5;
    swap(a, b);
    cout << a << b << endl;//���5,3
    _swap(a, b);
    cout << a << b << endl;//���5,3
    return 0;
}