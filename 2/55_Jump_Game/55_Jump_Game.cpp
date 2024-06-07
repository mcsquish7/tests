class Solution {
public:
    bool canJump(vector<int>& nums) 
    {   
        bool ans;

        int k = (nums.size()-1);
        for(int i = nums.size()-2; i >=0; i--)
        {
            if(i + nums[i] >= k )
            {
                ans = true;
                k = i;
            }
            else
            {
                ans = false;
            }
        }

        return ans; 
    }
};