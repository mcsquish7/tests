#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    void helper(string &s, int open, int close, vector<string> &res)
    {

        if (open == 0 && close == 0)
        {
            res.push_back(s);
        }

        if (open > 0)
        {
            s.push_back('(');
            helper(s, open - 1, close, res);
            s.pop_back();
        }

        if (close > 0 && open < close)
        {
            s.push_back(')');
            helper(s, open, close - 1, res);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {

        vector<string> res;
        string s = "";
        helper(s, n, n, res);

        return res;
    }
};

int main()
{
    int n = 2;
    Solution sol;
    vector<string> s = sol.generateParenthesis(n);
    for (auto &el : s)
    {
        cout << el << "\t";
    }

    return 0;
}