class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_brackets = 0;
        int additions = 0;
        
        for (char c : s) {
            if (c == '(') {
                open_brackets++;
            } else {
                if (open_brackets > 0) {
                    open_brackets--;
                } else {
                    additions++;
                }
            }
        }
        
        return additions + open_brackets;
    }
};
