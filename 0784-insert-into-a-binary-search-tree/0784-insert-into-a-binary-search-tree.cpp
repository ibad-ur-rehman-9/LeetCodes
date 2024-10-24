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
TreeNode* insert(TreeNode*& root, int val) {
        // Base Case
        if(root == nullptr)
        {
            root = new TreeNode;
            root->val = val;
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }

        else if(val > root->val)
        {
            root->right =  insert(root->right,val);
        }

        else{
            root->left =  insert(root->left, val);
        }
        return root;

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // TreeNode* temp = root;
        insert(root,val);
        return root;
    }
};