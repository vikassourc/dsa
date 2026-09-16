class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1000000007;

        long long numerator = 1;
        long long denominator = 1;

        int N = n + k - 1;
        int R = 2 * k;

        for (int i = 0; i < R; i++) {
            numerator = numerator * (N - i) % MOD;
            denominator = denominator * (i + 1) % MOD;
        }

        // denominator inverse using Fermat's theorem
        long long inverse = 1;
        long long power = MOD - 2;

        while (power > 0) {
            if (power % 2 == 1) {
                inverse = inverse * denominator % MOD;
            }

            denominator = denominator * denominator % MOD;
            power = power / 2;
        }

        return numerator * inverse % MOD;
    }
};