class Solution {
public:
    unordered_map<int,int>dp;
    int tribonacci(int n) {
        if(n==0)
        {
            return 0;
        }
        if(n==1 or n==2)
        {
            return 1;
        }
        if(dp.find(n)!=dp.end())
        {
            return dp[n];
        }
        int a1=tribonacci(n-3);
        int a2=tribonacci(n-2);
        int a3=tribonacci(n-1);
        int ans=a1+a2+a3;
        dp[n]=ans;
        return ans;

        
    }
};