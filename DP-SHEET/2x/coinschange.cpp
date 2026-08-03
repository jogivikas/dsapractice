class Solution
{
public:
    int helper(vector<int> &coins, int amount, int i, int dp[10001][13])
    {
        int n = coins.size();

        // Base cases
        if (amount == 0)
            return 0;

        if (i >= n)
            return 1e9; // Impossible

        if (dp[amount][i] != -1)
            return dp[amount][i];

        int op1 = 1e9, op2;

        // Take the coin (stay at same index)
        if (amount >= coins[i])
        {
            op1 = 1 + helper(coins, amount - coins[i], i, dp);
        }

        // Skip the coin
        op2 = helper(coins, amount, i + 1, dp);

        return dp[amount][i] = min(op1, op2);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int dp[10001][13];
        memset(dp, -1, sizeof(dp));

        int ans = helper(coins, amount, 0, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};