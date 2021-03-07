// Time Complexity : O(n^2)
// Problem Statement: Given n wines in a row, with integers denoting the cost of each wine respectively.
//   Each year you can sale the first or the last wine in the row. However, the price of wines increases over time.
//   Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from the ith wine will be Y*Pi.
//   Calculate the maximum profit from all the wines.

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 17;
int INF = INT_MAX;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define vi vector<int>

// Top Down DP
int maxProfit_td(int *wines, int i, int j, int y, int dp[][100])
{
    //  Base Case
    if (i > j)
        return 0;

    //Look Up
    if (dp[i][j] != 0)
        return dp[i][j];
    //  Recursive Case
    int op1 = wines[i] * y + maxProfit_td(wines, i + 1, j, y + 1, dp);
    int op2 = wines[j] * y + maxProfit_td(wines, i, j - 1, y + 1, dp);

    return dp[i][j] = max(op1, op2);
}
// Bottom Up Dp
int maxProfit_bu(int *wines, int n)
{
    int dp[100][100] = {0};
    // Wines array size
    int year = n;
    // Fill the diagonal elements i.e leaf nodes in case of recursion tree
    for (int i = 0; i < n; i++)
        dp[i][i] = year * wines[i];

    year--;

    // For remaining upper triangle
    for (int len = 2; len <= n; len++)
    {
        int start = 0, end = n - len;
        while (start <= end)
        {
            int cur = start + end - 1;
            dp[start][cur] = max(wines[start] * year + dp[start + 1][cur], wines[cur] * year + dp[start][cur - 1]);
            start++;
        }
        year--;
    }
    return dp[0][n - 1];
}

// Driver
int main()
{
    int n;
    cin >> n;
    int wines[n];
    for (int i = 0; i < n; i++)
        cin >> wines[i];

    int dp[100][100] = {0};
    cout << maxProfit_td(wines, 0, n - 1, 1, dp) << endl;
    cout << maxProfit_bu(wines, n) << endl;

    return 0;
}