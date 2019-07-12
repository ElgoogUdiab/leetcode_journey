/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <string.h>
class Solution {
public:
    int myAtoi(string str) {
        char *str_cstr = str.data();
        char *start_ptr;
        start_ptr = strtok(str_cstr, " ");
        if (start_ptr == NULL) return 0;
        if (start_ptr[0] != '-' && start_ptr[0]!='+' && (start_ptr[0]<48 || start_ptr[0]>57)) return 0;
        long result;
        result = strtol(start_ptr,NULL,10);
        if (result>INT_MAX) return INT_MAX;
        if (result<INT_MIN) return INT_MIN;
        return result;
    }
};

