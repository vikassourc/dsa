class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long x = 1000;

        while(x <= n)
        {
            commas += n - x + 1;
            x = x * 1000;
        }

        return commas;
    }
};