class Solution
{
public:
    int cost(int num, int target, int k)
    {
        int rem = num % k;
        int diff = abs(rem - target);
        return min(diff, k - diff);
    }
    int minOperations(vector<int> &nums, int k)
    {

        int ans = INT_MAX;

        int n = nums.size();
        for (int x = 0; x < k; x++)
        {
            for (int y = 0; y < k; y++)
            {
                if (x == y)
                {
                    continue;
                }
                int currCost = 0;

                for (int i = 0; i < n; i++)
                {
                    if (i % 2 == 0)
                    {
                        currCost += cost(nums[i], x, k);
                    }
                    else
                    {
                        currCost += cost(nums[i], y, k);
                    }
                }
                ans = min(currCost, ans);
            }
        }
        return ans;
    }
};