class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size()-1;
        int len = right;
        int Area = 0;
        int temp;
        while(left <= right)
        {   
            if (height.at(left) < height.at(right))
            {
                temp = height.at(left) * len;
                left++;
                len--;
            }
            else
            {   
                temp = height.at(right) * len;
                right--;
                len--;
            }
            Area = max(Area, temp);
        }
        return Area;
    }
};