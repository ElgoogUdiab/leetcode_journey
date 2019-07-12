/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        bool negative_flag = x<0;
        if (x<0){
            if (x==INT_MIN) return 0;
            x=-x;
        }
        char str[11];
        sprintf(str, "%d", x);
        string str_(str);
        std::reverse(str_.begin(), str_.end());
        long result;
        result = strtol(str_.c_str(), NULL, 10);
        if (negative_flag) result = - result;
        if (result>INT_MAX || result < INT_MIN) return 0;
        return result;
    }
};
