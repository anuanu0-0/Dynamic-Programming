#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Bottom Up DP
ll coin_change(ll *coins, int n, int m)
{
    ll dp[n + 1] = {0};
    dp[0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = coins[i]; j <= n; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        ll coins[n];
        for (int i = 0; i < m; i++)
            cin >> coins[i];
        sort(coins, coins + m);
        cout << coin_change(coins, n, m);
    }
}