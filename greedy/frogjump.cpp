#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> d;

    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    int currId = 0;
    int minJump = 0;

    while (currId < n)
    {
        int nextId = currId;
        int currDist = 0;

        while (nextId + 1 <= n && currDist + d[nextId] <= k)
        {
            currDist += d[nextId];
            nextId += 1;
        }

        currId = nextId;
        minJump += 1;
    }
    cout<<minJump<<endl;
}