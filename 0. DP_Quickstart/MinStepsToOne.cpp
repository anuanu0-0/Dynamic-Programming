#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 17;
int INF = INT_MAX;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long

// Top Down DP
int minSteps_td(vector<ll> dp, int n)
{
    // Base case
    if (n == 1)
        return 0;

    // Lookup
    if (dp[n] != 0)
        return dp[n];

    int op1 = INF, op2 = INF, op3 = INF;

    if (n % 2 == 0)
        op1 = minSteps_td(dp, n / 2);
    if (n % 3 == 0)
        op2 = minSteps_td(dp, n / 3);
    op3 = minSteps_td(dp, n - 1);
    return dp[n] = min(min(op1, op2), op3) + 1;
}

// Bottom Up Dp
int minSteps_bu(vector<ll> dp, int n)
{
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int op1 = INF, op2 = INF, op3 = INF;
        if (i % 2 == 0)
            op1 = dp[i / 2];
        if (i % 3 == 0)
            op2 = dp[i / 3];

        op3 = dp[i - 1];

        dp[i] = min(min(op1, op2), op3) + 1;
    }

    return dp[n];
}

// Driver
int main()
{
    test
    {
        ll n;
        cin >> n;
        vector<ll> dp(n + 1, 0);

        // Bottom Up
        int res1 = minSteps_bu(dp, n);
        cout << res1 << endl;
        // Top Down
        int res2 = minSteps_td(dp, n);
        cout << res2 << endl;
    }
}