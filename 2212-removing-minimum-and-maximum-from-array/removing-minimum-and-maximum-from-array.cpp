class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();

        int minPos = 0;
        int maxPos = 0;

        // Find positions of minimum and maximum
        for(int i = 0; i < n; i++) {
            if(nums[i] < nums[minPos])
                minPos = i;

            if(nums[i] > nums[maxPos])
                maxPos = i;
        }

        // Make minPos the smaller position
        if(minPos > maxPos)
            swap(minPos, maxPos);

        // 1. Remove both from left
        int option1 = maxPos + 1;

        // 2. Remove both from right
        int option2 = n - minPos;

        // 3. Remove min from left and max from right
        int option3 = minPos + 1 + n - maxPos;

        return min({option1, option2, option3});
    }
};