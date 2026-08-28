class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        
        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for(char ch : s) {
            cnt[ch - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char middle = '#';

        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2 == 1) {
                odd++;
                middle = char('a' + i);
            }
        }

        if(odd > 1) {
            return "";
        }

        // Characters available for left half
        vector<int> half(26);

        for(int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;

        string left = "";

        // Check if current prefix can produce
        // some palindrome > target
        auto possible = [&]() {

            string temp = left;

            // Put remaining characters in largest order
            for(int i = 25; i >= 0; i--) {
                while(half[i] > 0) {
                    temp += char('a' + i);
                    half[i]--;
                }
            }

            // Restore half[]
            for(char ch : temp.substr(left.size())) {
                half[ch - 'a']++;
            }

            // Build palindrome
            string right = temp;
            reverse(right.begin(), right.end());

            string pal = temp;

            if(n % 2 == 1)
                pal += middle;

            pal += right;

            return pal > target;
        };


        // Build left half greedily
        for(int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            // Try smallest character first
            for(int c = 0; c < 26; c++) {

                if(half[c] == 0)
                    continue;

                // Choose c
                half[c]--;
                left += char('a' + c);

                // Can this choice lead to answer?
                if(possible()) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[c]++;
            }

            // No character works
            if(!found)
                return "";
        }

        // Construct final answer
        string right = left;
        reverse(right.begin(), right.end());

        string ans = left;

        if(n % 2 == 1)
            ans += middle;

        ans += right;

        if(ans > target)
            return ans;

        return "";
    }
};