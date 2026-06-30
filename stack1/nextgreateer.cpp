#include <bits/stdc++.h>
using namespace std;
/// find the next grater ele

int main()
{
    vector<int> arr = {6, 8, 0, 1, 3};

    int n = arr.size() - 1;
    vector<int> ans(arr.size(), 0);
    stack<int> s;
    for (int i = n; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    // print ans

    for (int i = 0; i < ans.size(); i++)

    {
        cout << ans[i];
    }

    return 0;
}