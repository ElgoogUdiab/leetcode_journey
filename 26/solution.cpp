class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.size() <=1 ) return nums.size();
        int size=0;
        for(int i=0;i<nums.size()-1;++i){
            if (nums[i]!=nums[i+1]){
                nums[++size] = nums[i+1];
            }
        }
        return size+1;
    }
};