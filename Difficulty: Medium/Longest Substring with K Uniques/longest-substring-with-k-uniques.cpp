class Solution {
public:
    int longestKSubstr(string s, int k) {

        unordered_map<char,int> mp;

        int n = s.size();
        int low = 0;
        int ans = -1;

        for(int high = 0; high < n; high++)
        {
            mp[s[high]]++;

            while(mp.size() > k)
            {
                mp[s[low]]--;

                if(mp[s[low]] == 0)
                    mp.erase(s[low]);

                low++;
            }

            if(mp.size() == k)
            {
                ans = max(ans, high - low + 1);
            }
        }

        return ans;
    }
};