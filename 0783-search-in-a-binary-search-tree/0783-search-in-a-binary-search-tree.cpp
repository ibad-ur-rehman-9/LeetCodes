/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Not found Case
        if(root == nullptr)
        {
            return nullptr;
        }

        // Found Case
        if(root->val  == val)
        {
            return root;
        }

        // Recursive Calls
        if(val > root->val)
        {
            return searchBST(root->right, val);
        }
        else
        {
            return searchBST(root->left, val);
        }
        return root;
    }
};