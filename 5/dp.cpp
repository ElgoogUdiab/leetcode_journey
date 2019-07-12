class Solution
{
public:
    string longestPalindrome(string s)
    {
        auto whetherPalindrome = [](string s){string s_rev(s); reverse(s_rev.begin(), s_rev.end()); return s==s_rev;};
        if (whetherPalindrome(s)) return s;
        size_t len_str = s.length();
        char* matrix = new char[len_str*len_str];
        // Initial condition
        for (int i=0;i<len_str;++i){
            matrix[i+i*len_str]=1;
            for (int j=i+2;j<len_str;++j) matrix[i+j*len_str]=2;
            if (i!=len_str-1){
                if(s[i]==s[i+1]){
                    matrix[(i+1)*len_str+i]=1;
                } else {
                    for (int j=0;j<=i && i+j+1<len_str;++j){
                        matrix[(i+1+j)*len_str+(i-j)] = 0;
                    }
                }
            }
        }
        // DP part
        for (int i=2;i<len_str;++i){
            for (int j=0;j<i-1;++j){
                if (matrix[i*len_str+j]!=2) continue;
                if (s[i]==s[j]){
                    matrix[i*len_str+j]=1;
                } else {
                    for (int k=0;i+k < len_str && j-k < len_str;++k){
                        matrix[(i+k)*len_str + j-k]=0;
                    }
                }
            }
        }
        // Reproduce the result
        for (int i=len_str;i>0;--i){
            for (int j=0;len_str-(i-1)-j>0 ;++j){
                if (matrix[(len_str-1-j)*len_str+(len_str-i-j)]){
                    return s.substr(len_str-i-j, i);
                }
            }
        }
        return "";
    }
};