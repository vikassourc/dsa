class Solution {
public:

    struct Node {
        long long sum;
        vector<int> idx;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<vector<long long>> arr;

        for(int i=0;i<n;i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // sort by starting point
        sort(arr.begin(),arr.end());

        vector<long long> start(n);

        for(int i=0;i<n;i++) {
            start[i] = arr[i][0];
        }

        // dp[i][k] = best answer from i onwards
        // when we can still select k intervals
        vector<vector<Node>> dp(
            n+1,
            vector<Node>(5, {0,{}})
        );

        for(int i=n-1;i>=0;i--) {

            for(int k=1;k<=4;k++) {

                // SKIP
                Node skip = dp[i+1][k];

                // TAKE
                int next = upper_bound(
                    start.begin(),
                    start.end(),
                    arr[i][1]
                ) - start.begin();

                Node take;

                take.sum = arr[i][2] + dp[next][k-1].sum;

                take.idx = dp[next][k-1].idx;

                take.idx.push_back(arr[i][3]);

                sort(take.idx.begin(),take.idx.end());

                // choose better
                if(take.sum > skip.sum) {

                    dp[i][k] = take;

                }
                else if(take.sum < skip.sum) {

                    dp[i][k] = skip;

                }
                else {

                    // same sum
                    if(take.idx < skip.idx)
                        dp[i][k] = take;
                    else
                        dp[i][k] = skip;
                }
            }
        }

        return dp[0][4].idx;
    }
};