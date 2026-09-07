class Solution {
public:

    int fun(int i, int j, int m, int n,
            vector<vector<int>>& grid,
            vector<vector<int>>& dp)
    {
        // Destination
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        // Out of boundary
        if (i >= m || j >= n)
            return 1e9;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Two choices
        int down = fun(i + 1, j, m, n, grid, dp);
        int right = fun(i, j + 1, m, n, grid, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return fun(0, 0, m, n, grid, dp);
    }
};