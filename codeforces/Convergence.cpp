#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        map<int, int> mp;

        for (int x : a)
        {
            mp[x]++;
        }

        int ans = n;
        int pref = 0;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            int freq = it->second;

            int left = pref;
            int right = n - pref - freq;

            ans = min(ans, max(left, right));

            pref += freq;

            auto nxt = it;
            nxt++;

            if (nxt != mp.end())
            {
                int leftGap = pref;
                int rightGap = n - pref;

                ans = min(ans, max(leftGap, rightGap));
            }
        }

        cout << ans << "\n";
    }

    return 0;
}