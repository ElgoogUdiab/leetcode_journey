class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        // The always annoying situation. Let them go
        if (n<4) return {};
        // The second annoying situation.
        if (n==4){
            if (nums[0] + nums[1] + nums[2] + nums[3] == target)
                return {nums};
            return {};
        }
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        int last_two_sum = nums[n-2] + nums[n-1], last_three_sum = nums[n-3] + nums[n-2] + nums[n-1];
        // If the sum is too large, break (in for condition)
        // If the sum is too small, continue (the first command in for loop)
        for (int i = 0; i < n-3 && nums[i] + nums[i+1] + nums[i+2] + nums[i+3] <= target; ++i) {
            if (nums[i] + last_three_sum < target) continue;
            for (int j=i+1; j < n-2 && nums[i] + nums[j] + nums[j+1] + nums[j+2] <= target; ++j){
                if (nums[i] + nums[j] + last_two_sum < target) continue;
                // The 2sum LR solution
                // The LR pointer initialization
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    if (nums[i] + nums[j] + nums[l] + nums[r] == target) {
                        output.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        while (l < r && nums[l] == nums[l - 1])
                            ++l;
                    } else if (nums[i] + nums[j] + nums[l] + nums[r] < target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
                // Skipping nums[j]
                while(j < nums.size()-2 && nums[j]==nums[j+1])++j;
            }
            // Skipping nums[i]
            while(i < nums.size()-3 && nums[i]==nums[i+1])++i;
        }
        return output;
    }
};