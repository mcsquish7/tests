#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==1)
        {
            return nums.at(0);
        }
        
        sort(nums.begin(), nums.end());
        int temp = 1;
        for (int i = 0; i < n-1; i++)
        {   
            if (nums.at(i+1) == nums.at(i))
            {
                temp++;
                if (temp == n/2 + 1)
                {
                    return nums.at(i);
                }
                
            }
            else
            {
                temp = 1;
            }
            if (temp != (n/2 + 1) & i == (n/2))
            {
                return nums.at(i);
            }
            
        }
        return -1;
    }
};

int main()
{   
    vector<int> nums = {2,2};
    Solution sol;
    cout << sol.majorityElement(nums);
    return 0;
}