#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        string s = to_string(x);
        char temp;
        int ans;
        int k = 0, n = s.size() / 2;
        if (s[0] == '-')
        {
            k = 1;
            if (s.size() % 2 == 0)
            {
                n--;
            }
        }
        for (int i = k; i < n+k; i++)
        {
            temp = s[i];
            s[i] = s[s.size() - 1 - i + k];
            s[s.size() - 1 - i + k] = temp;
        }
        try
        {
            ans = stoi(s);
        }
        catch (const std::exception &e)
        {
            return 0;
        }

        return ans;
    }
};

int main()
{
    int x = 1;
    Solution sol;
    cout << sol.reverse(x);
    return 0;
}