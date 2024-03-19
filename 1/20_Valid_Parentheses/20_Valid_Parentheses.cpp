#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {   
        stack<int> st;
        bool result=true;
        int i = 0;
        while (i<s.size())
        {
            if (s[i]==')' && st.size()!=0 && st.top()=='(')
            {
                st.pop();
            }
            else if (s[i]==']' && st.size()!=0 && st.top()=='[')
            {
                st.pop();
            }
            else if (s[i]=='}' && st.size()!=0 && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.emplace(s[i]);
            }
            i++;
        }
        if (!(st.empty()))
            {
                result = false;
            }
        
        return result;
    }
};

int main()
{   
    string str = "[]{}";
    Solution sol;
    cout << sol.isValid(str);
    return 0;
}