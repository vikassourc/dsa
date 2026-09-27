#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> st;
        
        // First pass: pair up the matching parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        string result;
        // Second pass: build the string by jumping through the "wormholes"
        for (int i = 0, direction = 1; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];          // Teleport to the matching bracket
                direction = -direction; // Reverse the direction of traversal
            } else {
                result += s[i];       // Add normal characters to the result
            }
        }
        
        return result;
    }
};