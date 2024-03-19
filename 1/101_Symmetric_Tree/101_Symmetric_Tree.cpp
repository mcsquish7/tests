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

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        stack<TreeNode *> st_1;
        stack<TreeNode *> st_2;
        TreeNode *current_1 = root->left;
        TreeNode *current_2 = root->right;
        if ((current_1 == nullptr & current_2 != nullptr) || (current_2 == nullptr & current_1 != nullptr))
        {
            return 0;
        }

        if (root == nullptr || (current_1 == nullptr & current_2 == nullptr))
            return 1;
        else if ((current_1->val != current_2->val))
        {
            return 0;
        }
        else
        {
            while ((current_1 != nullptr & current_2 != nullptr) || (!st_1.empty() & !st_2.empty()))
            {

                while (current_1 != nullptr & current_2 != nullptr)
                {
                    st_1.emplace(current_1);
                    current_1 = current_1->left;
                    st_2.emplace(current_2);
                    current_2 = current_2->right;
                    if ((current_1 == nullptr & current_2 != nullptr) || (current_2 == nullptr & current_1 != nullptr))
                    {
                        return 0;
                    }
                    else if ((current_1 != nullptr & current_1 != nullptr))
                    {
                        if ((current_1->val != current_2->val))
                        {
                            return 0;
                        }
                    }
                }
                current_1 = st_1.top();
                st_1.pop();
                current_1 = current_1->right;

                current_2 = st_2.top();
                st_2.pop();
                current_2 = current_2->left;
                if ((current_1 == nullptr & current_2 != nullptr) || (current_2 == nullptr & current_1 != nullptr))
                {
                    return 0;
                }
                else if ((current_1 != nullptr & current_1 != nullptr))
                {
                    if ((current_1->val != current_2->val))
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};

int main()
{
    TreeNode n_l1(0);
    TreeNode n_r1(5);
    TreeNode n_l2(5);
    // TreeNode n_r2_1(1);
    // TreeNode n_r2(0, nullptr, &n_r2_1);
    TreeNode n_r2(0);
    TreeNode node1(3, &n_l1, &n_r1);
    TreeNode node2(3, nullptr, &n_r2);
    TreeNode node3(2, &node1, &node2);
    Solution sol;
    cout << sol.isSymmetric(&node3);

    return 0;
}