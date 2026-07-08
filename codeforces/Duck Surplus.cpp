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

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                arr[i + 1] += arr[i];
                swap(arr[i + 1], arr[i + 1]);
            }
        }

        sort(arr.begin(), arr.end());
        cout << arr[n - 1] << endl;
    }

    return 0;
}