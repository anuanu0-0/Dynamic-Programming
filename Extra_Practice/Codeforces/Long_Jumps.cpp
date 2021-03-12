#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define test  \
    int t;    \
    cin >> t; \
    while (t--)

#define f(i, c, n) for (int i = c; i < n; i++)
#define ii int, int
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define P pair
#define US unordered_set
#define UM unordered_map
#define S set
#define M map
#define fi first
#define sc second
#define pb push_back
#define endl '\n'

#define Fast                           \
    ios_base::sync_with_studio(false); \
    cin.tie();                         \
    cout.tie();

int main()
{
    test
    {
        int n;
        cin >> n;

        vi a(n), dp(n);
        for (int &i : a)
            cin >> i;

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = a[i];
            int j = i + a[i];
            if (j < n)
            {
                dp[i] += dp[j];
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << endl;
    }

    return 0;
}