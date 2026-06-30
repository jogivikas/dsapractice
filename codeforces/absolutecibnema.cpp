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
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                swap(a[i], b[i]);
            }
            else
            {
                continue;
            }
        }
        int mx = INT_MIN;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, a[i]);
        }
        int x = 0;

        for (int i = 0; i < n; i++)
        {
            x += b[i];
        }
        int y = x + mx;
        cout << y << endl;
    }

    return 0;
}