class Solution
{
public:
    vector<int> scoreValidator(vector<string> &s)
    {

        int n = s.size();

        int score = 0;
        int counter = 0;
        vector<int> v;

        for (int i = 0; i < n; i++)
        {

            if (s[i] == "1" || s[i] == "0" || s[i] == "2" ||
                s[i] == "3" || s[i] == "4" || s[i] == "5" || s[i] == "6")
            {

                score += stoi(s[i]);
            }
            else if (s[i] == "W")
            {

                counter++;

                if (counter == 10)
                {
                    break;
                }
            }
            else if (s[i] == "WD")
            {

                score = score + 1;
            }
            else if (s[i] == "NB")
            {

                score = score + 1;
            }
        }

        v.push_back(score);
        v.push_back(counter);

        return v;
    }
};