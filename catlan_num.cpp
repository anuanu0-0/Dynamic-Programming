#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Print Catalan number
//  2nCn/n+1
void printCatlan(int n)
{
    if (n < 0)
        return;
    ll dp[105] = {0};
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            // [i-1][n-1]
            dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }

    cout << dp[n] << endl;
}

int main()
{
    int n;
    cin >> n;
    printCatlan(n);
    return 0;
}