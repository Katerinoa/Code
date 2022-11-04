#include <bits/stdc++.h>
using namespace std;

int Next[20];

void get_next(string T)
{
    int i = 1, j = 0;
    Next[1] = 0;
    while (j < T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
            i++;
            j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}

int KMP(string S, string T, int pos)
{
    int i = pos, j = 1;
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
            j = Next[j];
    }
}