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

    vector<int> helper(TreeNode* root, vector<int>& inOrderValues)
    {
        if(root == nullptr)
        {
            return inOrderValues;
        }

        helper(root->left, inOrderValues);
        inOrderValues.push_back(root->val);
        helper(root->right, inOrderValues);
        return inOrderValues;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrderValues;
        inOrderValues = helper(root, inOrderValues);
        return inOrderValues;
    }
};