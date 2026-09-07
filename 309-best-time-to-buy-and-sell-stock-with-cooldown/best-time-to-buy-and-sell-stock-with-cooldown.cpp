class Solution {
public:

    int fun(vector<int>& a, int n, int i, int k,
            vector<vector<int>>& dp)
    {
        if (i >= n)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        if (k == 2)       // BUY
        {
            int c1 = fun(a, n, i + 1, 1, dp) - a[i];
            int c2 = fun(a, n, i + 1, 2, dp);

            return dp[i][k] = max(c1, c2);
        }
        else              // SELL
        {
            // After selling, cooldown → i + 2
            int c1 = fun(a, n, i + 2, 2, dp) + a[i];

            // Don't sell
            int c2 = fun(a, n, i + 1, 1, dp);

            return dp[i][k] = max(c1, c2);
        }
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(3, -1));

        return fun(prices, n, 0, 2, dp);
    }
};