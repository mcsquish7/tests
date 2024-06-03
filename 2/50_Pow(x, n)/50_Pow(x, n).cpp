#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0 or x == 1)
        {
            return 1;
        }
        if (n == 1)
        {
            return x;
        }
        if (n > 0)
        {
            double temp = x;
            for (int i = 0; i < n - 1; i++)
            {
                x *= temp;
            }
        }
        if (n < 0)
        {
            double temp = x;
            for (int i = 0; i < abs(n) - 1; i++)
            {
                x *= temp;
            }
            return 1 / x;
        }

        return x;
    }
};

class Solution_1
{
public:
    double myPow(double x, int n)
    {

        if (n == 0)
            return 1;

        if (n < 0)
        {
            n = abs(n);
            x = 1 / x;
        }

        if (n % 2 == 0)
            return myPow(x * x, n / 2);

        else
            return x * myPow(x, n - 1);
    }
};

int main()
{
    Solution sol;
    cout << sol.myPow(2.10000, 3);
    return 0;
}