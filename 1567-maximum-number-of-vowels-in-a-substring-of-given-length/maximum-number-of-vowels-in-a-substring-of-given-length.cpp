class Solution {
public:
    bool isvowel(char ch)
    {
        if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u')
        {
            return true;
        }
        return false;
    }
        
       
            
    int maxVowels(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int count=0;
        int maxi=INT_MIN;
        while(j<n)
        {
            if(isvowel(s[j]))
            {
                count++;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                maxi=max(count,maxi);
                if(isvowel(s[i]))
                {
                    count=count-1;
                }
                i++;
                j++;
                
            }
        }
        return maxi;
        
    }
};