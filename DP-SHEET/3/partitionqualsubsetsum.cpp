class Solution
{
public:
    vector<vector<int>> dp;

    bool solve(int idx, int currSum, int target, vector<int> &nums)
    {
        if (currSum == target)
            return true;

        if (idx == nums.size() || currSum > target)
            return false;

        if (dp[idx][currSum] != -1)
            return dp[idx][currSum];

        // Take current element
        bool take = solve(idx + 1, currSum + nums[idx], target, nums);

        // Don't take current element
        bool notTake = solve(idx + 1, currSum, target, nums);

        return dp[idx][currSum] = take || notTake;
    }

    bool canPartition(vector<int> &nums)
    {
        int total = 0;

        for (int x : nums)
            total += x;

        if (total % 2 != 0)
            return false;

        int target = total / 2;

        dp.assign(nums.size(), vector<int>(target + 1, -1));

        return solve(0, 0, target, nums);
    }
};