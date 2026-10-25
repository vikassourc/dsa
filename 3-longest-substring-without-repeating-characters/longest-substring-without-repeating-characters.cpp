class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0, j = 0;
        int maxLen = 0;
        int n = s.size();

        while (j < n) {
            // 1. Calculation
            mp[s[j]]++;

            // 2. No repeating characters
            if (mp[s[j]] == 1) {
                maxLen = max(maxLen, j - i + 1);
                j++;
            }

            // 3. Repeating character found
            else if (mp[s[j]] > 1) {
                while (mp[s[j]] > 1) {
                    mp[s[i]]--;

                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }

                    i++;
                }

                j++;
            }
        }

        return maxLen;
    }
};