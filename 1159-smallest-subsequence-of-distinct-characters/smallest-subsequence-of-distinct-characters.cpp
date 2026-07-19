class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        // Count frequency of each character
        for (char ch : s)
            freq[ch - 'a']++;

        string st = "";

        for (char ch : s) {
            freq[ch - 'a']--;

            // Already included in answer
            if (visited[ch - 'a'])
                continue;

            // Maintain lexicographical order
            while (!st.empty() &&
                   st.back() > ch &&
                   freq[st.back() - 'a'] > 0) {

                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(ch);
            visited[ch - 'a'] = true;
        }

        return st;
    }
};