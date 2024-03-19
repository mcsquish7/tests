#include <cmath>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) 
    {   
        int temp=1, res=0;
        int digit;
        int j = 0;
        while (res != 1 & (res != 4 || j<5))
        {   
            res = 0;
            temp = n;
            while (n > 0) 
            {
                digit = n % 10; // Получаем последнюю цифру числа
                n /= 10; // Удаляем последнюю цифру из числа
                res+=pow(digit,2);
            }
            n = res;
            j++;
        }
        if (res == 1)
            return 1;
        
        return 0;
    }
};
// второй способ
class Solution_1 
{
public:
    bool isHappy(int n) 
    {   
        set<int> s;
        int temp, res;
        int digit;
        while (true)
        {   
            s.emplace(n);
            res = 0;
            temp = n;
            while (n > 0) 
            {
                digit = n % 10; // Получаем последнюю цифру числа
                n /= 10; // Удаляем последнюю цифру из числа
                res+=pow(digit,2);
            }
            if (res == 1)
                return 1;
            if (s.count(res))
                return 0;
            n = res;
        }
        
        return 0;
    }
};

int main()
{   
    Solution sol;
    cout << sol.isHappy(2);
    return 0;
}