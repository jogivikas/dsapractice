class Solution
{
public:
    int helper(int i, int j, int m, int n, int dp[101][101])

    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int pathsFromRight = helper(i, j + 1, m, n, dp);
        int pathsFromLeft = helper(i + 1, j, m, n, dp);
        return dp[i][j] = pathsFromRight + pathsFromLeft;
    }
    int uniquePaths(int m, int n)
    {
        int dp[101][101] = {-1};
        memset(dp, -1, sizeof(dp));

        return helper(0, 0, m, n, dp);
    }
};