#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int total;
    vector<vector<int>> dp;

    int solve(int i, int currSum, vector<int> &stones)
    {
        if (i == stones.size())
            return abs(total - 2 * currSum);

        if (dp[i][currSum] != -1)
            return dp[i][currSum];

        int take = solve(i + 1, currSum + stones[i], stones);
        int notTake = solve(i + 1, currSum, stones);

        return dp[i][currSum] = min(take, notTake);
    }

    int lastStoneWeightII(vector<int> &stones)
    {
        total = accumulate(stones.begin(), stones.end(), 0);

        dp.assign(stones.size(), vector<int>(total + 1, -1));

        return solve(0, 0, stones);
    }
};