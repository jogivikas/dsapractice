class Solution
{
public:
    bool validDigit(int n, int x)
    {

        string y = to_string(n);
        char digit = x + '0';

        if (y[0] == digit)
            return false;

        for (int i = 1; i < y.size(); i++)
        {
            if (y[i] == digit)
                return true;
        }

        return false;
    }
};