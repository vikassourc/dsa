class Solution {
public:
    unordered_map<int,int> dp;

    int fun(int i, vector<int>& cost)
    {
        if(i >= cost.size())
        {
            return 0;
        }

        if(dp.find(i) != dp.end())
        {
            return dp[i];
        }

        int a1 = fun(i + 1, cost);
        int a2 = fun(i + 2, cost);

        int ans = cost[i] + min(a1, a2);

        dp[i] = ans;

        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {

        return min(fun(0, cost), fun(1, cost));

    }
};