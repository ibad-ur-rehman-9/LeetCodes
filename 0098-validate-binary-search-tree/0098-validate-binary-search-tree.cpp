class Solution
{
public:
    bool compare(TreeNode *node, bool validBST, vector<int> &nums)
    {
        if (node == nullptr)
        {
            return validBST;
        }

        validBST = compare(node->left, validBST, nums);
        nums.push_back(node->val);
        if ( nums.size() > 1)
        {
            if (nums[nums.size() - 2] >= nums[nums.size() - 1])
            {
                validBST = false;
            }
        }
        validBST = compare(node->right, validBST, nums);
        return validBST;
    }
    bool isValidBST(TreeNode *root)
    {

        vector<int> nums;
        bool validBST = true;
        validBST = compare(root, validBST, nums);
        return validBST;
    }
};