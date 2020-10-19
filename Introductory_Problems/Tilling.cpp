// Time Complexity :
//  Problem Statement : Given a floor of size n x m. Find the number of ways to tile the floor with tiles of
//                      size 1 x m. A tile can either be placed horizontally or vertically.

#include <iostream>
using namespace std;
#define MAX 1000000007
#define ll long long int

// Bottom Up DP
ll tilling(int n, int m)
{
    ll dp[100001] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (i > m)
            dp[i] = (dp[i - 1] + dp[i - m]) % MAX;
        else if (i < m)
            dp[i] = 1;
        else
            dp[i] = 2;
    }
    return dp[n];
}

// Top Down DP

// Driver Function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        cout << tilling(n, m) << '\n';
    }
    return 0;
}