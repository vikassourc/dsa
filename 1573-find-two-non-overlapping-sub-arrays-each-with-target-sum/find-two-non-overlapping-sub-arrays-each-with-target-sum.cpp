class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        int INF = 1000000;
        
        vector<int> best(n, INF);
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int prefix = 0;
        int ans = INF;
        int minLen = INF;
        
        for (int i = 0; i < n; i++) {
            
            prefix += arr[i];
            
            // Check if a subarray with sum = target exists
            if (mp.find(prefix - target) != mp.end()) {
                
                int start = mp[prefix - target] + 1;
                int len = i - start + 1;
                
                // If there is an earlier non-overlapping subarray
                if (start > 0 && best[start - 1] != INF) {
                    ans = min(ans, len + best[start - 1]);
                }
                
                minLen = min(minLen, len);
            }
            
            // Store the best subarray ending at or before i
            if (i == 0)
                best[i] = minLen;
            else
                best[i] = min(best[i - 1], minLen);
            
            mp[prefix] = i;
        }
        
        if (ans == INF)
            return -1;
        
        return ans;
    }
};