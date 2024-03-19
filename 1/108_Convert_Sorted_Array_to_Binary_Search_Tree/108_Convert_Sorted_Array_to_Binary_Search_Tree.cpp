#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution 
{
TreeNode* root;
public:
    TreeNode* getBST(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = getBST(nums, left, mid-1);
        root->right = getBST(nums, mid+1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {   
        return getBST(nums, 0, (int)size(nums)-1);
    }
    ~Solution()
    {
        delete root;
    }
};

int main()
{   
    vector<int> v = {-1,0,2,9};
    Solution sol;
    sol.sortedArrayToBST(v);
    return 0;
}