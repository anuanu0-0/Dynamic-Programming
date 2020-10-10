// Time Complexity : 0(n)
// Problem Statement: Count number of steps to reach 1.

#include <iostream>
#include <climits>
using namespace std;

// TOP DOWN DP
int minSteps(int n, int dp[])
{
    //  Base Case
    if (n == 1)
        return 0;

    //  Look up
    if (dp[n] != 0)
        return dp[n];

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if (n % 3 == 0)
        op1 = minSteps(n / 3, dp);
    if (n % 2 == 0)
        op2 = minSteps(n / 2, dp);
    op3 = minSteps(n - 1, dp);
    return dp[n] = min(min(op1, op2), op3) + 1;
}

// Driver Function
int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << minSteps(n, dp) << '\n';
    return 0;
}