class Solution {
public:
    int fun(vector<int>& nums, int i, vector<int>& dp) {

        // Reached the last index
        if (i == nums.size() - 1)
            return 1;

        // Went out of bounds
        if (i >= nums.size())
            return 0;

        // Already computed
        if (dp[i] != -1)
            return dp[i];

        // Try every possible jump
        for (int jump = 1; jump <= nums[i]; jump++) {
            if (fun(nums, i + jump, dp))
                return dp[i] = 1;
        }

        // No jump can reach the end
        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);

        return fun(nums, 0, dp);
    }
};