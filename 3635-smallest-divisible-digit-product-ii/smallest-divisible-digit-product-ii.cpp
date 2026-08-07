#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Factors {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    Factors getFactors(int d) {
        Factors f;
        if (d == 0) return f;
        while (d % 2 == 0) { f.c2++; d /= 2; }
        while (d % 3 == 0) { f.c3++; d /= 3; }
        while (d % 5 == 0) { f.c5++; d /= 5; }
        while (d % 7 == 0) { f.c7++; d /= 7; }
        return f;
    }

    int minDigitsNeeded(int r2, int r3, int r5, int r7) {
        r2 = max(0, r2);
        r3 = max(0, r3);
        r5 = max(0, r5);
        r7 = max(0, r7);

        // Greedy allocation for maximum factor density
        int c8 = r2 / 3; r2 %= 3;
        int c9 = r3 / 2; r3 %= 2;

        int c6 = 0;
        if (r2 == 1 && r3 == 1) {
            c6 = 1;
            r2 = 0;
            r3 = 0;
        }

        int c4 = r2 / 2; r2 %= 2;

        return r2 + r3 + c4 + r5 + c6 + r7 + c8 + c9;
    }

    string buildSmallestSuffix(int len, int r2, int r3, int r5, int r7, const vector<Factors>& df) {
        r2 = max(0, r2); r3 = max(0, r3); r5 = max(0, r5); r7 = max(0, r7);
        string res = "";
        for (int pos = 0; pos < len; ++pos) {
            int rem_len = len - 1 - pos;
            for (int d = 1; d <= 9; ++d) {
                int nr2 = r2 - df[d].c2;
                int nr3 = r3 - df[d].c3;
                int nr5 = r5 - df[d].c5;
                int nr7 = r7 - df[d].c7;
                if (minDigitsNeeded(nr2, nr3, nr5, nr7) <= rem_len) {
                    res += to_string(d);
                    r2 = nr2; r3 = nr3; r5 = nr5; r7 = nr7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Prime factorize t into 2, 3, 5, 7
        Factors req;
        long long temp_t = t;
        while (temp_t % 2 == 0) { req.c2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { req.c3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { req.c5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { req.c7++; temp_t /= 7; }

        // If t has prime factors > 7, no digit product can be divisible by t
        if (temp_t > 1) return "-1";

        vector<Factors> df(10);
        for (int i = 0; i < 10; ++i) df[i] = getFactors(i);

        int n = num.size();
        size_t zero_pos = num.find('0');
        
        // We can process up to zero_pos + 1 (inclusive) because 
        // position zero_pos can be replaced with digits >= 1.
        int limit = (zero_pos == string::npos) ? n : (int)zero_pos + 1;

        // Prefix factor tracking
        vector<Factors> prefix_req(limit + 1);
        Factors cur = req;
        prefix_req[0] = cur;

        for (int i = 0; i < min(limit, n); ++i) {
            int d = num[i] - '0';
            if (d == 0) break; // Cannot accumulate factor from '0'
            cur.c2 -= df[d].c2;
            cur.c3 -= df[d].c3;
            cur.c5 -= df[d].c5;
            cur.c7 -= df[d].c7;
            prefix_req[i + 1] = cur;
        }

        // Case 1: Check if 'num' itself is valid (zero-free and satisfies requirements)
        if (zero_pos == string::npos && minDigitsNeeded(cur.c2, cur.c3, cur.c5, cur.c7) <= 0) {
            return num;
        }

        // Case 2: Try replacing digit at position i (from right to left) with d > num[i]
        for (int i = limit - 1; i >= 0; --i) {
            int orig_d = num[i] - '0';
            Factors p = prefix_req[i];
            int rem_len = n - 1 - i;

            // If orig_d is 0, d starts from 1 (> 0). Otherwise d starts from orig_d + 1.
            for (int d = orig_d + 1; d <= 9; ++d) {
                int nr2 = p.c2 - df[d].c2;
                int nr3 = p.c3 - df[d].c3;
                int nr5 = p.c5 - df[d].c5;
                int nr7 = p.c7 - df[d].c7;

                if (minDigitsNeeded(nr2, nr3, nr5, nr7) <= rem_len) {
                    string prefix = num.substr(0, i) + to_string(d);
                    string suffix = buildSmallestSuffix(rem_len, nr2, nr3, nr5, nr7, df);
                    return prefix + suffix;
                }
            }
        }

        // Case 3: Need a longer string length (n + 1 or minimum needed)
        int target_len = max(n + 1, minDigitsNeeded(req.c2, req.c3, req.c5, req.c7));
        return buildSmallestSuffix(target_len, req.c2, req.c3, req.c5, req.c7, df);
    }
};