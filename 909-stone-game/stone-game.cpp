class Solution {
public:

    int fun(vector<int>& piles, int i, int j,
            vector<vector<int>>& dp)
    {
        if(i == j)
        {
            return piles[i];
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int left = piles[i] - fun(piles, i + 1, j, dp);

        int right = piles[j] - fun(piles, i, j - 1, dp);

        return dp[i][j] = max(left, right);
    }

    bool stoneGame(vector<int>& piles)
    {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return fun(piles, 0, n - 1, dp) > 0;
    }
};