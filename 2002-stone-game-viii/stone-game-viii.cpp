class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> dp(n);

        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += stones[i];
        }

        dp[n - 1] = sum;

        for(int i = n - 2; i >= 1; i--)
        {
            sum -= stones[i + 1];

            dp[i] = max(sum - dp[i + 1], dp[i + 1]);
        }

        return dp[1];
    }
};