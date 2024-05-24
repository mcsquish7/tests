#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {   
        vector<vector<int>> current = {{1}, {1,1}};
        vector<int> temp;
        vector<int> result;
        if (rowIndex == 0)
        {
            return {{1}};
        }
        if (rowIndex == 1)
        {
            return {1,1};
        }
        int colls = 3;
        for (int i = 2; i <= rowIndex; ++i)
        {
            temp = current[i-1];
            result.emplace_back(1);
            for (int j = 1; j < colls; ++j)
            {   
                if (j==colls-1)
                {
                    result.emplace_back(1);
                }
                else
                {
                   result.emplace_back(temp[j-1]+temp[j]); 
                }
                
            }
            if (i == rowIndex)
            {
                return result;
            }
            
            ++colls;
            current.emplace_back(result);
            result.clear();
            temp.clear();
        }
        
        return {};      
    }
};

int main()
{   
    Solution sol;
    vector<int> result = sol.getRow(6);
    int count = 0;
    for (auto &el : result)
    {
        cout << el << "\t";
        count++;
    }
    cout << endl << count;
    return 0;
}