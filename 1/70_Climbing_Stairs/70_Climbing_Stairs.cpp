#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
        int result_b = 1;
        int result = 2;
        int temp;
        if (n<=2) {return n;}

        for (int i =0; i<n-2; i++)
        {   
            temp = result;
            result += result_b;
            result_b = temp;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(45);
    return 0;
}