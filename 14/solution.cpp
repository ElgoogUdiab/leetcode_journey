class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        else if(strs.size() == 1) return strs[0];

        int min_len = strs[0].length();
        for(int i=1;i<strs.size();++i){
            if(strs[i].length() < min_len) min_len = strs[i].length();
        }     
        
        string result = "";

        for(int i=0; i < min_len; ++i){
            for(int j=0; j < strs.size() - 1; ++j){
                if(strs[j][i] != strs[j+1][i]){
                    return result;
                }
            }
            result += strs[0][i];
        }
        
        return result;
    }
};