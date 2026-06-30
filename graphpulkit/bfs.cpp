#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n;

vector<int> bfs(int src)
{
	queue<int> q;
	vector<int> dis(n + 1, -1);

	q.push(src);
	dis[src] = 0;

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		// cout << i << ' ';

		for (int nb : adj[i])
		{
			if (dis[nb] != -1)
				continue;

			q.push(nb);
			dis[nb] = dis[i] + 1;
		}
	}

	return dis;
}

void shortestPathNodes(int n, int src, int dest)
{
	vector<int> ds = bfs(src);
	vector<int> dd = bfs(dest);

	if (ds[dest] == -1)
		return;

	for (int i = 1; i <= n; ++i)
	{
		if (ds[i] == -1 or dd[i] == -1)
			continue;

		if (ds[i] + dd[i] == ds[dest])
			cout << i << ' ';
	}
}

int main()
{
	int m;
	cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j;
		cin >> i >> j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	vector<int> d = bfs(1);

	for (int i = 1; i <= n; ++i)
	{
		cout << i << ' ' << d[i] << '\n';
	}

	return 0;
}