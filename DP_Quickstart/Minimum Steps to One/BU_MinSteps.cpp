// Time Complexity : 0(n)
// Auxilary Space  : 0(n)
// Problem Statement: Count number of steps to reach 1.

#include <iostream>
#include <climits>
using namespace std;

// BOTTOM UP DP
int minSteps(int n)
{
    int dp[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if (i % 3 == 0)
            op1 = dp[i / 3];
        if (i % 2 == 0)
            op2 = dp[i / 2];
        op3 = dp[i - 1];
        dp[i] = min(op1, min(op2, op3)) + 1;
    }
    return dp[n];
}

// Driver Function
int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << minSteps(n) << '\n';
    return 0;
}