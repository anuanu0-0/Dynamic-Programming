#include <iostream>
#include <climits>

using namespace std;
// Top Down DP
int minCoinChangeTD(int n, int dp[], int coins[], int c)
{
	// Base Case
	if (n == 0)
		return 0;
	// Lookup
	if (dp[n] != 0)
		return dp[n];
	int ans = INT_MAX;
	for (int i = 0; i < c; i++)
	{
		ans = min(ans, minCoinChangeTD(n - coins[i], dp, coins, c) + 1);
	}
	return dp[n] = ans;
}

// Bottom Up DP
int minCoinChangeBU(int n, int coins[], int c)
{
	int dp[100] = {0};

	// Iterate over all the states
	for (int i = 1; i <= n; i++)
	{
		// Make current ans as INT_MAX
		dp[i] = INT_MAX;
		for (int j = 0; j < c; j++)
		{
			if (i - coins[j] >= 0)
			{
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[n];
}

int main()
{
	int n, c;
	cin >> n >> c;
	int coins[c];
	for (int i = 0; i < c; i++)
		cin >> coins[i];
	// Considering n=100 is the largest considerable value
	int dp[100] = {0};
	cout << minCoinChangeTD(n, dp, coins, c) << endl;
	cout << minCoinChangeBU(n, coins, c);
	return 0;
}
