
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Bottom Up DP
// Time Complexity : O(n^2)
// Auxilary Space : O(n)
int lis(ll nums[], int n)
{
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                // Some prev smaller value exists
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    ll res = dp[0];
    for (ll i = 0; i < n; i++)
    {
        if (dp[i] > res)
            res = dp[i];
    }
    return res;
}

// Optimized solution : DP + Binary Search
// Time Complexity : O(nlogn)
// TO DO

int main()
{
    ll n;
    cin >> n;

    ll nums[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << lis(nums, n) << endl;
}