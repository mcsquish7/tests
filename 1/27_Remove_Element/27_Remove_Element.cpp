#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {   
        auto it = remove(nums.begin(), nums.end(), val);
        int count = 0;
        for (auto i = nums.begin(); i != it; ++i)
        {   
            count++;
        }
        // nums.erase(it, nums.end());
        return count;
    }
};

int main()
{   
    vector<int> nums = {0,1,2,2,3,0,4,2};
    Solution s;
    cout << s.removeElement(nums, 2) << endl;

    for (auto &el : nums)
    {
        cout << el << '\t';
    }
    
    return 0;
}