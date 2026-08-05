class Solution
{
public:
    int mini(int i, int j, vector<vector<int>> &matrix,
             vector<vector<int>> &dp, int n)
    {
        // Out of bounds
        if (j < 0 || j >= n)
            return 1e9; // A large value instead of INT_MAX

        // Last row
        if (i == n - 1)
            return matrix[i][j];

        // Already computed
        if (dp[i][j] != 1e9)
            return dp[i][j];

        int down = mini(i + 1, j, matrix, dp, n);
        int left = mini(i + 1, j - 1, matrix, dp, n);
        int right = mini(i + 1, j + 1, matrix, dp, n);

        dp[i][j] = matrix[i][j] + min(down, min(left, right));

        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        int ans = 1e9;

        // Try every starting column
        for (int j = 0; j < n; j++)
        {
            ans = min(ans, mini(0, j, matrix, dp, n));
        }

        return ans;
    }
};