#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        const int INF = 1e9;

        // Case 1: No rearrange
        int ans1 = 0;
        bool ok1 = true;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                ok1 = false;
                break;
            }
            ans1 += a[i] - b[i];
        }

        // Case 2: Rearrange once
        vector<int> x = a, y = b;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int ans2 = c;
        bool ok2 = true;

        for (int i = 0; i < n; i++)
        {
            if (x[i] < y[i])
            {
                ok2 = false;
                break;
            }
            ans2 += x[i] - y[i];
        }

        if (!ok1 && !ok2)
            cout << -1 << '\n';
        else if (!ok1)
            cout << ans2 << '\n';
        else if (!ok2)
            cout << ans1 << '\n';
        else
            cout << min(ans1, ans2) << '\n';
    }

    return 0;
}