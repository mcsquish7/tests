class Solution {
public:
    int divide(int dividend, int divisor) 
    {   
        int temp = dividend;
        int count = 0;
        if (abs(dividend) < abs(divisor))
            return 0;
        if (dividend == divisor)
            return 1;
        else if (abs(dividend) == abs(divisor))
            return -1;
        if(dividend == 0)
            return 0;
        if(divisor == 1)
            return dividend;
        if(divisor == -1)
        {
            if (dividend < 0)
            {
                dividend++;
                dividend = -dividend;
                if (dividend == INT_MAX)
                    return dividend;
                dividend++;
                return dividend;
            }
            return -dividend;
        } 
        if (dividend > 0 && divisor > 0)
        {
            while (temp >= 0)
            {
                temp -= divisor;
                count++;
            }
            count--;
        }
        else if (dividend < 0 && divisor < 0)
        {
            while (temp <= 0)
            {
                temp += -divisor;
                count++;
            }
            count--;
        }
        else if (dividend < 0 && divisor > 0)
        {
            while (temp <= 0)
            {
                temp += divisor;
                count--;
            }
            count++;
        }
        else if (dividend > 0 && divisor < 0)
        {
            while (temp >= 0)
            {
                temp += divisor;
                count--;
            }
            count++;
        }
        return count; 
    }
};

// второй способ