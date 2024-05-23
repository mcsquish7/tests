#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int count = 0;
        auto temp = lower_bound(nums.begin(), nums.end(), target);

        if (temp != nums.end())
        {
            for (auto it = nums.begin(); it != temp; ++it)
            {
                count++;
            }
        }
        else
        {
            temp = upper_bound(nums.begin(), nums.end(), target);
            for (auto it = nums.begin(); it != temp; ++it)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {1,2,2,6,6,8,9};
    Solution s;
    cout << s.searchInsert(nums, 5);
    return 0;
}