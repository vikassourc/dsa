class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // Find the character's position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1)
            int reversePos = 26 - (s[i] - 'a');
            
            // Multiply by its 1-indexed position in the string (i + 1)
            ans += reversePos * (i + 1);
        }
        
        return ans;
    }
};
