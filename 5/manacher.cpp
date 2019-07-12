/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s=="") return "";
        int len_str = s.length();
        char s_processed[len_str*2+2];
        int P[len_str*2+1];
        // Processed string
        s_processed[len_str*2+1]=0;
        for(int i=0;i<len_str;++i){
            s_processed[i*2+1]=s[i];
            s_processed[i*2]=10;
        }
        s_processed[len_str*2]=10;
        int p, R=-1, C=0, max_index=0;
        for (p=0;p<len_str*2+1;++p){
            if (p>R){
                int i;
                for (i=1;i<=min(p, len_str*2-p);++i){
                    if (s_processed[p+i] != s_processed[p-i]) break;
                }
                P[p]=i-1;
                R = p+i-1;
                C=p;
                if (P[p] > P[max_index]) max_index = p;
            } else {
                int pl = C*2-p - P[C*2-p];
                int cl = C*2-R;
                if (pl<cl) {
                    P[p] = R-p;
                } else if (pl>cl) {
                    P[p] = P[C*2-p];
                } else {
                    int i;
                    for (i=1;i<=min(p, len_str*2-p);++i){
                        if (s_processed[p+i] != s_processed[p-i]) break;
                    }
                    P[p]=i-1;
                    R = p+i-1;
                    C=p;
                    if (P[p] > P[max_index]) max_index = p;
                }
            }
        }
        return s.substr((max_index-P[max_index]+1)/2, P[max_index]);
    }
};