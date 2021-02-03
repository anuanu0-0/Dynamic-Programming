#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define db(x) cout << #x << ": " << x << '\n';

const int N = 1005;
bool dp[N][N];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        string s;
        cin >> s;
        for (i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for (int sz = 2; sz <= n; sz++)
        {
            for (i = 0; i + sz - 1 < n; i++)
            {
                int start = i, end = i + sz - 1;
                if (sz == 2)
                {
                    dp[start][end] = (s[start] == s[end]);
                }
                else
                {
                    dp[start][end] = (s[start] == s[end]) && (dp[start + 1][end - 1]);
                }
            }
        }
        // queries whether l to r plaindrome ?
        cin >> m;
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << (dp[l][r] ? "YES" : "NO") << '\n';
        }
    }
