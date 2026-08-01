class Solution
{
public:
    int lut(vector<int> &nums, int i, int end, vector<int> &dp)
    {
        if (i > end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + lut(nums, i + 2, end, dp);
        int skip = lut(nums, i + 1, end, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = lut(nums, 0, n - 2, dp1);
        int case2 = lut(nums, 1, n - 1, dp2);

        return max(case1, case2);
    }
};