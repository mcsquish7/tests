#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        string str = to_string(x);
        int s = size(str);
        for (int i = 0; i < s/2; i++)
        {
            if (str[i] != str[s - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    Solution s;
    cout << s.isPalindrome(1231);

    return 0;
}