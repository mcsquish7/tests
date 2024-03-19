#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution 
{
public:
    int strStr(string a, string b) 
    {
        if (a.find(b) != string::npos)
            return a.find(b);
        else
        return -1;
    }
};

int main()
{
    string haystack = "bustad", needle = "sad";
    Solution sol;
    sol.strStr(haystack,needle);

    return 0;
}