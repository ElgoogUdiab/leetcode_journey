class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // The always annoying situation. Let them go
        if (nums.size()<3) return {};
        
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        
        // Since l=i+1 and r starts from the last element, i can stop at the last 3rd element.
        // Also, when nums[i]>0, all remaining elements are bigger than 0, therefore no more solution
        for (int i = 0; i < nums.size()-2 && nums[i]<=0; ++i) {
            // Each i repesents a 2sum puzzle, with candidate numbers nums[i+1:] and target number nums[i]
            // The LR pointer initialization
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    output.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    // Skipping duplicated left value to avoid duplicated solution
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                } else if (nums[i] + nums[l] + nums[r] < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
            // Skipping duplicated target for little 2sum problem
            while(i < nums.size()-2 && nums[i]==nums[i+1])++i;
        }
        return output;
    }
};