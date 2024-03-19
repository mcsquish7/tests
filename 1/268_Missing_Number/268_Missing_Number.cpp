class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        set<int> s;
        for (auto &el : nums)
        {
            s.emplace(el);
        }
        for(int i = 0; i<nums.size()+1; i++)
        {
            if (!s.count(i))
                return i;
        }
        return 0;    
    }
};
// второй способ
class Solution_1
{
public:
    int missingNumber(vector<int>& nums) 
    {   
        sort(nums.begin(), nums.end());
        if (nums.at(0) != 0)
            return 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums.at(i+1) != nums.at(i)+1)
                return (i+1);
        }
        return nums.size();   
    }
};