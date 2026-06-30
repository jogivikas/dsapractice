#include <bits/stdc++.h>
using namespace std;

// find previoys smalller elemebt in the stacvck

int main()
{
    vector<int> arr = {3, 1, 0, 8, 6};

    stack<int> s;

    vector<int> ans(arr.size(), 0);

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {

        while (s.size() > 0 && s.top() >= arr[i])
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
    /// print the elemenets;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    return 0;
}