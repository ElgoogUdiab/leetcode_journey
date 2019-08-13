class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size()==0) return {-1, -1};
        int left_result = searchLeft(nums, target);
        return left_result < nums.size() && nums[left_result] == target ? vector<int>{left_result, searchLeft(nums, target+1)-1} : vector<int>{-1, -1};
    }
    
    int searchLeft(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = (r-l)/2+l;
            if (nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};