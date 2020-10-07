#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1e9 + 7;

// Top Down DP
int tilling(int n, int m, vector<int> dp)
{
    // Case 1:
    if (n < m || n == 1 && m == 1)
        return 1;
    // Case 2:
    if (n < 1 || m < 1)
        return 0;

    // Case 3:
    if (n == m)
        return 2;

    if (dp[n] != 0)
        return dp[n] % mod;

    int res = (tilling(n - 1, m, dp) % mod + tilling(n - m, m, dp) % mod) % mod;
    return dp[n] = res % mod;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> dp(n + 1, 0);
        cout << tilling(n, m, dp) << endl;
    }
    return 0;
}
