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
int decode_td(ll *arr, ll len, ll *dp)
{
    if (len == 0 || len == 1)
        return 1;
    if (dp[len] > 0)
        return dp[len];
    ll ans = 0;
    if (arr[len - 1] != 0)
    {
        ans = decode_td(arr, len - 1, dp);
    }
    if (arr[len - 2] != 0 && arr[len - 2] * 10 + arr[len - 1] <= 26)
    {
        ans += decode_td(arr, len - 2, dp) % m;
        ans %= m;
    }
    return dp[len] = ans;
}

// Bottom Up DP
int decode_bu(ll *arr, ll len, ll *dp)
{
    dp[0] = 1;
    dp[1] = 1;

    for (ll i = 2; i <= len; i++)
    {
        if (arr[i - 1] != 0)
            dp[i] = dp[i - 1];
        if (arr[i - 2] * 10 + arr[i - 1] <= 26 && arr[i - 2] != 0)
            dp[i] += dp[i - 2];
    }

    return dp[len];
}

int main()
{
    while (true)
    {
        string s;
        cin >> s;
        if (s == "0")
            break;

        // Special Case
        // if(s[0]=='0') {
        //     cout << 0 << endl;
        //     break;
        // }

        ll len = s.size();
        ll arr[len], dp[len + 1];
        memset(dp, 0, sizeof(dp));
        for (ll i = 0; i < len; i++)
        {
            arr[i] = s[i] - '0';
        }

        // cout << decode_td(arr, len, dp) << endl;
        cout << decode_bu(arr, len, dp) << endl;
    }
}