class Solution {
public:

    int dp[2005];

    bool isPalindrome(string &s, int i, int j) {

        while (i < j) {

            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    int solve(int i, string &s, int k) {

        if (i >= s.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        // Don't take anything starting from i
        int ans = solve(i + 1, s, k);

        // Try every substring starting from i
        for (int j = i + k - 1; j < s.size(); j++) {

            if (isPalindrome(s, i, j)) {

                int take = 1 + solve(j + 1, s, k);

                ans = max(ans, take);
            }
        }

        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {

        memset(dp, -1, sizeof(dp));

        return solve(0, s, k);
    }
};