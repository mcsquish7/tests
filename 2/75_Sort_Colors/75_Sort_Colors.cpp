#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto &el : nums)
        {
            m[el]++;
        }
        nums.clear();
        for (int i = 0; i < m[0]; i++)
        {
            nums.emplace_back(0);
        }
        for (int i = 0; i < m[1]; i++)
        {
            nums.emplace_back(1);
        }
        for (int i = 0; i < m[2]; i++)
        {
            nums.emplace_back(2);
        }
    }
};

int main()
{
    vector<int> v = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(v);

    for (auto &el : v)
    {
        cout << el << "\t";
    }
    
    return 0;
}