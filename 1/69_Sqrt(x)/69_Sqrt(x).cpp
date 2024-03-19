#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


class Solution 
{
public:
    int mySqrt(int x) 
    {   
        if (x<2) {return x;}
        int left = 1;
        int right = x;
        int result = -1; // Индекс искомого элемента

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid > x/mid)
            {
                right = mid - 1;
            }
            else if (mid == x/mid)
            {
                return mid;
            }
    
            else
            {
                result = mid;
                left = mid + 1;
            }
        }
        return result;
    }
};

int main()
{   
    Solution sol;
    cout << sol.mySqrt(2);
    return 0;
}