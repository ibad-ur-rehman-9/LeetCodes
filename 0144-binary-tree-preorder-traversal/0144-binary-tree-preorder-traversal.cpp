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
    vector<int> helper(TreeNode* root, vector<int>& preOrderValues)
    {
        if(root == nullptr)
        {
            return preOrderValues;
        }

        preOrderValues.push_back(root->val);
        helper(root->left, preOrderValues);
        helper(root->right, preOrderValues);

        return preOrderValues;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrderValues;
        preOrderValues = helper(root, preOrderValues);
        return preOrderValues;
    }
};