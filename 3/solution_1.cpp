/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<long> exist_char(256, -1);
        int result=0;
        long tail = 0;
        for(long index = 0; index < s.length(); ++index){
            long prev_char_pos = exist_char[s[index]];

            if (prev_char_pos!=-1)
                tail = max(prev_char_pos + 1, tail);
            
            if (result < (index - tail + 1)) result = index - tail + 1;
            exist_char[s[index]]=index;
        }
        return result;
    }
};