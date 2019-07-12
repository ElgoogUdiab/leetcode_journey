class Solution
{
public:
    string longestPalindrome(string s)
    {
        size_t len_str = s.length();
        if (len_str==0) return "";
        string return_str;
        int result_len=0, return_len=0;
        string s_rev(s);
        reverse(s_rev.begin(), s_rev.end());
        if (s==s_rev) return s;
        for (int center = 0; center < len_str * 2 - 1; ++center){
            int i = center & 1; string result_str;
            if (i){
                // center between chars
                if (s[center >> 1]!=s[(center >> 1) + 1]){
                    continue;
                } else {
                    result_len = 2;
                    result_str = s[center >> 1];
                    result_str += s[center >> 1];
                    i = 3;
                }
            } else {
                // center at char
                result_len = 1;
                result_str = s[center >> 1];
                i = 2;
            }
            while ((center + i)/2 < len_str && (center-i)>=0){
                if (s[(center + i)/2] != s[(center - i)/2]) {
                    break;
                } else {
                    result_str = s[(center + i)/2] + result_str + s[(center + i)/2];
                    result_len+=2;
                    i+=2;
                }
            }
            if (result_len > return_len){
                return_len = result_len; return_str = result_str;
            }
        }
        return return_str;
    }
};
