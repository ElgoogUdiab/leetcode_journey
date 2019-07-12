/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <regex>
class Solution {
public:
    bool isMatch(string s, string p) {
        regex pattern(p);
        return regex_match(s,pattern);
    }
};

