class Solution
{
public:
    static const int MOD = 1e9 + 7;

    int maxValue(vector<int> &nums1, vector<int> &nums0)
    {

        vector<pair<int, int>> seg;
        int totalBits = 0;

        for (int i = 0; i < nums1.size(); i++)
        {
            seg.push_back({nums1[i], nums0[i]});
            totalBits += nums1[i] + nums0[i];
        }

        auto group = [](pair<int, int> p)
        {
            if (p.second == 0)
                return 0; // only 1's
            if (p.first > 0)
                return 1; // both 1's and 0's
            return 2;     // only 0's
        };

        sort(seg.begin(), seg.end(), [&](auto &a, auto &b)
             {

            int g1 = group(a);
            int g2 = group(b);

            if (g1 != g2) return g1 < g2;

            if (g1 == 0)
                return a.first > b.first;

            if (g1 == 1) {
                if (a.first != b.first)
                    return a.first > b.first;
                return a.second < b.second;
            }

            return a.second < b.second; });

        vector<long long> pow2(totalBits);
        pow2[0] = 1;
        for (int i = 1; i < totalBits; i++)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        long long ans = 0;
        int bit = totalBits - 1;

        for (auto &[ones, zeros] : seg)
        {

            while (ones--)
            {
                ans = (ans + pow2[bit]) % MOD;
                bit--;
            }

            bit -= zeros;
        }

        return (int)ans;
    }
};