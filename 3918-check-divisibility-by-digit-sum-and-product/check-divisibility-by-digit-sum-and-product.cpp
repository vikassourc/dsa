class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int temp=n;
        while(temp!=0)
        {
            int d=temp%10;
            sum=sum+d;
            pro=pro*d;
            temp=temp/10;
        }
        int newdivisor=sum+pro;
        if(n%newdivisor==0)
        {
            return true;
        }
        else
        {
            return false;
        }

        
    }
};