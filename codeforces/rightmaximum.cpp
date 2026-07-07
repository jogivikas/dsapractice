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

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int count = 0;

        while (!arr.empty())
        {
            int maxi = *max_element(arr.begin(), arr.end());

            int k = 0;

            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i] == maxi)
                    k = i;
            }

            arr.erase(arr.begin() + k, arr.end());

            count++;
        }

        cout << count << "\n";
    }

    return 0;
}