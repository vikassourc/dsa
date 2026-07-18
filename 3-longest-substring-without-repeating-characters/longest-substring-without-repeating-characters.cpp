class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>f;
        int n=s.size();
        int res=INT_MIN;
        int low=0;
        int high=0;
        for(high=0;high<n;high++)
        {
            f[s[high]]++;
            int k=high-low+1;
            while(f.size()<k)
            {
                f[s[low]]--;
                if(f[s[low]]==0)
                {
                    f.erase(s[low]);
                }
                low++;
                k=high-low+1;
            }
            int len=high-low+1;
            res=max(res,len);
        }
       if(res==INT_MIN)
       return 0;
       return res;

        
        
    }
};