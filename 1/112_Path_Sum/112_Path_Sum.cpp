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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        
        bool left_sum = hasPathSum(root->left, targetSum - root->val);
        bool right_sum = hasPathSum(root->right, targetSum - root->val);
        
        return left_sum || right_sum;
    }
};

int main()
{
    TreeNode n_l1(0);
    TreeNode n_r1(5);
    TreeNode n_l2(6);
    TreeNode n_r2(1);
    TreeNode node1(3, &n_l1, &n_r1);
    TreeNode node2(4, &n_l2, &n_r2);
    TreeNode node3(2, &node1, &node2);
    Solution sol;
    cout << sol.hasPathSum(&node3, 10);

    return 0;
}