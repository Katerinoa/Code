#include <iostream>
#include <cstring>//?
#include <string>
#include <vector> //这里指查找单词，用vector容器存储每一个单词再遍历即可
using namespace std;

int main()
{
    string select, words;
    int sum = 0;
    cin >> select;
    vector<string> sentence;
    while (cin >> words)
    {
        sentence.push_back(words);
    }
    for (vector<string>::iterator it = sentence.begin(); it != sentence.end(); it++)
    {
        string index = *it;
        int temp = strcmp(select.c_str(), index.c_str());
        if (temp == 0)
        {
            sum++;
        }
    }
    if (sum > 0)
    {
        cout << sum << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    system("pause");
    return 0;
}