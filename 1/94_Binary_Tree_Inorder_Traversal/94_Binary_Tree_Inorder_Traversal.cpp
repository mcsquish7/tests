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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* current= root;
        while (current != nullptr || !st.empty())
        {
            while (current != nullptr)
            {
                st.emplace(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            ans.emplace_back(current->val);
            current = current->right;
        }
        return ans;
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
    vector<int> res = sol.inorderTraversal(&node3);

    for (auto &el : res)
    {
        cout << el << "\t";
    }
    
    return 0;
}