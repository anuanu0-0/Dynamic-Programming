#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 17;
int INF = INT_MAX;
int INFF = INT_MIN;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long

// Top Down DP
int getMinCoins_td(vector<int> dp, int amt, vector<int> coins, int n)
{
    // Base case
    if (amt < 0)
        return -1;
    if (amt == 0)
        return 0;
    // Look up
    if (dp[amt] != 0)
        return dp[amt];

    int ans = INF;
    // Recursive case

    for (int i = 0; i < n; i++)
    {
        if (amt - coins[i] >= 0)
            ans = min(ans, getMinCoins_td(dp, amt - coins[i], coins, n) + 1);
    }
    // return dp[amt] = ans;
    dp[amt] = ans;
    return ans;
    // return dp[amt] == INFF ? -1 : dp[amt];
}

// Bottom Up Dp
int getMinCoins_bu(int amount, vector<int> coins, int n)
{

    auto dp = vector<int>(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < amount + 1; i++)
    {
        for (const auto coinVal : coins)
        {
            if (i - coinVal >= 0 && dp[i - coinVal] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coinVal] + 1);
        }
    }

    return dp.back() == INT_MAX ? -1 : dp.back();
}

// Driver
int main()
{
    int amt, n;
    cin >> amt >> n;

    vector<int> coins(n);
    vector<int> dp(amt + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int res1 = getMinCoins_td(dp, amt, coins, n);
    (res1 == INFF) ? cout << -1 << endl : cout << res1 << endl;
    // cout << res1 << endl;

    int res2 = getMinCoins_bu(amt, coins, n);
    cout << res2 << endl;
}