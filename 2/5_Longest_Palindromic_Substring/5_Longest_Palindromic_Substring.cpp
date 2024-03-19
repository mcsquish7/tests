#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;
        int min_left = 0;
        int max_len = 1;
        int max_right = s.size() - 1;
        for (int mid = 0; mid < s.size();)
        {
            int left = mid;
            int right = mid;
            while (right < max_right && s[right + 1] == s[right])
                right++;     // пропускаем повторы
            mid = right + 1; // идем на некст итерацию
            while (right < max_right && left > 0 && s[right + 1] == s[left - 1])
            {
                right++;
                left--;
            }                               
            int new_len = right - left + 1; // считаем длину палиндрома
            if (new_len > max_len)
            {
                min_left = left;
                max_len = new_len;
            }
        }
        return s.substr(min_left, max_len);
    }
};

int main()
{   
    string s = {"bbaddabbetytec"};
    Solution sol;
    sol.longestPalindrome(s);
    return 0;
}