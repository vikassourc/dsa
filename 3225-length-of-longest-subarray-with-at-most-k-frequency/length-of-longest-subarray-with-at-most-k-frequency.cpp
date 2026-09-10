class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int low=0;
        int res=0;
        for(int high=0;high<n;high++)
        {
            mpp[nums[high]]++;
            while(mpp[nums[high]]>k)
            {
                mpp[nums[low]]--;
                if(mpp[nums[low]]==0)
                {
                    mpp.erase(nums[low]);
                }
                low++;
            }
            int len=high-low+1;
            res=max(res,len);
        }
        return res;
        
    }
};