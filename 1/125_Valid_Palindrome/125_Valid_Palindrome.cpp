#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        // Удаляем все символы, кроме букв и цифр
        s.erase(remove_if(s.begin(), s.end(), [](char c) {return !isalnum(c);}), s.end());
        // Приводим все буквы к нижнему регистру
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); });
        const int SIZE = s.size();
        for (int i = 0; i < SIZE/2; i++)
        {
            if (s[i] != s[(SIZE-1)-i])
            {
                return false;
            }
            
        }
        return true;
    }
};

int main() {
    // string s = "A man, a plan, a canal: Panama";
    string s = "0p";
    // cout << s.size() << endl;
    // // Удаляем все символы, кроме букв
    // s.erase(remove_if(s.begin(), s.end(), [](char c) {
    //     return !isalpha(c);
    // }), s.end());
    
    // // Приводим все буквы к нижнему регистру
    // transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); });
    // cout << s.size() << endl;
    // cout << "Результат: " << s << endl;

    Solution sol;
    cout << sol.isPalindrome(s);
    
    return 0;
}