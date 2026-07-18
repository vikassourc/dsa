class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int zeroes = 0;
        unordered_map<int,int> f;
        int low = 0;
        int high = 0;
        int res = 0;   // FIX

        for(high = 0; high < n; high++)
        {
            f[nums[high]]++;

            if(nums[high] == 0)
                zeroes++;

            while(zeroes > k)
            {
                if(nums[low] == 0)   // FIX: decrease zero count
                    zeroes--;

                f[nums[low]]--;
                if(f[nums[low]] == 0)
                    f.erase(nums[low]);

                low++;
            }

            int len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};
