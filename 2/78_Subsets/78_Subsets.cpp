#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1)
        {
            return {{}, nums};
        }
        if (nums.size() == 2)
        {
            return {{}, nums, {nums[0]}, {nums[1]}};
        }

        vector<vector<int>> ans = {{}, nums};
        for (int i = 0; i < nums.size(); ++i)
        {
            ans.push_back({nums[i]});
        }
        vector<int> temp;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            temp.emplace_back(nums[i]);
            for (int j = i + 1; j < nums.size(); j++)
            {
                temp.push_back(nums[j]);
                ans.push_back(temp);
                temp.pop_back();
            }
            temp.pop_back();
        }
        temp.clear();
        int k = 2 + nums.size();
        for (int h = 0; h < nums.size() - 3; h++)
        {
            int kk = ans.size();
            for (int i = 0; i < nums.size() - 2 - h; i++)
            {
                temp.push_back(nums[i]);
                for (int j = k; j < kk; j++)
                {
                    if (find(ans[j].begin(), ans[j].end(), nums[i]) == ans[j].end() and find_if(ans[j].begin(), ans[j].end(), [&](int a)
                                                                                                { return a < nums[i]; }) == ans[j].end())
                    {
                        for (auto &el : ans[j])
                        {
                            temp.push_back(el);
                        }
                        ans.push_back(temp);
                        temp.clear();
                        temp.push_back(nums[i]);
                    }
                }
                temp.clear();
            }

            k = kk;
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    Solution sol;
    sol.subsets(v);
    return 0;
}