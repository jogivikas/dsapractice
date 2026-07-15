class Solution
{
public:
    bool consecutiveSetBits(int n)
    {

        if (n == 0)
            return false;

        string s = "";

        while (n > 0)
        {
            s += (n % 2) + '0';
            n /= 2;
        }

        reverse(s.begin(), s.end());

        int count = 0;

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1')
                count++;
        }

        return count == 1;
    }
};