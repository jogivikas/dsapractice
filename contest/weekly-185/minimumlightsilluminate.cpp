class Solution
{
public:
    int minAdditionalBulbs(vector<int> &lights)
    {

        int n = lights.size();

        vector<bool> visible(n, false);

        // Existing bulbs se visible positions mark
        for (int i = 0; i < n; i++)
        {

            if (lights[i] == 0)
                continue;

            int left = max(0, i - lights[i]);
            int right = min(n - 1, i + lights[i]);

            for (int j = left; j <= right; j++)
            {
                visible[j] = true;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            if (visible[i])
                continue;

            int pos = min(i + 1, n - 1);

            int left = max(0, pos - 1);
            int right = min(n - 1, pos + 1);

            for (int j = left; j <= right; j++)
            {
                visible[j] = true;
            }

            ans++;
        }

        return ans;
    }
};