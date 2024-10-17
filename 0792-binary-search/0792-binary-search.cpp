class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1 && target == nums[0]) return 0;

        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;  // Adjust end to mid - 1 to properly shrink the search space.
            } else {
                start = mid + 1;
            }
        }
        return -1;  // Target not found.
    }
};
