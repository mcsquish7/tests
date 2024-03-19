#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> m;
        int len = 0;
        int temp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!m.count(s[i]))
            {
                m.emplace(s[i], i);
                temp++;
                len = max(len, temp);
            }
            else if (s[i - 1] == s[i])
            {
                temp = 1;
                m.clear();
                m.emplace(s[i], i);
                continue;
            }
            else
            {
                len = max(len, temp);
                temp = 1;
                i = m.at(s[i]) + 1;
                m.clear();
                m.emplace(s[i], i);
            }
        }
        return len;
    }
};
// Второй способ (лучше)
class Solution_1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        unordered_map<char, int> map;
        int start = 0;

        for (int end = 0; end < s.size(); end++)
        {
            if (map.find(s[end]) != map.end())
            {
                start = max(start, map[s[end]] + 1);
            }
            map[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution_1 sol;
    cout << sol.lengthOfLongestSubstring(s);
    return 0;
}