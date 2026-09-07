class Solution {
public:

    int fun(vector<int>& a, int i, int end, int free,
            vector<vector<int>>& dp)
    {
        if(i > end)
            return 0;

        if(dp[i][free] != -1)
            return dp[i][free];

        if(free == 0)
        {
            return dp[i][free] =
                fun(a, i + 1, end, 1, dp);
        }

        int c1 = a[i] +
                 fun(a, i + 1, end, 0, dp);

        int c2 =
            fun(a, i + 1, end, 1, dp);

        return dp[i][free] = max(c1, c2);
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        // Case 1: exclude first
        vector<vector<int>> dp1(n, vector<int>(2, -1));
        int c1 = fun(nums, 1, n - 1, 1, dp1);

        // Case 2: exclude last
        vector<vector<int>> dp2(n, vector<int>(2, -1));
        int c2 = fun(nums, 0, n - 2, 1, dp2);

        return max(c1, c2);
    }
};