#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        long long c;
        cin >> n >> c >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
        {
            if (a[i] > c)
                break;

            long long use = min(1LL * k, c - a[i]);
            k -= use;
            c += a[i] + use;
        }

        cout << c << '\n';
    }

    return 0;
}