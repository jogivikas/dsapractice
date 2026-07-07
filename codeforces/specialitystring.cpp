#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        stack<char> st;

        for (char ch : s)
        {
            if (!st.empty() && st.top() == ch)
                st.pop();
            else
                st.push(ch);
        }

        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}