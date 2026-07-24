class Solution
{
public:
    bool isPrime(int num)
    {
        if (num < 2)
            return false;

        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    int minOperations(vector<int> &nums)
    {
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            // Even index -> should be prime
            if (i % 2 == 0)
            {
                while (!isPrime(nums[i]))
                {
                    nums[i]++;
                    cnt++;
                }
            }
            // Odd index -> should be non-prime
            else
            {
                while (isPrime(nums[i]))
                {
                    nums[i]++;
                    cnt++;
                }
            }
        }

        return cnt;
    }
};