class Solution {
public:
    void fun(int open, int close, int n, string &tmp, vector<string>& res)
    {
        if(open == n && close == n)
        {
            res.push_back(tmp);
            return;
        }

        if(open < n)
        {
            tmp.push_back('(');
            fun(open + 1, close, n, tmp, res);
            tmp.pop_back();
        }

        if(close < open)
        {
            tmp.push_back(')');
            fun(open, close + 1, n, tmp, res);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> res;
        string tmp = "";

        fun(0, 0, n, tmp, res);

        return res;
    }
};