#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(),strs.end());
        string result="";
        string first=strs[0], second=strs[strs.size()-1];
        
        for(int i=0;i<first.size();i++)
        {
            if(first[i]!=second[i]){return result;}
            result+=first[i];
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> str = {"flower","fliendly","flight", "fuck", "fucking", "fruct"};
    cout << sol.longestCommonPrefix(str);
    return 0;
}