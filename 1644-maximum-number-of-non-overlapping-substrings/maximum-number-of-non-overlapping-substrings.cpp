class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // First and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Only first occurrences can start a minimal valid interval
        for (int L = 0; L < n; L++) {
            int ch = s[L] - 'a';

            if (first[ch] != L)
                continue;

            int R = last[ch];
            bool valid = true;

            for (int i = L; i <= R; i++) {
                int c = s[i] - 'a';

                // This character has an occurrence before L
                if (first[c] < L) {
                    valid = false;
                    break;
                }

                // Include all occurrences of this character
                R = max(R, last[c]);
            }

            if (valid)
                intervals.push_back({L, R});
        }

        // Greedy interval scheduling
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto &[L, R] : intervals) {
            if (L > prevEnd) {
                ans.push_back(s.substr(L, R - L + 1));
                prevEnd = R;
            }
        }

        return ans;
    }
};