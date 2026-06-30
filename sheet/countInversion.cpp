#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d;
    cin >> d;

    while (d--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long count = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                count++;
            }
            else
            {
                continue;
            }
        }
        cout << count << endl;
    }
}