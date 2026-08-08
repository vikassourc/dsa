#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();

        // last[j] stores the largest index in word1 from which 
        // word2[j...] can be matched as an EXACT subsequence.
        std::vector<int> last(m + 1, -1);
        last[m] = n;

        int p = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }
            last[j] = p;
            p--; // Move left for the next character search
        }

        std::vector<int> ans;
        bool changed = false;
        int i = 0;

        // Greedily pick the smallest valid index in word1 for each word2[j]
        for (int j = 0; j < m; ++j) {
            while (i < n) {
                bool is_match = (word1[i] == word2[j]);

                if (is_match) {
                    if (!changed || last[j + 1] > i) {
                        ans.push_back(i);
                        i++;
                        break;
                    }
                } else {
                    if (!changed && last[j + 1] > i) {
                        ans.push_back(i);
                        changed = true;
                        i++;
                        break;
                    }
                }

                i++;
            }
        }

        return ans.size() == m ? ans : std::vector<int>{};
    }
};