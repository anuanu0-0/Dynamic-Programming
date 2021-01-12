#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define ll long long int
// Top Down DP
ll solve_td(ll n, ll m, ll *dp)
{
    if (dp[n] != 0)
        return dp[n];

    if (n == m)
        return 2;
    if (1 <= n && n < m)
        return 1;
    return dp[n] = (solve_td(n - 1, m, dp) % mod + solve_td(n - m, m, dp) % mod) % mod;
}

// Bottom Up DP
ll solve_bu(ll n, ll m, ll *dp)
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i < m)
            dp[i] = dp[i - 1];
        else
            dp[i] = (dp[i - 1] + dp[i - m]) % mod;
    }
    return dp[n];
}

// Driver
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll dp[n + 1] = {0};
        cout << solve_td(n, m, dp) % mod << endl;
        cout << solve_bu(n, m, dp) % mod << endl;
    }
}