class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store key -> value
        for (auto x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        int i = 0;

        while (i < s.length()) {

            if (s[i] == '(') {

                i++; // skip '('

                string key = "";

                // Extract key
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Check key in map
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += '?';
                }

                i++; // skip ')'
            }
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};