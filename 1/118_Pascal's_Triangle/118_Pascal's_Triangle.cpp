#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {   
        vector<vector<int>> result = {{1}, {1,1}};
        vector<int> temp;
        vector<int> current;
        if (numRows == 1)
        {
            return {{1}};
        }
        if (numRows==2)
        {
            return {{1}, {1,1}};
        }
        int colls = 3;
        for (int i = 2; i < numRows; ++i)
        {
            temp = result[i-1];
            current.emplace_back(1);
            for (int j = 1; j < colls; ++j)
            {   
                if (j==colls-1)
                {
                    current.emplace_back(1);
                }
                else
                {
                   current.emplace_back(temp[j-1]+temp[j]); 
                }
                
            }
            ++colls;
            result.emplace_back(current);
            current.clear();
            temp.clear();
        }
        
        return result;   
    }
};


int main()
{   
    Solution sol;
    vector<vector<int>> result = sol.generate(5);
    for (auto &el : result)
    {
        for (auto &ell : el)
        {
            cout << ell << "\t";
        }
        cout << endl;
    }
    
    return 0;
}