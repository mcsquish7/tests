#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c = count(nums.begin(), nums.end(), 0);
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        for (int i = 0; i < c; i++)
        {
            nums.emplace_back(0);
        }
    }
};

int main()
{   
    vector<int> v = {2,0,4,0,6,4,8,0,9,0};
    Solution sol;
    sol.moveZeroes(v);
    for (auto &el : v)
    {
        cout << el << "\t";
    }
    
    return 0;
}