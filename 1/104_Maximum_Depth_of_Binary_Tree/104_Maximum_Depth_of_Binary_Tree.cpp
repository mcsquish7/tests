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

// рекурсивное решение
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {   
        if (root == nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) +1;
    }
};
// решение итеративное:
class Solution_1 {
public:
    int maxDepth(TreeNode* root) 
    {   
        if (root == nullptr)
        {
            return 0;
        }
        int result = 0;
        vector<TreeNode*> current;
        current.emplace_back(root);
        vector<TreeNode*> next;
        while (!current.empty())
        {
            for (auto &el : current)
            {
                if (el->left != nullptr)
                {
                    next.emplace_back(el->left);
                }
                if (el->right != nullptr)
                {
                    next.emplace_back(el->right);
                }
            }
            next.swap(current);
            next.clear();
            ++result;
        }
        return result;
    }
};
int main()
{   TreeNode n_l1(0);
    TreeNode n_r1(5);
    TreeNode n_l2(-2);
    TreeNode n_r2(4);
    TreeNode node1(1, &n_l1, &n_r1);
    TreeNode node2(3, &n_l2, &n_r2);
    TreeNode node3(2, &node1, &node2);
    Solution sol;
    Solution_1 sol1;
    cout << sol.maxDepth(&node3);
    cout << sol1.maxDepth(&node3);
    return 0;
}