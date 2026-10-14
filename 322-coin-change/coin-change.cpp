class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> t(n+1, vector<int>(amount+1, INT_MAX-1));

        for(int i = 0; i <= n; i++)
        {
            t[i][0] = 0;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(j % coins[i-1] == 0)
                {
                    t[i][j] = j / coins[i-1];
                }
                else
                {
                    t[i][j] = INT_MAX-1;
                }

                if(coins[i-1] <= j)
                {
                    t[i][j] = min(
                        1 + t[i][j-coins[i-1]],
                        t[i-1][j]
                    );
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        if(t[n][amount] == INT_MAX-1)
            return -1;

        return t[n][amount];
    }
};