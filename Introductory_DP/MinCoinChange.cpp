#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Bottom Up DP
ll min_coin_change(ll *coins, int n, int m)
{
    vector<ll> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (coins[i] <= j)
            {
                // cout << j << ": " << dp[j] << " " << dp[j - coins[i]] + 1 << " :";
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                // cout << dp[j] << endl;
            }
        }
    }
    if (dp[n] != INT_MAX)
        return dp[n];
    else
        return -1;
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
        // sort(coins, coins + m);
        cout << min_coin_change(coins, n, m);
    }
}