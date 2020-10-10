// Time Complexity : 0(n)

#include <iostream>
using namespace std;

//  BOTTOM DP
//  Auxilary Space : 0(n)
int fib(int n)
{
    int dp[100] = {0};
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//  BOTTOM UP OPTIMIZED
//  Auxilary Space : 0(1)
int fibOpt(int n)
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

// Driver Function
int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << fib(n) << '\n';
    cout << fibOpt(n) << '\n';
    return 0;
}