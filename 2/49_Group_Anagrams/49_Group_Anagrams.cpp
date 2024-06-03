#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread> // работа с потоками
#include <chrono>
#include <unordered_map>

using namespace std;

class Simpletimer
{
public:
    Simpletimer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    
    ~Simpletimer()
    {
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> durat = end - start;
        std::cout << "time doing programm = " << durat.count() << std::endl;
    }
private:
    // std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::system_clock::time_point start, end;
};

class Solution {
public:
    bool isAnagram(string s, string t) 
    {   
        if (size(s) != size(t))
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s != t)
            return false;
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {   
        vector<string> temp;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++)
        {   
            bool found = false;
            for (auto& vec : ans) 
            {
                if (find(vec.begin(), vec.end(), strs[i]) != vec.end()) 
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                continue;
            }
            else
            {
                temp.push_back(strs[i]);
            }

            // temp.push_back(strs[i]);
            for (int j = i+1; j < strs.size(); j++)
            {
                if (isAnagram(strs[i], strs[j]))
                {
                    temp.push_back(strs[j]);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

class Solution_1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main()
{   
    Simpletimer timer;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution_1 sol;
    sol.groupAnagrams(strs);

    return 0;
}