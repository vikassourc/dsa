class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        vector<vector<int>>dp(m+1);
        for(i=0;i<=m;i++)
        {
            vector<int>t(n+1);
            dp[i]=t;
        }
        dp[m-1][n-1]=1;
        for(j=0;j<=n;j++)
        {
            dp[m][j]=0;
        }
        for(i=0;i<=m;i++)
        {
            dp[i][n]=0;
        }
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                    continue;
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
        
    }
};