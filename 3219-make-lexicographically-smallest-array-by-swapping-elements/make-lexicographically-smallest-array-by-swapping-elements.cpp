class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort according to value
        sort(v.begin(), v.end());

        int i = 0;

        while(i < n) {
            
            int j = i;

            // Find a group where consecutive values differ <= limit
            while(j + 1 < n && v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Original indices of this group
            vector<int> indices;

            for(int k = i; k <= j; k++) {
                indices.push_back(v[k].second);
            }

            // Sort original indices
            sort(indices.begin(), indices.end());

            // Put sorted values into sorted indices
            for(int k = 0; k < indices.size(); k++) {
                nums[indices[k]] = v[i + k].first;
            }

            i = j + 1;
        }

        return nums;
    }
};