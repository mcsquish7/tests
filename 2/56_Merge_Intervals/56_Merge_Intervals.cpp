#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        if (v.size() == 1)
        {
            return v;
        }

        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        vector<int> temp = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (temp[1] < v[i][0])
            {
                ans.emplace_back(temp);
                temp = v[i];
                if (i == v.size() - 1)
                {
                    ans.emplace_back(temp);
                }
                continue;
            }
            if (temp[1] < v[i][1])
            {
                temp[1] = v[i][1];
            }
            if (i == v.size() - 1)
            {
                ans.emplace_back(temp);
            }
        }

        return ans;
    }
};

int main()
{

    vector<vector<int>> v = {{1, 4}, {0, 4}};
    // vector<vector<int>> v = {{1, 3}, {6, 9}, {1, 5}, {8,11}};
    Solution sol;
    sol.merge(v);
    return 0;
}