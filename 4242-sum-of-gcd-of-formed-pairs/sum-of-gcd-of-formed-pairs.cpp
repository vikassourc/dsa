class Solution {
public:
    long long sum=0;
    long long gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        vector<int>prefixGcd;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mx)
            {
                mx=nums[i];
            }
            long long ans=gcd(nums[i],mx);
            prefixGcd.push_back(ans);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int left=0;
        int right=n-1;
        while(left<right)
        {
            
            int x=prefixGcd[left];
            int y=prefixGcd[right];
            sum=sum+gcd(prefixGcd[left],prefixGcd[right]);
            left++;
            right--;
        }
        return sum;
        

        
    }
};