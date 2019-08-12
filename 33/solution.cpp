class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size()==0) return -1;
        int l = 0, r = nums.size()-1;
        
        while (l <= r){
            int mid = (l + r)/2;
            // Free gift
            if (target == nums[mid]) return mid;
            if (target == nums[r]) return r;
            if (target == nums[l]) return l;
            
            // The normal binary search early exit condition when target out of bound.
            if (nums[l] < nums[r] && (target < nums[l] || nums[r] < target)) return -1;
            // The rotated early exit condition when target out of bound
            if (nums[l] > nums[r] && (nums[r] < target && target < nums[l])) return -1;
            
            if (nums[mid] < nums[r]) {
                if(nums[mid] < target && target < nums[r]) {
                    // --------[mid](l)--------[target]--------[r]--------
                    // normal binary search afterwards
                    l = mid+1;
                } else {
                    // --------(r)[mid]--------[r]--------[l]--------[target]--------
                    // --------[target]--------(r)[mid]--------[r]--------[l]--------
                    // or
                    // --------[l]--------[target]--------(r)[mid]--------[r]-------- normal binary search
                    r = mid-1;
                }
            } else {
                // nums[l] < nums[mid]
                if(nums[l] < target && target < nums[mid]) {
                    // --------[l]--------[target]--------(r)[mid]--------
                    // normal binary search afterwards
                    r = mid-1;
                } else {
                    // --------[r]--------[l]--------[mid](l)--------[target]--------
                    // --------[target]--------[r]--------[l]--------[mid](l)--------
                    // or
                    // --------[l]--------[mid](l)--------[target]--------[r]-------- normal binary search
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};