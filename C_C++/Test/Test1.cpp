#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {5, 6, 7}, {4, 1, 8, 3}};
    int m = triangle.size();
    int dp[2][m + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < m; i++)
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
                dp[i & 1][j] = triangle[i][j] + dp[(i - 1) & 1][j];
            else if (j == i)
                dp[i & 1][j] = triangle[i][j] + dp[(i - 1) & 1][j - 1];
            else
                dp[i & 1][j] = triangle[i][j] + min(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - 1]);
        }
    int min = 1e7;
    for (int i = 0; i < m; i++)
        min = dp[(m - 1) & 1][i] < min ? dp[(m - 1) & 1][i] : min;
    cout << min << endl;
}