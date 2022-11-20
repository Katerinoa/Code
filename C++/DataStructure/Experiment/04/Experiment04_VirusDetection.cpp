#include <bits/stdc++.h>
#define MAXLENGTH 100
using namespace std;
int Next[MAXLENGTH];
char inPath[MAXLENGTH], outPath[MAXLENGTH];

void getNext(string T)
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < T.size() - 1)
    {
        if (j == -1 || T[i] == T[j])
        {
            i++;
            j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}
bool KMP(string S, string T)
{
    getNext(T);
    int i = 0, j = 0;
    int len_s = S.size(), len_t = T.size();
    while (i < len_s && j < len_t)
    {
        if (j == -1 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
            j = Next[j];
    }
    if (j >= len_t)
        return true;
    else
        return false;
}

bool judge(string T, string str)
{
    string S = str + str;
    return KMP(S, T);
}

void fileOperate()
{
    //打开文件
    ifstream infile;
    ofstream outfile;
    infile.open(inPath, ios::in);
    outfile.open(outPath, ios::out);
    //判断文件状态
    if (!infile.is_open())
    {
        cout << "读入文件打开失败!" << endl;
        return;
    }
    if (!outfile.is_open())
    {
        cout << "写入文件打开失败!" << endl;
        return;
    }

    int n = 0;
    infile >> n; //读入第一行的数据数量
    while (n--)
    {
        string S, T;
        infile >> S >> T; //从文件中顺序读取字符串
        outfile << left << setw(10) << S << setw(20) << T;
        if (judge(S, T))
            outfile << left << setw(30) << "YES" << endl; //对齐输出
        else
            outfile << left << setw(30) << "NO" << endl;
    }
    //关闭文件
    infile.close();
    outfile.close();
    cout << "File Operate Done!" << endl;
}
int main()
{
    cout << "请输入要读取的文件路径" << endl;
    cin >> inPath;
    cout << "请输入要写入的文件路径" << endl;
    cin >> outPath;

    fileOperate();
    return 0;
}
