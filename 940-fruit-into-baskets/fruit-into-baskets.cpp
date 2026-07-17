class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;
        int n=fruits.size();
        int res=INT_MIN;
        int low=0;
        int high=0;
        for(high=0;high<n;high++)
        {
            mp[fruits[high]]++;
            while(mp.size()>2)
            {
                mp[fruits[low]]--;
                if(mp[fruits[low]]==0)
                {
                    mp.erase(fruits[low]);
                }
                low++;
            }
            if(mp.size()==2 or mp.size()<2)
            {
                int len=high-low+1;
                res=max(len,res);
            }
            
        }
        return res;
    }
};    
    