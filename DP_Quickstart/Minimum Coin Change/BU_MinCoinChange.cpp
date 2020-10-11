// Time Complexity : 0(cn), where c in the no. of coins
// Problem Statement: What is the minimum no. of coin change for a given denomination.

#include <iostream>
#include <climits>
using namespace std;

// BOTTOM UP DP
int getMinCoins(int n, int coins[], int T)
{
    int dp[100] = {0};

    // Iterate over all states 1..N
    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < T; j++)
        {
            if (i - coins[j] >= 0)
            {
                int subprob = dp[i - coins[j]];
                dp[i] = min(dp[i], subprob + 1);
            }
        }
    }
    return dp[n];
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

    cout << getMinCoins(n, coins, c) << '\n';

    return 0;
}