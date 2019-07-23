class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) return -1;
        if (needle.length()==0) return 0;
        for (int i=0;i<haystack.length()-needle.length()+1;++i){
            if (haystack.substr(i,needle.size()) == needle.c_str()) return i;
        }
        return -1;
    }
};