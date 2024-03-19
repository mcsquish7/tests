#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> result;
        if (len1 > len2)
        {   
            for (auto &el : nums2)
            {
                auto iter = find(nums1.begin(), nums1.end(), el);
                if (iter != nums1.end())
                {
                    nums1.erase(iter);
                    result.emplace_back(el);
                }    
            }
        }
        else
        {
            for (auto &el : nums1)
            {
                auto iter = find(nums2.begin(), nums2.end(), el);
                if (iter != nums2.end())
                {   
                    nums2.erase(iter);
                    result.emplace_back(el);
                }    
            }
        }
         
        return result;   
    }
};

int main()
{   
    vector<int> a = {5,4,8};
    vector<int> b = {2,4,8,5};
    Solution sol;
    vector<int> V = sol.intersect(a,b);
    // for (auto &el : a)
    // {
    //     cout << el << "\t";
    // }
    // cout << endl;
    // for (auto &el : b)
    // {
    //     cout << el << "\t";
    // }
    for (auto &el : V)
    {
        cout << el << "\t";
    }
    
    return 0;
}