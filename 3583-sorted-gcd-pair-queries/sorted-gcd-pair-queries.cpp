class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // Frequency of each number
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // divCount[d] = numbers divisible by d
        vector<long long> divCount(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d)
                divCount[d] += freq[j];
        }

        // exactPairs[d] = pairs having gcd exactly d
        vector<long long> exactPairs(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            exactPairs[d] = divCount[d] * (divCount[d] - 1) / 2;

            for (int j = 2 * d; j <= mx; j += d)
                exactPairs[d] -= exactPairs[j];
        }

        // Prefix sum
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exactPairs[i];

        vector<int> ans;

        for (long long q : queries) {
            int l = 1, r = mx;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }

            ans.push_back(l);
        }

        return ans;
    }
};