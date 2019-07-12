/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        char str[11];
        sprintf(str, "%d", x);
        int digits = strlen(str);
        for (int i=0;i<digits/2;++i){
            if (str[i] != str[digits-i-1]) return false;
        }
        return true;
    }
};

