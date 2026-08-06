#include <numeric>
using namespace std;

class Solution
{
public:
    long long maxPairStrength(vector<int> &nums)
    {

        long long strength = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            long long sum = 0;

            for (int j = i + 1; j < nums.size(); j++)
            {
                long long g = gcd(nums[i], nums[j]);

                sum = max(sum,
                          (1LL * nums[i] * nums[j]) / (g * g));
            }

            strength = max(strength, sum);
        }

        return strength;
    }
};