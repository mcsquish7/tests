#include <vector>
#include <list>
#include <stack>
#include <iostream>

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

class Solution {
public:
    int maxDepth_L(TreeNode* root) 
    {   
        if (root == nullptr)
        {
            return 1;
        }
        return max(maxDepth_L(root->left), maxDepth_L(root->right)) +1;
    }
    int maxDepth_R(TreeNode* root) 
    {   
        if (root == nullptr)
        {
            return 1;
        }
        return max(maxDepth_R(root->left), maxDepth_R(root->right)) +1;
    }
    bool isBalanced(TreeNode* root) 
    {   
        if(root == nullptr)
            return 1;
        return abs(maxDepth_L(root->left) - maxDepth_R(root->right)) <= 1;
    }
};

class Solution_1 {
public:

    bool ans;

    int getHt(TreeNode* root){
        if(!root) return 0;
        int lst = getHt(root->left);
        int rst = getHt(root->right);
        if(abs(lst-rst) > 1) ans = false;
        return 1 + max(lst, rst);

    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        getHt(root);
        return ans;
    }
};