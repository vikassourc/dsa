class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int i, k;

        vector<vector<int>> dp(n+1);

        for(i=0; i<=n; i++)
        {
            vector<int> t(3, 0);
            dp[i] = t;
        }

        // i == n
        for(k=0; k<=2; k++)
        {
            dp[n][k] = 0;
        }

        // k == 0
        for(i=0; i<=n; i++)
        {
            dp[i][0] = 0;
        }

        for(i=n-1; i>=0; i--)
        {
            // k == 1 -> sell
            int c1 = dp[i+1][0] + a[i];
            int c2 = dp[i+1][1];

            dp[i][1] = max(c1,c2);

            // k == 2 -> buy
            c1 = dp[i+1][1] - a[i];
            c2 = dp[i+1][2];

            dp[i][2] = max(c1,c2);
        }

        return dp[0][2];
    }
};