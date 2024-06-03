#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {   
        const int rows = board.size();
        const int cols = board[0].size();
        unordered_set<char> s;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {   
                if (board[i][j] != '.')
                {
                    if (!(s.insert(board[i][j]).second))
                    {
                        return false;
                    }
                }
            }
            s.clear(); 
        }
        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < cols; i++)
            {   
                if (board[i][j] != '.')
                {
                    if (!(s.insert(board[i][j]).second))
                    {
                        return false;
                    }
                }
            }
            s.clear();   
        }
        int k = 0;
        
        for (int g = 0; g < 3; g++)
        {
            for (int l = 0; l < 3; l++)
            {
                for (int i = 0+3*g; i < 3+3*g; i++)
                {
                    for (int j = 0+3*k; j < 3+3*k; j++)
                    {   
                        if (board[i][j] != '.')
                        {
                            if (!(s.insert(board[i][j]).second))
                            {
                                return false;
                            }
                        }
                    } 
                }
                k++;
                s.clear();
            }
            k = 0;
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = 
        {{'5','3','9','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    Solution sol;
    cout << sol.isValidSudoku(board);

    return 0;
}