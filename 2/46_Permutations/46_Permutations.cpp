#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(const vector<int>& start) 
    {   
        vector<vector<int>> ans;
        vector<int> current = start;
        while (true)
        {
            ans.push_back(current);
            next_permutation(current.begin(), current.end());
            if (current == start)
                return ans;
        }
    }
};