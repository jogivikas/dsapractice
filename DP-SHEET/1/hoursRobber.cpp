class Solution
{
public:
    int helper(vector<int> &nums, int i, vector<int> &dp, int n)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        // take it
        int op1 = 0, op2 = 0;
        op1 += nums[i];
        op1 += helper(nums, i + 2, dp, n);

        // skip
        op2 = helper(nums, i + 1, dp, n);

        return dp[i] = max(op1, op2);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return helper(nums, 0, dp, n);
    }
};