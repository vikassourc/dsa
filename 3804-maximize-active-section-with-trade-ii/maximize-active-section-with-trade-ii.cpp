struct Group {
    int start, length;
};

class SparseTable {
public:
    SparseTable(const vector<int>& nums)
        : n(nums.size()), st(bit_width((unsigned)n) + 1, vector<int>(n + 1)) {
        copy(nums.begin(), nums.end(), st[0].begin());
        for (int i = 1; i <= bit_width((unsigned)n); ++i)
            for (int j = 0; j + (1 << i) <= n; ++j)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    int query(int l, int r) const { // max(nums[l..r])
        int i = bit_width((unsigned)(r - l + 1)) - 1;
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
private:
    int n;
    vector<vector<int>> st;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') zeroGroups.back().length++;
                else zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex[i] = (int)zeroGroups.size() - 1;
        }

        vector<int> ans;
        if (zeroGroups.empty()) {
            ans.assign(queries.size(), ones);
            return ans;
        }

        vector<int> mergeLens;
        for (int i = 0; i + 1 < (int)zeroGroups.size(); ++i)
            mergeLens.push_back(zeroGroups[i].length + zeroGroups[i + 1].length);
        SparseTable st(mergeLens);

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int gl = zeroGroupIndex[l], gr = zeroGroupIndex[r];
            int left  = (gl == -1) ? -1 : (zeroGroups[gl].length - (l - zeroGroups[gl].start));
            int right = (gr == -1) ? -1 : (r - zeroGroups[gr].start + 1);

            int startAdj = gl + 1;
            int endAdj   = (s[r] == '1' ? gr : gr - 1) - 1;

            int best = ones;

            if (s[l] == '0' && s[r] == '0' && gl + 1 == gr) {
                best = max(best, ones + left + right);
            } else if (startAdj <= endAdj) {
                best = max(best, ones + st.query(startAdj, endAdj));
            }

            if (s[l] == '0' && gl + 1 <= (s[r] == '1' ? gr : gr - 1))
                best = max(best, ones + left + zeroGroups[gl + 1].length);

            if (s[r] == '0' && gl < gr - 1)
                best = max(best, ones + right + zeroGroups[gr - 1].length);

            ans.push_back(best);
        }
        return ans;
    }
};