class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long result=INT_MAX;// If target is negative, INT_MAX-target will definitely overflow, therefore use long.
        sort(nums.begin(), nums.end());
        // Since j=i+1 and k starts from the last element, i can stop at the last 3rd element.
        for (int i = 0; i < nums.size()-2; ++i) {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                // Updating the closest
                if (abs(nums[i] + nums[l] + nums[r]-target) < abs(result-target)) {
                    result = nums[i] + nums[l] + nums[r];
                    // When the best result found, quit early
                    if (result == target) return target;
                }
                // Trying to get closer to the result.
                // In the 3sum problem, the target is 0.
                if (nums[i] + nums[l] + nums[r] < target) {
                    ++l;
                } else {
                    --r;
                }
            }
            // Skipping duplicated target for little 2sum problem
            while(i < nums.size()-2 && nums[i]==nums[i+1])++i;
        }
        return result;
    }
};