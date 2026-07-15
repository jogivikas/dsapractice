class Solution
{
public:
    bool isMiddleElementUnique(vector<int> &nums)
    {

        int n = nums.size();

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        int x = nums[n / 2];

        for (int i = 0; i < n; i++)
        {
            if (freq[x] == 1)
            {
                return true;
            }
        }
        return false;
    }
};