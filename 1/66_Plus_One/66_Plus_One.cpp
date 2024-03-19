#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//     string temp = "";
//     for (int i = 0; i < digits.size(); i++) {
//         temp += to_string(digits[i]);
//     }
//     long long result = stoll(temp);
//     result++;
//     temp = to_string(result);
//     vector<int> updatedDigits;
//     for (int i = 0; i < temp.size(); i++) {
//         updatedDigits.push_back(temp[i] - '0');
//     }
//     return updatedDigits;
//     }
// };

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        for (int i = size(digits)-1; i >= 0; i--)
        {   
            if (i == size(digits)-1)
            {
                digits[i]++;
            }
        
            if (digits[i] == 10)
            {
                digits[i]=0;
                if (i!=0)
                {
                    digits[i-1]++;
                }
                else
                {
                    digits.push_back(0);
                    digits[i]=1;
                }
                
            }
            
        }
        return digits;
    }
};

int main()
{
    Solution sol;
    vector<int> digits = {9,9,9,9,8,9};
    sol.plusOne(digits);
    for (auto &el : digits)
    {
        cout << el << endl;
    }
    return 0;
}