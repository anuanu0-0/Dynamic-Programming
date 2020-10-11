// Time Complexity : 0(cn), where c in the no. of coins
// Problem Statement: What is the minimum no. of coin change for a given denomination.

#include <iostream>
#include <climits>
using namespace std;

// TOP DOWN DP
int getMinCoins(int n, int coins[], int T, int dp[])
{ //  Base Case
    if (n == 0)
        return 0;

    //  Lookup
    if (dp[n] != 0)
        return dp[n];
    //  Rec Case
    int ans = INT_MAX;
    for (int i = 0; i < T; i++)
    {
        if (n - coins[i] >= 0)
        {
            int subprob = getMinCoins(n - coins[i], coins, T, dp);
            ans = min(ans, subprob + 1);
        }
    }

    return dp[n] = ans;
}

// Driver Function
int main()
{
    int n, c;
    cin >>
        n >> c;
    int coins[c];
    int dp[100] = {0};
    for (int i = 0; i < c; i++)
    {
        cin >> coins[i];
    }

    cout << getMinCoins(n, coins, c, dp) << '\n';

    return 0;
}