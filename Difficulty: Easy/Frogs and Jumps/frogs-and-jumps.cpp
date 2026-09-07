class Solution {
public:
    int unvisitedLeaves(vector<int>& arr, int k) {

        vector<bool> visited(k + 1, false);

        for(int i = 0; i < arr.size(); i++)
        {
            int s = arr[i];

            for(int j = s; j <= k; j += s)
            {
                visited[j] = true;
            }
        }

        int ans = 0;

        for(int i = 1; i <= k; i++)
        {
            if(visited[i] == false)
                ans++;
        }

        return ans;
    }
};