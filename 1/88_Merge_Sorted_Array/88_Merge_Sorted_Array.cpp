#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m, nums1.end());
        for (int i = 0; i < n; i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
    }
};

int main()
{   
    Solution sol;
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};
    int m=3, n=3;
    sol.merge(a,m,b,n);

    for (auto &el : a)
    {
        cout << el << "\t";
    }
    
    return 0;
}