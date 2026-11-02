class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Sort the array to find the median
        sort(nums.begin(), nums.end());
        
        int moves = 0;
        int median = nums[nums.size() / 2];
        
        // Sum the absolute differences between each element and the median
        for (int num : nums) {
            moves += abs(num - median);
        }
        
        return moves;
    }
};