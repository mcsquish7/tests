#include <vector>
#include <algorithm>
#include <iostream>
#include <forward_list>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    int romanToInt(string s) 
    {   
        map<char, int> m;
        m.emplace('I', 1);
        m.emplace('V', 5);
        m.emplace('X', 10);
        m.emplace('L', 50);
        m.emplace('C', 100);
        m.emplace('D', 500);
        m.emplace('M', 1000);
        int result=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] < m[s[i+1]])
            {
                result-=m[s[i]]; 
            }
            else
                result+=m[s[i]];
        }
        return (result);
    }
};

int main()
{   
    string s = "VLVIII";
    Solution res;
    cout << res.romanToInt(s);
    return 0;
}