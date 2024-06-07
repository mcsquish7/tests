#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> rows;
        unordered_set<int> cols;

        for (int i = 0; i < matrix.size(); i++)
        {   
            if (find(matrix[i].begin(), matrix[i].end(), 0) != matrix[i].end())
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    if (matrix[i][j] == 0)
                    {   
                        rows.emplace(i);
                        cols.emplace(j);
                    }
                }
            }
        }
        for (auto &el : rows)
        {
            for (int i = 0; i < matrix[el].size(); i++)
            {
                matrix[el][i] = 0;
            }
            
        }
        for (auto &el : cols)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][el] = 0;
            }
        }
    }
};

int main()
{   
    // vector<vector<int>> temp;

    // unordered_set<int> rows;
    // unordered_set<int> cols;

    vector<vector<int>> matrix = {
        {1,1,1,1},
        {2,0,1,0},
        {1,1,1,1},
        {1,1,0,1}
    };

    // for (int i = 0; i < matrix.size(); i++)
    // {   
    //     if (find(matrix[i].begin(), matrix[i].end(), 0) != matrix[i].end())
    //     {
    //         for (int j = 0; j < matrix[i].size(); j++)
    //         {
    //             if (matrix[i][j] == 0)
    //             {   
    //                 rows.emplace(i);
    //                 cols.emplace(j);
    //                 // temp.push_back({i,j});
    //             }
    //         }
    //     }
    // }
    // for (auto &el : rows)
    // {
    //     for (int i = 0; i < matrix[el].size(); i++)
    //     {
    //         matrix[el][i] = 0;
    //     }
        
    // }
    // for (auto &el : cols)
    // {
    //     for (int i = 0; i < matrix.size(); i++)
    //     {
    //         matrix[i][el] = 0;
    //     }
    // }
    
    Solution sol;
    sol.setZeroes(matrix);

    return 0;
}