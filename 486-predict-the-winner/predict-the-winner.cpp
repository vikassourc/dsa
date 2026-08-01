class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];

        if (dp[left][right] != -1)
            return dp[left][right];

        int takeLeft = nums[left] - solve(nums, left + 1, right);
        int takeRight = nums[right] - solve(nums, left, right - 1);

        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(nums, 0, n - 1) >= 0;
    }
};