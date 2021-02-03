#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> v)
{
    vector<int> dp(v.size() + 1, 0);
    dp[0] = v[0] > 0 ? v[0] : 0;
    int maxSum = dp[0];

    for (int i = 1; i < v.size(); i++)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        maxSum = max(dp[i], maxSum);
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << maxSubarraySum(v) << endl;
}