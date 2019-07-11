/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n_1=0, n_2=0;
        auto it_1 = nums1.begin(), it_2 = nums2.begin();
        int i=0, the_big_size = nums1.size()+nums2.size();
        // Merge
        for (; i<=the_big_size/2;++i){
            n_1 = n_2;
            if ( it_1 != nums1.end() && it_2 !=nums2.end() )
                n_2 = *(*it_1 < *it_2 ? it_1++ : it_2++);
            else if (it_1 != nums1.end())
                n_2 = *(it_1++);
            else if (it_2 != nums2.end())
                n_2 = *(it_2++);
        }
        // Select
        if (the_big_size & 1)
            return n_2;
        else
            return (double)(n_1 + n_2)/2;
    }
};
