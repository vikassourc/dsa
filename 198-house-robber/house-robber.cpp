class Solution {
public:
    int fun(vector<int>& a, int n, int i, int free,
            vector<vector<int>>& dp) {

        // Base case
        if (i == n)
            return 0;

        // Already calculated
        if (dp[i][free] != -1)
            return dp[i][free];

        // Cannot rob this house
        if (free == 0) {
            return dp[i][free] = fun(a, n, i + 1, 1, dp);
        }

        // Rob current house
        int c1 = a[i] + fun(a, n, i + 1, 0, dp);

        // Don't rob current house
        int c2 = fun(a, n, i + 1, 1, dp);

        return dp[i][free] = max(c1, c2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return fun(nums, n, 0, 1, dp);
    }
};