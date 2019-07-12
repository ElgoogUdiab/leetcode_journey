// The key is go from the end to the beginning
class Solution {
public:
    typedef struct token{
        char c;
        bool isWildcard;
    } token_t;
    bool isMatch(string s, string p) {
        // Parsing token
        vector<token_t> tokens;
        for(int i=0;i<p.length();++i){
            token_t temp;
            temp.c = p[i];
            if (i!=p.length()-1 && p[i+1]=='*'){
                temp.isWildcard = true;
                ++i;
            } else {
                temp.isWildcard = false;
            }
            tokens.push_back(temp);
        }
        // Initializing dynamic programming matrix
        bool matrix[s.length()+1][tokens.size()+1];
        for (int i=0;i<=s.length();++i){
            for (int j=0;j<=tokens.size();++j){
                matrix[i][j]=false;
            }
        }
        // Empty string and empty pattern is a match.
        matrix[s.length()][tokens.size()]=true;
        
        for(int i=s.length();i>=0;--i){
            for(int j=tokens.size()-1;j>=0;--j){
                bool first_match = i<s.length() && (tokens[j].c==s[i] || tokens[j].c=='.'); // If first character match
                if (tokens[j].isWildcard){
                    // If (s[i:], tokens[j+1:]) match, this match
                    // Else, if (s[i],tokens[j]) match and (s[i+1:], tokens[j:]) match, this match
                    matrix[i][j]=matrix[i][j+1] || first_match && matrix[i+1][j];
                } else {
                    // If (s[i], tokens[j]) match and (s[i+1:], tokens[j+1:]) match, this match
                    matrix[i][j]=first_match && matrix[i+1][j+1];
                }
            }
        }
        return matrix[0][0];
    }
};