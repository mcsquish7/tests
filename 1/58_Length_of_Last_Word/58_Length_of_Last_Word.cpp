#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) 
    {   
        int count = 0;
        int i = s.size()-1;
        while (s[i] == ' ')
        {
            i--;
        }
        for (int ii = i; ii >= 0; ii--)
        {   
            if (s[ii] == ' ')
            {
                return count;
            }
            count++;
        }
        return count;
    }
};

int main()
{
    string str = "Hello World";

    Solution s;
    cout << s.lengthOfLastWord(str);
    return 0;
}