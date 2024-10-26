class Solution {
public:
    int ans = -1;
    
    int helper(TreeNode* root, int k, int &NodeCount) {
        if (root == nullptr) {
            return ans;
        }
        
        // Traverse the left subtree
        helper(root->left, k, NodeCount);
        
        // Increment NodeCount and check if it matches k
        ++NodeCount;
        if (k == NodeCount) {
            ans = root->val;
            return ans;
        }
        
        // Traverse the right subtree
        helper(root->right, k, NodeCount);
        
        return ans;
    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        return helper(root, k, i);
    }
};
