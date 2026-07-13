class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total=total+nums[i];
        }

        if(abs(target)>total)
        {
            return 0;
        }

        if((total+target)%2!=0)
        {
            return 0;
        }

        int sum=(total+target)/2;

        int n=nums.size();

        vector<vector<int>> dp(n+1);

        for(int i=0;i<=n;i++)
        {
            vector<int> t(sum+1,-1);
            dp[i]=t;
        }

        for(int j=0;j<=sum;j++)
        {
            dp[n][j]=0;
        }

        dp[n][0]=1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=sum;j++)
            {
                if(nums[i]>j)
                {
                    dp[i][j]=dp[i+1][j];
                }
                else
                {
                    dp[i][j]=dp[i+1][j-nums[i]] + dp[i+1][j];
                }
            }
        }

        return dp[0][sum];
    }
};