/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> the_big_vector;
        auto it_1 = nums1.begin(), it_2 = nums2.begin();
        int i=0, the_big_size = nums1.size()+nums2.size();
        // Merge
        for (; i<=the_big_size/2;++i){
            if ( it_1 != nums1.end() && it_2 !=nums2.end() )
                the_big_vector.push_back(*(*it_1 < *it_2 ? it_1++ : it_2++));
            else if (it_1 != nums1.end())
                the_big_vector.push_back(*(it_1++));
            else if (it_2 != nums2.end())
                the_big_vector.push_back(*(it_2++));
        }
        // Select
        --i;
        if (the_big_size & 1)
            return the_big_vector[i];
        else
            return (double)(the_big_vector[i-1] + the_big_vector[i])/2;
    }
};
