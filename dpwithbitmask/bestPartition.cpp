#include <bits/stdc++.h>
using namespace std;

int setBits(int m)
{
    int ans = 0;
    while (m > 0)
    {
        ans++;
        // removing  last set bit one by one until the mask become 0//
        m &= (m - 1);
        return ans;
    }
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> reward(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> reward[i][j];
        }
    }
    vector<int> dp(1 << n);

    for (int m = 0; m < (1 << n); ++m)
    {
        // try to find the dp[m];
        // m=00101101
        // subset={0,2,3,5} |{0,1,2,3}//
        int id = setBits(m) - 1;
        for (int i = 0; i < n; i++)
        {
            if (((m >> i) & 1) > 0)
            {
                // i put mask at last then jo bhi bachha hua reh gya h vo uske ander//
                int currRew = reward[i][id];
                int further = dp[m ^ 1 << i];
                dp[m] = max(currRew + further, dp[m]);
            }
        }
    }
    cout << (dp[(1 << n) - 1]);
}