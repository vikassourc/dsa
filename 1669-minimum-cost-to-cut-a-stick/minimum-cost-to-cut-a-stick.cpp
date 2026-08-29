class Solution {
public:

    int fun(vector<int>& cuts, int i, int j,
            vector<vector<int>>& dp)
    {
        // No cut possible
        if(i + 1 == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for(int k = i + 1; k < j; k++)
        {
            int c1 = fun(cuts, i, k, dp);
            int c2 = fun(cuts, k, j, dp);

            int cost = cuts[j] - cuts[i];

            int c3 = cost + c1 + c2;

            ans = min(ans, c3);
        }

        return dp[i][j] = ans;
    }


    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int s = cuts.size();

        vector<vector<int>> dp(s);

        for(int i = 0; i < s; i++)
        {
            vector<int> t(s, -1);
            dp[i] = t;
        }

        return fun(cuts, 0, s - 1, dp);
    }
};