#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> a;
    char input;
    while ((input = getchar()) != EOF)
        a.push_back(input);
    a[0] = toupper(a[0]);
    for (int i = 1; i < a.size(); i++)
    {
        char m = a[i];
        if (!isalpha(a[i]))
            continue;
        else if (isspace(a[i - 1]))
            a[i] = toupper(a[i]);
        else
            a[i] = tolower(a[i]);
    }
    for (vector<char>::iterator i = a.begin(); i != a.end(); i++)
        cout << *i;
    return 0;
}

// for（i）
// {
//     if（a[i] 不是字母）下一次循环
//     else if（a[i - 1] 是空格）a[i]
//     大写 else if（a[i - 1] 是字母）a[i] 小写
// }
