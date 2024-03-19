#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < size(nums); i+=2)
        {
            if (nums[i]!=nums[i-1])
            {
                return nums[i-1];
            }
        }   
        return nums[size(nums)-1];
    }
};

int main()
{   
    vector<int> nums = {5,5,4,1,2,1,2};
    Solution sol;
    cout << sol.singleNumber(nums);
    
    return 0;
}