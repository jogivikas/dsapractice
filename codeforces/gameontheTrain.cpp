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
        vector<int> h(n);

        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {

            maxi = max(h[i], maxi);
            mini = min(h[i], mini);
        }

        int k = maxi - mini + 1;

        cout << k << endl;
    }
    return 0;
}