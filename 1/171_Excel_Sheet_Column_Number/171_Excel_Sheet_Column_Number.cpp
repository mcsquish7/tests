#include <vector>
#include <algorithm>
#include <iostream>
#include <forward_list>
#include <string>
#include <map>
#include <cmath>

using namespace std;


class Solution {
public:
    int titleToNumber(string columnTitle) 
    {   
        int result = 0, n = 0;
        map<char, int> m;
        m.emplace('A', 1); m.emplace('B', 2); m.emplace('C', 3); m.emplace('D', 4);
        m.emplace('E', 5); m.emplace('F', 6); m.emplace('G', 7); m.emplace('H', 8);
        m.emplace('I', 9); m.emplace('J', 10); m.emplace('K', 11); m.emplace('L', 12);
        m.emplace('M', 13); m.emplace('N', 14); m.emplace('O', 15); m.emplace('P', 16);
        m.emplace('Q', 17); m.emplace('R', 18); m.emplace('S', 19); m.emplace('T', 20);
        m.emplace('U', 21); m.emplace('V', 22); m.emplace('W', 23); m.emplace('X', 24); 
        m.emplace('Y', 25); m.emplace('Z', 26);
        for (int i = columnTitle.size()-1; i>=0; --i)
        {
            result+=pow(26,n) * m[columnTitle[i]];
            ++n;
        }
        return result;
    }
};
// второй способ
class Solution_1 {
public:
    int titleToNumber(string columnTitle) 
    {   
        int result = 0, n = 0;
        for (int i = columnTitle.size()-1; i>=0; --i)
        {
            result+=pow(26,n) * (columnTitle[i] - 'A'+1);
            ++n;
        }
        return result;
    }
};
int main()
{
    Solution sol;
    cout << sol.titleToNumber("ZY");
    
    return 0;
}