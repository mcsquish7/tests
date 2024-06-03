#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            currentSum = std::max(nums[i], currentSum + nums[i]);
            maxSum = std::max(maxSum, currentSum);
        }

        return maxSum;    
    }
};

int main()
{

    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    sol.maxSubArray(v);
    
    return 0;
}