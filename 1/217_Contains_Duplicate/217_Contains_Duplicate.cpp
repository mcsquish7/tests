class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        for (auto &el : nums)
        {
            if (s.count(el))
                return true;
            s.emplace(el);
        }
        return false;    
    }
};
// второй способ
class Solution_1 {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums.at(i+1) == nums.at(i))
            {
                return true;
            }
        }
        return false;        
    }
};