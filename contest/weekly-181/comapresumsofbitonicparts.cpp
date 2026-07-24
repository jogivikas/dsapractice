class Solution
{
public:
    int compareBitonicSums(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> v;
        vector<int> k;
        int x = 0;
        long long sum1 = 0;
        long long sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= nums[i + 1])
            {
                v.push_back(nums[i]);
                sum1 += nums[i];
            }
            else
            {
                v.push_back(nums[i]);
                sum1 += nums[i];
                x = i;
                break;
            }
        }
        for (int i = x; i < n; i++)
        {
            k.push_back(nums[i]);
            sum2 += nums[i];
        }
        if (sum1 == sum2)
        {
            return -1;
        }
        else if (sum1 > sum2)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};