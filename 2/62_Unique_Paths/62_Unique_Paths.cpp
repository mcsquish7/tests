#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> ans(n, 1);
        for (int i = 1; i < m; i++)
        {
            int prev = 1;
            for (int j = 1; j < n; j++)
            {
                ans[j] += prev;
                prev = ans[j];
            }
        }
        return ans[n - 1];
    }
};

int main()
{
    Solution sol;
    sol.uniquePaths(3, 7);
    return 0;
}