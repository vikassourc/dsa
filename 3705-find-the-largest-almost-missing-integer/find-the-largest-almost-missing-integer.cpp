class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k = 1
        if (k == 1) {
            unordered_map<int, int> mp;

            for (int x : nums) {
                mp[x]++;
            }

            int ans = -1;

            for (auto x : mp) {
                if (x.second == 1) {
                    ans = max(ans, x.first);
                }
            }

            return ans;
        }

        // Case 2: k = n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        int ans = -1;

        // Check first element
        bool first = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[0]) {
                first = false;
                break;
            }
        }

        if (first) {
            ans = max(ans, nums[0]);
        }

        // Check last element
        bool last = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[n - 1]) {
                last = false;
                break;
            }
        }

        if (last) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};