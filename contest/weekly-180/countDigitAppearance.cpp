class Solution
{
public:
    int countDigitOccurrences(vector<int> &nums, int digit)
    {

        int n = nums.size();
        int cnt = 0;

        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(to_string(nums[i]));
        }
        char ch = digit + '0';

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j] == ch)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};