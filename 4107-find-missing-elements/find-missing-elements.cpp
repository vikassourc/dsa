class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;

        int mn = nums[0], mx = nums[0];

        for (int x : nums) {
            st.insert(x);
            mn = min(mn, x);
            mx = max(mx, x);
        }

        for (int i = mn + 1; i < mx; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};