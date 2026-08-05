class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 1);

        int maxLIS = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j <= i - 1; j++)
            {

                if (nums[j] < nums[i])
                {

                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }

            maxLIS = max(maxLIS, dp[i]);
        }

        return maxLIS;
    }
};