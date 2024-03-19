#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {   
        vector<int> nums_unic;
        unique_copy(nums.begin(), nums.end(), back_inserter(nums_unic));
        return nums_unic.size();
    }
};
int main()
{
    vector<int> v={1,1,5,5,4,8,8,9,9,11,11,11};
    Solution sol;
    cout << sol.removeDuplicates(v);
    return 0;
}