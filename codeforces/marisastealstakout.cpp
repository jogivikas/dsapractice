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

        vector<int> v;
        int count = 0;
        int sum = 0;
        vector<int> w(n);
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }

        for (int i = 0; i < n; i++)

        {
            if (w[i] % 3 == 0)
            {
                v.push_back(w[i]);
            }
        }
    }
    return 0;
}