class Solution
{
public:
    int minOperations(string s1, string s2)
    {

        const int INF = 1e9;
        int n = s1.size();

        if (n == 1)
        {
            if (s1 == s2)
                return 0;

            if (s1 == "0" && s2 == "1")
                return 1;

            return -1;
        }

        vector<vector<int>> dp(n + 1, vector<int>(2, INF));

        dp[0][0] = 0;

        for (int i = 0; i < n; i++)
        {

            for (int carry = 0; carry <= 1; carry++)
            {

                if (dp[i][carry] == INF)
                    continue;

                char cur;

                if (carry == 1)
                    cur = '0';
                else
                    cur = s1[i];

                // Option 1
                if (cur == s2[i])
                {

                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][carry]);
                }
                else if (cur == '0' && s2[i] == '1')
                {

                    dp[i + 1][0] = min(dp[i + 1][0],
                                       dp[i][carry] + 1);
                }

                // Option 2
                if (i + 1 < n)
                {

                    int cost = dp[i][carry];

                    char a = cur;
                    char b = s1[i + 1];

                    if (a == '0')
                    {
                        cost++;
                        a = '1';
                    }

                    if (b == '0')
                    {
                        cost++;
                        b = '1';
                    }

                    // perform 11 -> 00
                    cost++;

                    if (s2[i] == '1')
                        cost++;

                    dp[i + 1][1] = min(dp[i + 1][1], cost);
                }
            }
        }

        if (dp[n][0] == INF)
            return -1;

        return dp[n][0];
    }
};