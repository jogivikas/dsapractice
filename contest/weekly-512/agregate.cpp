class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        vector<vector<int>> ans;

        int i = 0, j = 0;
        int n = series1.size(), m = series2.size();

        while (i < n || j < m) {
            int t;
            if (j == m || (i < n && series1[i][0] < series2[j][0]))
                t = series1[i][0];
            else if (i == n || series2[j][0] < series1[i][0])
                t = series2[j][0];
            else
                t = series1[i][0];

            long long v1 = 0, v2 = 0;

            if (i < n) {
                v1 = series1[i][1];
                if (series1[i][0] == t) i++;
            }

            if (j < m) {
                v2 = series2[j][1];
                if (series2[j][0] == t) j++;
            }

            ans.push_back({t, (int)(v1 + v2)});
        }

        return ans;
    }
};