class Solution
{
public:
    void dfs(int i, int j, int m, int n, vector<string> &grid)
    {

        grid[i][j] = '.';

        if (i == m - 1 && j == n - 1)
            return;

        if (j + 1 < n)
            dfs(i, j + 1, m, n, grid);
        else
            dfs(i + 1, j, m, n, grid);
    }

    vector<string> createGrid(int m, int n)
    {

        vector<string> grid(m, string(n, '#'));

        dfs(0, 0, m, n, grid);

        return grid;
    }
};