class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k = k % (m * n);

        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int index = i * n + j;
                int newindex = (index + k) % (m * n);

                int row = newindex / n;
                int col = newindex % n;

                ans[row][col] = grid[i][j];
            }
        }

        return ans;
    }
};