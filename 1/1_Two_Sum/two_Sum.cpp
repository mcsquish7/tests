#include <vector>
#include <algorithm>
#include <iostream>
#include <forward_list>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {   
        for (int i = 0; i < nums.size()-1; ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                if(nums[i]+nums[j]==target)
                    return {i, j};
            }
            
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> a = {3,2,4};
    int target = 6;
    // sol.twoSum(a, target);
    for (int i = 0; i < sol.twoSum(a, target).size(); i++)
    {
        cout << sol.twoSum(a, target)[i] << "\t";
    }
    
    
    return 0;
}