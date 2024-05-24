#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {   
        if ((p == nullptr and q == nullptr))
        {
            return true;
        }
        else if ((p == nullptr and q != nullptr) || (p != nullptr and q == nullptr))
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }
        
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};


int main()
{   
    TreeNode n_l1(1);
    TreeNode n_r1(2);
    TreeNode n_l2(2);
    TreeNode n_r2(1);
    TreeNode node1(1, &n_l1, &n_r1);
    TreeNode node2(1, &n_l2, &n_r2);
    TreeNode node3(2, &node1, &node2);
    Solution sol;
    std :: cout << sol.isSameTree(&node1, &node2);
    return 0;
}