#include <iostream>
using namespace std;

// TOP DOWN DP
int fib_td(int n, int *dp)
{
    // Base Case
    if (n == 0 || n == 1)
        return n;

    // Lookup
    if (dp[n] != 0)
        return dp[n];

    return dp[n] = fib_td(n - 1, dp) + fib_td(n - 2, dp);
}

// BOTTOM UP DP
//  Auxilary Space : 0(n)
int fib_bu(int n)
{
    int dp[100] = {0};
    dp[1] = 1;
    for (int i = 2; i <= 2; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// BOTTOM UP OPTIMIZED
//  Auxilary Space : 0(1)
int fibOpt_bu(int n)
{
    if (n == 0 || n == 1)
        return n;
    int a = 0, b = 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Driver function
int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << fib_td(n, dp) << '\n';
    cout << fib_bu(n) << '\n';
    cout << fibOpt_bu(n) << '\n';
    return 0;
}