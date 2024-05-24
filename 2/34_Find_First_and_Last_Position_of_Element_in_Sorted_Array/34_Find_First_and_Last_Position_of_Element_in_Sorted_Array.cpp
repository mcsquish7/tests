#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &arr, int target, int& count)
    {
        int left = 0;
        int right = arr.size() - 1;
        int result = 0; // Индекс искомого элемента

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // Если текущий элемент меньше целевого значения,
            // двигаем левую границу поиска вправо
            if (arr[mid] < target)
            {
                left = mid + 1;
            }
            // Если текущий элемент больше целевого значения,
            // обновляем результат и двигаем правую границу поиска влево
            else
            {
                result = mid;
                right = mid - 1;
            }
        }
        if (target != arr[result])
        {
            result = -1;
        }

        int temp = arr.size()-1;
        if (result != -1)
        {   
            while (*(arr.begin() + result) == target and arr.size() != 0 and result <= temp)
            {
                arr.erase(arr.begin() + result);
                temp--;
                count++;
            }
            
            // arr.erase(arr.begin() + result);
        }

        return result;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {   
        if (nums.size() == 0)
        {
            return {-1, -1};
        }
        if (nums.size() == 1 and target == nums[0])
        {
            return {0,0};
        }
        else if (nums.size() == 1 and target != nums[0])
        {
            return {-1, -1};
        }
        int count = 0;
        int result = binarySearch(nums, target, count);
        // int result_2 = binarySearch(nums, target);

        if (result == -1 and count == 0)
        {
            return {-1, -1};
        }
        if (result != -1 and count == 0)
        {
            return {result, result};
        }
        
        return {result, result + (count-1)};
    }
};

int main()
{   
    vector<int> nums = {5,7,7,8};
    Solution sol;
    vector <int> temp = sol.searchRange(nums, 8);
    for (auto &el : temp)
    {
        cout << el << '\t';
    }
    
    return 0;
}