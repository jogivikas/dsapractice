#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        bool ok = true;

        for (int i = 0; i < k; i++)
        {
            int one = 0;

            for (int j = i; j < n; j += k)
            {
                if (s[j] == '1')
                    one++;
            }

            if (one % 2 != 0)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}