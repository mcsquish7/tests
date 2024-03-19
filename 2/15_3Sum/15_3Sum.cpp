#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (i != j && i != k && j != k && (nums[i] + nums[j] + nums[k] == 0))
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        s.insert(temp);
                        // ans.emplace_back(temp);
                    }
                }
            }
        }
        for (const auto &el : s)
            ans.push_back(el);
        return ans;
    }
};

// второй способ
class Solution_1
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int k = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < k; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= 0)
                    k--;
                if (nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    Solution_1 sol;
    sol.threeSum(v);
    return 0;
}