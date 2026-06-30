#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    // DFS helper for cycle detection
    bool dfsindirected(int src, int parent, vector<bool> &vis)
    {
        vis[src] = true;

        for (int neigh : l[src])
        {
            if (!vis[neigh])
            {
                if (dfsindirected(neigh, src, vis))
                    return true;
            }
            else if (neigh != parent)
            {
                return true; // cycle found
            }
        }
        return false;
    }

    // Main cycle check function
    bool iscycle()
    {
        vector<bool> vis(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfsindirected(i, -1, vis))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2); // creates cycle
    g.addEdge(3, 4);

    cout << g.iscycle() << endl;

    return 0;
}