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

    void printAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << " : ";
            for (int neigh : l[i])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    void bfs(int start)
    {
        queue<int> q;
        vector<bool> vis(v, false);

        q.push(start);
        vis[start] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            for (int neigh : l[curr])
            {
                if (!vis[neigh])
                {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout << endl;
    }

    // ✅ DFS inside class
    void dfs(int node, vector<bool> &vis)
    {
        cout << node << " ";
        vis[node] = true;

        for (int neigh : l[node])
        {
            if (!vis[neigh])
            {
                dfs(neigh, vis);
            }
        }
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.printAdjList();

    cout << "BFS: ";
    g.bfs(0);

    cout << "DFS: ";
    vector<bool> vis(5, false);
    g.dfs(0, vis);

    return 0;
}