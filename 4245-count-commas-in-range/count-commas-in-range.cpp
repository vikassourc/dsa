class Solution {
public:
    int total=0;
    int nomberCommas(int n) {
        int count=0;
        int commas=0;
        while(n!=0)
        {
            int d=n%10;
            count++;
            n=n/10;
        }
        if(count<4)
        {
            return 0;
        }
        for(int i=0;i<count;i++)
        {
            if(i%3==0 && i!=0)
            {
                commas++;
            }
        }
        return commas;
    }
    int countCommas(int n) {
        int maxcommas=nomberCommas(n);
        for(int i = 1; i <= n; i++)
        {
            total += nomberCommas(i);
        }

        return total;
        
       
        
    }
};