class Solution
{
public:
    int helper(int remCap, vector<int> &val, vector<int> &wt,
               int i, long long dp[][1001])
    {
        if (i >= wt.size())
            return 0;

        if (dp[i][remCap] != -1)
            return dp[i][remCap];

        int op1 = 0, op2;

        if (wt[i] <= remCap)
            op1 = val[i] + helper(remCap - wt[i], val, wt, i + 1, dp);

        op2 = helper(remCap, val, wt, i + 1, dp);

        return dp[i][remCap] = max(op1, op2);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        long long dp[1001][1001];
        memset(dp, -1, sizeof(dp));

        return helper(W, val, wt, 0, dp);
    }
};