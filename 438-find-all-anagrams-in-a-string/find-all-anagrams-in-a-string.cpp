class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        vector<int> ans;

        for (char c : p) {
            mp[c]++;
        }

        int k = p.size();
        int count = mp.size();
        int i = 0, j = 0;
        int n = s.size();

        while (j < n) {
            // Calculation
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;

                if (mp[s[j]] == 0) {
                    count--;
                }
            }

            // Window size < K
            if (j - i + 1 < k) {
                j++;
            }

            // Window size == K
            else if (j - i + 1 == k) {
                if (count == 0) {
                    ans.push_back(i);
                }

                // Remove outgoing character
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;

                    if (mp[s[i]] == 1) {
                        count++;
                    }
                }

                // Slide window
                i++;
                j++;
            }
        }

        return ans;
    }
};