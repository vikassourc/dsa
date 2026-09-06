class Solution {
public:

    long long dp[1001][1001];

    long long solve(int i, int j, string &s, string &t)
    {
        // t is completely formed
        if(j == t.size())
            return 1;

        // s is finished but t is still remaining
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // OP1 : Skip s[i]
        long long op1 = solve(i + 1, j, s, t);

        // OP2 : Take s[i]
        long long op2 = 0;

        if(s[i] == t[j])
        {
            op2 = solve(i + 1, j + 1, s, t);
        }

        return dp[i][j] = op1 + op2;
    }

    int numDistinct(string s, string t) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, s, t);
    }
};