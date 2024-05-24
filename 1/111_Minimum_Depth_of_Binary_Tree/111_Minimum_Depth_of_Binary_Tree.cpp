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

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        // Base case: If the root is null, the depth is 0.
        if (!root)
            return 0;

        // Case 1: Only left child exists, return 1 plus the minimum depth of the left subtree.
        if (root->left && !root->right)
            return 1 + minDepth(root->left);

        // Case 2: Only right child exists, return 1 plus the minimum depth of the right subtree.
        else if (root->right && !root->left)
            return 1 + minDepth(root->right);

        // Case 3: Both left and right children exist, return 1 plus the minimum depth among both subtrees.
        else
        {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            return 1 + min(left, right);
        }

        // Default return (not necessary in this case, as all possible scenarios are covered above).
        return 0;
    }
};