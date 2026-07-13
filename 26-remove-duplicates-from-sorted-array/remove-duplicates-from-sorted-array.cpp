class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=1;
        int unique=1;
        while(r<n)
        {
            if(nums[r]==nums[l])
            {
               r++;
            }
            else
            {
                swap(nums[r], nums[l+1]);
                unique=unique+1;
                l++;
                r++;
                

            }
        }
        return unique;
    }
};