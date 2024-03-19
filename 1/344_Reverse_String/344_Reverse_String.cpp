#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) 
    {   
        char temp;
        for (int i = 0; i < s.size()/2; i++)
        {
            temp = s.at(i);
            s.at(i) = s.at((s.size()-1)-i);
            s.at((s.size()-1)-i) = temp;
        }
    }
};

int main()
{   
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    sol.reverseString(s);
    for (auto &el : s)
    {
        cout << el << "\t";
    }
    
    return 0;
}