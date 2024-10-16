class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>>& result , int i)
    {
        // Base Case
        if(i >= nums.size())
        {
            result.push_back(nums);
            return;
        }

        // We have to swap i with every other index as well as it with itself
        for(int j = i ; j < nums.size() ; j++)
        {
            swap(nums[i] , nums[j]);
            solve(nums, result,i+1);
            // Backtracking
            // When returning from the ith pos, the function wants the same string as it received originally. So to get that string, we swap that again.
            swap(nums[i],nums[j]); 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int index = 0; // Starting Index
        solve(nums, result, index);
        return result;
    }
};