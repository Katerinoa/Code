#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> obstacleGrid = {{1,2,3}, {4,5,6}};
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = obstacleGrid[0][0];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + obstacleGrid[i][j];
            else if (i > 0)
                dp[i][j] = dp[i - 1][j] + obstacleGrid[i][j];
            else if (j > 0)
                dp[i][j] += dp[i][j - 1] + obstacleGrid[i][j];
        }
    cout << dp[m - 1][n - 1] << endl;
}