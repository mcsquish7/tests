#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void solve(int idx, string s, string temp, unordered_map<char, string> m, vector<string> &result)
    {
        if (idx >= s.size())
        {
            result.push_back(temp);
        }
        char ch = s[idx];
        string str = m[ch];

        for (int i = 0; i < str.length(); i++)
        {
            temp.push_back(str[i]);
            solve(idx + 1, s, temp, m, result);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return {};
        vector<string> result;
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        solve(0, digits, "", m, result);
        return result;
    }
};

int main()
{
    string s = "23";
    Solution sol;
    vector<string> ans = sol.letterCombinations(s);
    // sol.letterCombinations(s);
    for (auto &el : ans)
    {
        cout << el << "\t";
    }

    return 0;
}