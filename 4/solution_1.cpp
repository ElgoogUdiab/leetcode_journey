/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size = nums1.size()+nums2.size();
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int min1=0, max1=nums1.size(); // Search between [min1, max1)
        int i, j;
        while(min1<=max1){
            i=(min1+max1)/2, j=(total_size+1)/2-i;
            if (i < nums1.size() && nums1[i]<nums2[j-1]){
                min1=i+1;
            } else if (i>0 && nums1[i-1]>nums2[j]) {
                max1=i-1;
            } else {
                int left_max, right_min;
                if (i==0) {
                    left_max = nums2[j-1];
                } else if (j==0) {
                    left_max = nums1[i-1];
                } else {
                    left_max = max(nums1[i-1], nums2[j-1]);
                }
                if (total_size & 1) return left_max;
                if (i==nums1.size()) {
                    right_min = nums2[j];
                } else if (j==nums2.size()) {
                    right_min = nums1[i];
                } else {
                    right_min = min(nums1[i], nums2[j]);
                }
                return (left_max + right_min)/2.0;
            }
        }
        return 0;
    }
};
