class Solution {
public:
    int minInsertions(string s) {
        int m = s.size();
        string rev = "";

        for (int i = m - 1; i >= 0; i--) {
            rev = rev + s[i];
        }

        int n = rev.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lps = dp[m][n];

        return m - lps;
    }
};