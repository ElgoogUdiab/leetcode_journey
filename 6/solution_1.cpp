/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution {
public:
    string convert(string s, int numRows) {
        string return_str("");
        int len_str = s.length();
        if (len_str < numRows || numRows == 1) return s;
        int factor = (numRows - 1)*2;
        // First line
        int n=0;
        while (n*factor < len_str){
            return_str += s[(n++)*factor];
        }
        // Except last line
        for (int i=1;i<numRows-1;++i){
            int n=0;
            while (1){
                if (factor*n+i>=len_str) break;
                return_str += s[factor*(n++) + i];
                if (factor*n-i>=len_str) break;
                return_str += s[factor*n-i];
            }
        }
        // Last line
        n=0;
        while (n*factor + numRows - 1 < len_str){
            return_str += s[(n++)*factor + numRows - 1];
        }
        return return_str;
    }
};
