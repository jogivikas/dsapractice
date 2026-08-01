class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<bool>>> dp(
            n, vector<vector<bool>>(m, vector<bool>(1024, false)));

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int xr = 0; xr < 1024; xr++)
                {
                    if (!dp[i][j][xr])
                        continue;

                    if (i + 1 < n)
                        dp[i + 1][j][xr ^ grid[i + 1][j]] = true;

                    if (j + 1 < m)
                        dp[i][j + 1][xr ^ grid[i][j + 1]] = true;
                }
            }
        }

        for (int xr = 0; xr < 1024; xr++)
        {
            if (dp[n - 1][m - 1][xr])
                return xr;
        }

        return -1;
    }
};