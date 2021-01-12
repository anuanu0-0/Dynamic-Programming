// Problem Link: https://codezen.codingninjas.com/practice/471/852/min-steps-to-one-using-dp

#include <bits/stdc++.h>
using namespace std;

// Top Down DP
int countStepsToOne_td(int n, int *dp)
{
    if (n <= 1)
        return 0;

    if (dp[n] != 0)
        return dp[n];
    int n1, n2, n3;
    n1 = n2 = n3 = INT_MAX;
    if (n % 2 == 0)
        n1 = countStepsToOne_td(n / 2, dp);
    if (n % 3 == 0)
        n2 = countStepsToOne_td(n / 3, dp);

    n3 = countStepsToOne_td(n - 1, dp);

    dp[n] = min(min(n1, n2), n3) + 1;
    return dp[n];
}

// Bottom up DP
int countStepsToOne_bu(int n, int *dp)
{

    dp[0] = dp[1] = 0;
    dp[2] = dp[3] = 1;
    int n1, n2, n3;
    for (int i = 4; i <= n; i++)
    {

        n1 = n2 = n3 = INT_MAX;
        if (i % 2 == 0)
            n1 = dp[i / 2];
        if (i % 3 == 0)
            n2 = dp[i / 3];
        n3 = dp[i - 1];
        dp[i] = min(min(n1, n2), n3) + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    cout << countStepsToOne_td(n, dp) << endl;
    cout << countStepsToOne_bu(n, dp) << endl;
}