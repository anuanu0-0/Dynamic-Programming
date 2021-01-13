#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Bottom Up DP
ll countStrings(int n)
{
    ll dp[2][n + 1];
    memset(dp, 0, 2 * n * sizeof dp[0][0]);
    dp[0][1] = dp[1][1] = 1;
    ll count = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1];
        count = dp[0][i] + dp[1][i];
    }
    return count;
}

// Same as Fibonnaci Pattern
ll fibOpt_bu(int n)
{
    if (n == 1)
        return 2;
    if (n == 2)
        return 3;
    ll a = 2, b = 3;
    ll c;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // cout << fibOpt_bu(n) << endl;
        cout << countStrings(n) << endl;
    }
}