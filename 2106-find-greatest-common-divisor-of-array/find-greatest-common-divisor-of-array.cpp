class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int max=INT_MIN;
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
            }
            if(nums[i]<min)
            {
                min=nums[i];
            }
        }
        return gcd(min,max);
        
    }
};