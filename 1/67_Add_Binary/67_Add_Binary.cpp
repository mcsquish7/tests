#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution_1
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';

            if (j >= 0)
                carry += b[j--] - '0';

            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.size()-1;
        int j = b.size()-1;
        string ans;
        int temp = 0;
        
        while (i >= 0 && j >= 0)
        {
            if (a[i] == '1' && b[j] == '1')
            {   
                if (temp != 0)
                {
                    ans += "1";
                }
                else
                {
                    ans += "0";
                    temp++;
                }
            }
            else if((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0'))
            {
                if (temp == 0)
                {
                    ans += "1";
                }
                else
                {   
                    ans += "0";
                    // temp--;
                }
            }
            else
            {
                if (temp == 0)
                {
                    ans += "0";
                }
                else
                {
                    ans += "1";
                    temp--;
                }
            }
            i--;
            j--;
        }
        if(i > j)
        {
            while (i >= 0)
            {
                if (a[i] == '0')
                {
                    if (temp == 0)
                    {
                        ans += "0";
                    }
                    else
                    {   
                        ans += "1";
                        temp--;
                    }
                }
                else if (a[i] == '1')
                {
                    if (temp == 0)
                    {
                        ans += "1";
                    }
                    else
                    {   
                        ans += "0";
                    }
                }
                i--;
            }  
        }
        else if(j > i)
        {
            while (j >= 0)
            {
                if (b[j] == '0')
                {
                    if (temp == 0)
                    {
                        ans += "0";
                    }
                    else
                    {   
                        ans += "1";
                        temp--;
                    }
                }
                else if (b[j] == '1')
                {
                    if (temp == 0)
                    {
                        ans += "1";
                    }
                    else
                    {   
                        ans += "0";
                    }
                }
                j--;
            }  
        }
        
        while (temp != 0)
        {
            ans += '1';
            temp--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    string a = "110010", b = "10111";
    Solution s;
    cout << s.addBinary(a,b);
    return 0;
}