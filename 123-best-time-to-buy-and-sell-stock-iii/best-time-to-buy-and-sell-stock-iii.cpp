class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int i,k;

        vector<vector<int>> dp(n+1);

        for(i=0; i<=n; i++)
        {
            vector<int> t(5,0);
            dp[i] = t;
        }

        for(i=n-1; i>=0; i--)
        {
            for(k=1; k<=4; k++)
            {
                if(k % 2 == 0) // BUY
                {
                    int c1 = dp[i+1][k-1] - a[i];
                    int c2 = dp[i+1][k];

                    dp[i][k] = max(c1,c2);
                }
                else // SELL
                {
                    int c1 = dp[i+1][k-1] + a[i];
                    int c2 = dp[i+1][k];

                    dp[i][k] = max(c1,c2);
                }
            }
        }

        return dp[0][4];
    }
};