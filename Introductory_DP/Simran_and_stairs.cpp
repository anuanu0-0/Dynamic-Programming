// Problem Link : https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/simran-and-stairs/

#include <iostream>
using namespace std;

// Top Down DP
int possibleWays_td(int n, int *dp)
{
    // Base cases
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (dp[n] != 0)
        return dp[n];
    int ans = possibleWays_td(n - 1, dp) + possibleWays_td(n - 2, dp) + possibleWays_td(n - 3, dp);
    return dp[n] = ans;
}

// Bottom Up DP
int possibleWays_bu(int n, int *dp)
{

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    int i;
    for (i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    // cout << possibleWays_td(n, dp) << endl;
    cout << possibleWays_bu(n, dp) << endl;
}