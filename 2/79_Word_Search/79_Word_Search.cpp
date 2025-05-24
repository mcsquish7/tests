#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {   
        if (board.size() == 1 and board[0].size() == 1)
        {
            string str = "";
            str.push_back(board[0][0]);
            if (str == word)
            {
                return true;
            }
            else
            {
                return false;
            } 
        }
        if (word.size() > board.size() * board[0].size())
        {
            return false;
        }
        
        
        
        stack<string> st;
        string temp = "";
        int i = 0, j = 0, k = 0;
        string prev = "";
        while (true)
        {
            if (board[i][j] == word[k]) // centre
            {
                temp.push_back(word[k]);
                k++;
                if (temp == word)
                {
                    return true;
                }
                
                if (j != board[0].size() - 1 and board[i][j + 1] == word[k] and (st.empty() or st.top() != "right") and ((temp.size() != 1 and prev != "left") or prev == "")) // right
                {
                    // if ((temp.size() != 1 and prev != "left") or prev == "")
                    // {
                        st.emplace("left");
                        j++;
                        continue;
                    // }
                }
                else if (i != board.size() - 1 and board[i + 1][j] == word[k] and (st.empty() or st.top() != "bot")) // bot  and ((temp.size() != 1 and prev != "top")  or prev == "")
                {
                    if ((temp.size() != 1 and prev != "top")  or prev == "")
                    {
                        st.emplace("top");
                        i++;
                        continue;
                    }
                }
                else if (i != 0 and board[i - 1][j] == word[k] and (st.empty() or st.top() != "top") and ((temp.size() != 1 and prev != "bot")  or prev == "")) // top
                {
                    // if ((temp.size() != 1 and prev != "bot")  or prev == "")
                    // {
                        st.emplace("bot");
                        i--;
                        continue;
                    // }
                }
                else if (j != 0 and board[i][j - 1] == word[k] and (st.empty() or st.top() != "left") and ((temp.size() != 1 and prev != "right")  or prev == "")) // left
                {
                    // if ((temp.size() != 1 and prev != "right")  or prev == "")
                    // {
                        st.emplace("right");
                        j--;
                        continue;
                    // }
                }

                if (st.empty())
                {
                    temp.pop_back();
                    k--;
                    if (j != board[0].size() - 1)
                    {
                        j++;
                    }
                    else if (i != board.size() - 1)
                    {
                        i++;
                        j = 0;
                    }
                    prev = "";
                }

                while (!st.empty())
                {
                    if (st.size() == 1)
                    {
                        prev = st.top();
                        temp.pop_back();
                        k--;
                    }
                    if (st.top() == "bot")
                    {
                        i--;
                        st.pop();
                        temp.pop_back();
                        k--;
                    }
                    else if (st.top() == "top")
                    {
                        i++;
                        st.pop();
                        temp.pop_back();
                        k--;
                    }
                    else if (st.top() == "right")
                    {
                        j++;
                        st.pop();
                        temp.pop_back();
                        k--;
                    }
                    else if (st.top() == "left")
                    {
                        j--;
                        st.pop();
                        temp.pop_back();
                        k--;
                    }
                }
                // temp.pop_back();
                // k--;
            }
            else
            {
                if (j != board[0].size() - 1)
                {
                    j++;
                }
                else if (i != board.size() - 1)
                {
                    i++;
                    j = 0;
                }
                else
                {
                    break;
                }
                
            }
        }
        return false;
    }
};


class Solution_1 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
            if (k == word.length()) {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            
            char temp = board[i][j];
            board[i][j] = '\0';
            
            if (backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) || 
                backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{   
    vector<vector<char>> v = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    string word = "AAB";
    Solution sol;
    cout << sol.exist(v, word);

    return 0;
}