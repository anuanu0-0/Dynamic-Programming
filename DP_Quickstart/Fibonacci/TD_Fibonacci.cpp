// Time Complexity : 0(n)
// Space Complexity : 0(n)

#include <iostream>
using namespace std;

// TOP DOWN DP

int fib(int n, int dp[])
{
    // Base Case
    if (n == 0 || n == 1)
        return n;

    // Lookup
    if (dp[n] != 0)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << fib(n, dp) << '\n';
    return 0;
}