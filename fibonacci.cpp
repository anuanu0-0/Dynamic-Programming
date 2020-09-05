//  Time Complexity : O(n)
//  Auxilary Space : O(n)
//  For space optimized version Auxilary space can be reduced to O(1).
//  IDEAL APPROACH : Matrix Exponentiation  with TC: O(log n)
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// TOP Down DP
ll fib_TD(ll n, ll dp[])
{
    //Base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    //Look Up
    if (dp[n] != 0)
    {
        return dp[n];
    }

    ll ans = fib_TD(n - 1, dp) + fib_TD(n - 2, dp);
    return dp[n] = ans;
}

// Bottom Up DP
ll fib_BU(ll n, ll dp[])
{
    // ll dp[100] = {0};
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Bottom Up Space Optimized
ll fibSpaceOpt(ll n)
{
    if (n == 0 || n == 1)
        return n;
    ll a = 0;
    ll b = 1;
    ll c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    ll n;
    cin >> n;
    ll dp[100] = {0};
    cout << fib_TD(n, dp) << '\n';
    cout << fib_BU(n, dp) << '\n';
    cout << fibSpaceOpt(n);
}
