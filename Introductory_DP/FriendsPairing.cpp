// Question: https://www.spoj.com/problems/ACODE/
// Introductory DP
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long int
ll m = 1000000000 + 7;

// Top Down DP
ll fpair(int n, ll *dp)
{
    if (dp[n] != 0)
        return dp[n];

    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return dp[n] = fpair(n - 1, dp) + (n - 1) * fpair(n - 2, dp);
}

// Bottom Up DP
ll fpair_bu(int n)
{
    ll dp[n + 1] = {0};
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll dp[n + 1] = {0};
        cout << fpair(n, dp) << endl;
        cout << fpair_bu(n) << endl;
    }
}