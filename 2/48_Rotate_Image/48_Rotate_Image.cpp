#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {   
        int k = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 1 + k; j < matrix[0].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
            k++;
        }
        for (int j = 0; j < matrix[0].size()/2; j++)
        {
           for (int i = 0; i < matrix.size(); i++)
           {
                swap(matrix[i][j], matrix[i][matrix[0].size()-1-j]);
           }
           
        }
         
    }
};

int main()
{
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution sol;
    sol.rotate(matrix);

    return 0;
}