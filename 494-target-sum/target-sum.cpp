class Solution {
public:
    int countsubsetsum(vector<int>& arr, int target)
    {
        int n = arr.size();

        vector<vector<int>> t(n+1, vector<int>(target+1, 0));

        for(int i = 0; i <= n; i++)
        {
            t[i][0] = 1;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= target; j++)
            {
                if(arr[i-1] <= j)
                {
                    t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(abs(target)>sum||(target+sum)%2!=0)
        {
            return 0;
        }
        int s1=(target+sum)/2;
        return countsubsetsum(nums,s1);

        
    }
};