class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        for(;i >= 0; --i){
            for (int j = nums.size()-1; j>i; --j){
                if (nums[i] < nums[j]){
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    sort(nums.begin()+i+1, nums.end());
                    return;
                }
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};