class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total=total+nums[i];
        }
        if(total%2!=0)
        {
            return false;
        }
        int target=total/2;
        int n=nums.size();
        int i,j;
        vector<vector<int>>dp(n+1);//rows
        for(int i=0;i<=n;i++)
        {
            vector<int>t(total+1,-1);//column
            dp[i]=t;
        }
        for(int j=0;j<=target;j++)
        {
            dp[n][j]=0;
        }
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=target;j++)
            {
                if(nums[i]>j)
                {
                    dp[i][j]=dp[i+1][j];
                }
                else
                {
                    dp[i][j]=dp[i+1][j-nums[i]] || dp[i+1][j];
                }
            }
        }
        return dp[0][target];

        
    }
};