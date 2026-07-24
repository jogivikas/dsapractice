class Solution
{
public:
    void dfs(int u, vector<vector<int>> &adj, vector<int> &vis, int mask)
    {
        vis[u] = 1;

        for (int v : adj[u])
        {
            if (!(mask & (1 << v)))
                continue; // node subset me nahi hai

            if (!vis[v])
                dfs(v, adj, vis, mask);
        }
    }

    int evenSumSubgraphs(vector<int> &nums, vector<vector<int>> &edges)
    {

        int n = nums.size();

        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        // Enumerate all non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++)
        {

            int sum = 0;
            int cnt = 0;
            int start = -1;

            // Calculate sum and count selected nodes
            for (int i = 0; i < n; i++)
            {

                if (mask & (1 << i))
                {
                    sum += nums[i];
                    cnt++;

                    if (start == -1)
                        start = i;
                }
            }

            // Sum should be even
            if (sum % 2 != 0)
                continue;

            vector<int> vis(n, 0);

            dfs(start, adj, vis, mask);

            int visited = 0;

            for (int i = 0; i < n; i++)
            {
                if ((mask & (1 << i)) && vis[i])
                    visited++;
            }

            if (visited == cnt)
                ans++;
        }

        return ans;
    }
};