#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int k = 0;
        vector<int> ans;
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        while (ans.size() != (n+1)*(m+1))
        {
            for (int j = k; j <= (n-k); j++)
            {
                ans.emplace_back(matrix[k][j]);
                if (ans.size() == (n+1)*(m+1))
                {
                    return ans;
                }
            }
            for (int i = (1+k); i <= (m-k); i++)
            {
                ans.emplace_back(matrix[i][(n-k)]);
                if (ans.size() == (n+1)*(m+1))
                {
                    return ans;
                }
            }
            for (int j = (n-1-k); j >= k; --j)
            {
                ans.emplace_back(matrix[(m-k)][j]);
                if (ans.size() == (n+1)*(m+1))
                {
                    return ans;
                }
            }
            for (int i = (m-1-k); i >= (1+k); --i)
            {
                ans.emplace_back(matrix[i][k]);
                if (ans.size() == (n+1)*(m+1))
                {
                    return ans;
                }
            }
            k++;
            
        }
        return ans;   
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution sol;
    vector<int> ans = sol.spiralOrder(matrix);
    for (auto &el : ans)
    {
        cout << el << "\t";
    }
    
    return 0;
}