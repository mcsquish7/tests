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
};