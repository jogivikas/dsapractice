#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion
{
    vector<int> par;
    vector<int> rank;

public:
    DisjointSetUnion(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }

        return par[x] = find(par[x]); // Path Compression
    }

    void unionByRank(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        if (parA == parB)
            return;

        if (rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
        {
            par[parB] = parA;
        }
        else
        {
            par[parA] = parB;
        }
    }
};

int main()
{
    DisjointSetUnion dsu(6);

    dsu.unionByRank(0, 2);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(1, 3);
    dsu.unionByRank(2, 5);
    dsu.unionByRank(0, 3);

    cout << dsu.find(2) << endl;

    dsu.unionByRank(0, 4);

    return 0;
}