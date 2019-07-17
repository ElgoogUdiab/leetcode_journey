class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end()); // essential for removing duplicated results
        for (int i = 0; i < nums.size(); ++i) {
            // skipping duplicated results
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            // reduce to the two-sum problem
            unordered_set<int> hash_table;
            for (int j = i + 1; j < nums.size(); ++j) {
                int target = -nums[i] - nums[j];
                if (hash_table.count(target)) {
                    output.push_back({nums[i], nums[j], target});
                    // skipping duplicated results
                    while (j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;
                }
                hash_table.insert(nums[j]);
            }
        }
        return output;
    }
};