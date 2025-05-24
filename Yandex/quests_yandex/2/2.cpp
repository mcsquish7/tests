#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    string J = "aab"; // drag
    string S = "aabbccd"; // cam
    
    unordered_map<char, int> um;

    for (auto i = J.begin(); i < unique(J.begin(), J.end()); ++i)
    {
        for (auto &el : S)
        {
            if (*i == el)
            {
                um[el]++;
            }
        }
    }
    
    int sum = 0;
    for (auto &el : um)
    {
        sum += el.second;
    }

    cout << sum;

    return 0;
}