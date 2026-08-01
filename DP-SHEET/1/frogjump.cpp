class Solution
{
public:
    int helper(vector<int> &height, int i, vector<int> &dp)
    {
        int n = height.size();

        if (i == n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int oneJump = abs(height[i] - height[i + 1]) +
                      helper(height, i + 1, dp);

        int twoJump = INT_MAX;
        if (i + 2 < n)
            twoJump = abs(height[i] - height[i + 2]) +
                      helper(height, i + 2, dp);

        return dp[i] = min(oneJump, twoJump);
    }

    int minCost(vector<int> &height)
    {
        vector<int> dp(height.size(), -1);
        return helper(height, 0, dp);
    }
};