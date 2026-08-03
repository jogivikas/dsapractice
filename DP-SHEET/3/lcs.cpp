class Solution
{
public:
    int helper(string &text1, string &text2,
               int i, int j,
               int dp[1001][1001])
    {
        if (i == text1.size() || j == text2.size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (text1[i] == text2[j])
        {
            return dp[i][j] =
                       1 + helper(text1, text2,
                                  i + 1, j + 1, dp);
        }

        int op1 = helper(text1, text2,
                         i + 1, j, dp);

        int op2 = helper(text1, text2,
                         i, j + 1, dp);

        return dp[i][j] = max(op1, op2);
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        int dp[1001][1001];

        memset(dp, -1, sizeof(dp));

        return helper(text1, text2, 0, 0, dp);
    }
};