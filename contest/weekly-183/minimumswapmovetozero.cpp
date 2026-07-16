#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &v, int n)
{
    int cnt = 0;

    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        while (l < r && v[r] == 0)
        {
            r--;
        }
        if (l < r && v[l] == 0)
        {
            swap(v[l], v[r]);
            cnt++;
            r--;
        }
        l++;
    }
    return cnt;
}
int main()

{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << count(v, n) << endl;

    return 0;
}