class Solution {
public:

    int fun(vector<int>& cuts, int i, int j,
            vector<vector<int>>& dp)
    {
        if(i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;

        for(int k = i; k <= j; k++)
        {
            int cost = cuts[j + 1] - cuts[i - 1];

            int c1 = fun(cuts, i, k - 1, dp);

            int c2 = fun(cuts, k + 1, j, dp);

            int r = cost + c1 + c2;

            res = min(res, r);
        }

        return dp[i][j] = res;
    }


    int minCost(int n, vector<int>& c)
    {
        vector<int> cuts;

        cuts.push_back(0);

        for(int i = 0; i < c.size(); i++)
        {
            cuts.push_back(c[i]);
        }

        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int s = cuts.size();

        vector<vector<int>> dp(s,
                               vector<int>(s, -1));

        return fun(cuts, 1, s - 2, dp);
    }
};